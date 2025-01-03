#include <iostream>
#include <webp/encode.h>
#include <cstring>
using namespace std;

class Bitmap {
private:
    uint32_t* pixels;
    int width;
    int height;
public:
    Bitmap(int w, int h) : width(w), height(h) {
        pixels = new uint32_t[width*height]; // allocate 4*width*height bytes  each pixel has R,G,B, A
        for (int i = 0; i < width*height; i++) {
            pixels[i] = 0xFF000000;
        }
    }
    
    ~Bitmap() {
        delete [] pixels;
    }
    // we will talk about the copy constructor and operator = later, for now we make sure they don't exist
    Bitmap(const Bitmap& other) = delete;
    void operator=(const Bitmap& other) = delete;
/*
    0 0 0 0 0 0 0 ...
    0 0 0 0 0 0 0 

*/

    void set(uint32_t x, uint32_t y, uint32_t color) {
        pixels[y*width + x] = color; // manually index the correct pixel
    }

    //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
    void line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color) {
        
    }

    // TODO: draw a rectangle outline
    void rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
        
    }   

    void circle(uint32_t x, uint32_t y, uint32_t r, uint32_t color) {
    }

    void horline(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
        for (uint32_t x = x1; x <= x2; x++) {
            set(x, y, color);
        }
    }

    void horline_fast(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
        uint32_t start = y*width + x1;
        uint32_t end = y*width + x2;
        for (uint32_t x = start; x <= end; x++) {
            pixels[x] = color;
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
#if 0
        WebPConfig config;
        if (!WebPConfigPreset(&config, WEBP_PRESET_PHOTO, 75.0f)) {
            cerr << "WebPConfigPreset failed" << endl;
            return;   // version error
        }
        // Add additional tuning:
        config.sns_strength = 90;
        config.filter_sharpness = 6;
        config.alpha_quality = 90;
        if (!WebPValidateConfig(&config)) {
            cerr << "WebPValidateConfig failed" << endl;
            return;  // parameter error
        }

        WebPPicture pic;
        if (!WebPPictureInit(&pic)) {
            cerr << "WebPPictureInit failed" << endl;
            return;  // version error
        }
        pic.width = width;
        pic.height = height;
        pic.use_argb = 1; // Use ARGB input

        if (!WebPPictureAlloc(&pic)) {
            cerr << "WebPPictureAlloc failed" << endl;
            return;   // memory error
        }

        // Import the pixel data
        if (!WebPPictureImportRGBA(&pic, (uint8_t*)pixels, width * 4)) {
            cerr << "WebPPictureImportRGBA failed" << endl;
            WebPPictureFree(&pic);
            return;  // import error
        }

        // Open the file for writing
        FILE* outFile = fopen(filename, "wb");
        if (!outFile) {
            cerr << "Failed to open file for writing" << endl;
            WebPPictureFree(&pic);
            return;  // file error
        }

        // Set up the writer
        pic.writer = WebPMemoryWrite;
        pic.custom_ptr = outFile;

        // Encode the picture
        if (!WebPEncode(&config, &pic)) {
            cerr << "WebPEncode failed" << endl;
            fclose(outFile);
            WebPPictureFree(&pic);
            return;  // encoding error
        }

        // Clean up
        fclose(outFile);
        WebPPictureFree(&pic);
#endif
    }
};



int main() {
    Bitmap b(500, 500);
    b.line(0, 0, 100, 100, 0x00FF00FF);
    b.rect(0, 0, 100, 100, 0x0000FFFF);
    b.circle(50, 50, 40, 0xFF0000FF);
    b.horline(0, 200,100, 0xFFFFFFFF);
    b.horline_fast(0, 200,150, 0xFFFFFFFF);
    b.save("test.webp");
    return 0;
}