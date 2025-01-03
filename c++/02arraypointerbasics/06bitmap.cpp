#include <iostream>
#include <webp/encode.h>
#include <cstring>
#include <webp/decode.h> 
using namespace std;

const uint32_t BLACK = 0xFF000000, WHITE = 0xFFFFFFFF,
RED= 0xFF0000FF, GREEN= 0xFF00FF00, BLUE=0xFFFF0000, YELLOW=0xFF00FFFF;

class Bitmap {
private:
    uint32_t* pixels;
    int width;
    int height;
public:
    Bitmap(int w, int h, uint32_t color) : width(w), height(h) {
        pixels = new uint32_t[width*height]; // allocate 4*width*height bytes  each pixel has R,G,B, A
        for (int i = 0; i < width*height; i++) {
            pixels[i] = color; // Intel is little-endian RRGGBBAA
        }
    }

    Bitmap(const char filename[]) {
        FILE* file = fopen(filename, "rb");

        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);

        uint8_t* fileData = new uint8_t[fileSize];
        fread(fileData, fileSize, 1, file);
        fclose(file);
        
        pixels = (uint32_t*)WebPDecodeRGBA(fileData, fileSize, &width, &height);
        delete [] fileData;
    }
    
    ~Bitmap() {
        delete [] pixels;
    }
    // we will talk about the copy constructor and operator = later, for now we make sure they don't exist
    Bitmap(const Bitmap& other) = delete;
    void operator=(const Bitmap& other) = delete;

    void set(uint32_t x, uint32_t y, uint32_t color) {
        pixels[y*width + x] = color; // manually index the correct pixel
    }

    //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
    void line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color) {
           
    }

    // TODO: draw a rectangle outline
    void rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
//        horline(x, x+w-1, y, color);
//        horline(x, x+w-1, y+h-1, color);

       for (uint32_t i = x; i < x + w; i++){
        pixels[y*width+i] = color;
       }
    
        for(uint32_t i=x; i<x+w; i++){
            pixels[(y+h-1)*width+i] = color;
        }
        vertline(x,y,y+h-1,color);
        vertline(x+w-1,y,y+h-1,color);
    }   

    void fillrect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
        
    }   

    void circle(uint32_t x, uint32_t y, uint32_t r, uint32_t color) {
    }

    void horline(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
        uint32_t start = y*width + x1;
        uint32_t end = y*width + x2;
        for (uint32_t x = start; x <= end; x++) {
            pixels[x] = color;
        }
    }

/*
   0  1  2  3   4  5  6
   7  8  9  10  11 12 13
   14 15 16 17  18 19 20
*/
    void vertline(uint32_t x, uint32_t y1, uint32_t y2, uint32_t color) {
        uint32_t start = y1*width + x;
        uint32_t end = y2*width + x;
        for (uint32_t i = start; i <= end; i += width) {
            pixels[i] = color;
        }
    }
    void save(const char* filename) const {
        uint8_t* output;
        size_t size = WebPEncodeRGBA((uint8_t*)pixels, width, height, width * 4, 100, &output);
        if (size == 0) {
            cerr << "WebPEncode failed" << endl;
            return;
        }

        FILE* outFile = fopen(filename, "wb");
        if (!outFile) {
            cerr << "Failed to open file for writing" << endl;
            WebPFree(output);
            return;
        }

        fwrite(output, size, 1, outFile);
        fclose(outFile);
        WebPFree(output);
    }

    friend ostream& operator<<(ostream& s, const Bitmap& b) {
        return s << "w = " << b.width << "\th = " << b.height << std::endl;
    }
};



int main() {
    Bitmap b(500, 500, BLACK);
    b.line(0, 0, 100, 100, BLUE);
    b.rect(0, 0, 100, 100, RED);
    b.rect(200, 300, 100, 100, GREEN);
    b.circle(50, 50, 40, YELLOW);
    b.horline(0, 200,100, WHITE);
    b.vertline(300, 100, 200, RED);
    b.save("test.webp");

    Bitmap b2("test.webp");
    cout << b2 << '\n'; // print the bitmap
    b2.rect(300,100,50,50,YELLOW);
    b2.save("test2.webp");
    return 0;
}