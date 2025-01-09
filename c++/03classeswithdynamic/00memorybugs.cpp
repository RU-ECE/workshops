#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    uint32_t len; // ORDER IS CRITICAL! Put this after data and IT CRASHES!!!
    char*  data;
public:
    String() : data(nullptr), len(0) {
        cout << "Empty String\n";
    }
    String(const char* str) : len(strlen(str)), data(new char[len]) {
        for (int i = 0; i < len; i++)
            data[i] = str[i];
        //memcpy(data, str, len);
        cout << "Allocated String\n";
    }
    String(const String& orig) : len(orig.len), data(new char[len]) {
        for (int i = 0; i < len; i++)
            data[i] = orig.data[i];
        cout << "Copied String\n";
    }
    void change() {
        data[0] = 'x';
    }
    ~String() {
        delete[] data;
        cout << "Just gave back the memory for String\n";
    }
    friend ostream& operator<<(ostream& os, const String& str) {
        for (int i = 0; i < str.len; i++)
            os << str.data[i];
        return os;
    }
};



int main() {
    int a = 3; // auto, on the stack, we don't know where it is
//CRASH:    delete &a;

    int* b = new int[1024];
    String s = "hello";
    {
        String s2;
    }
    //s.append("test"); // "hellotest"
    cout << s << '\n';
    delete[] b;
//CRASH:    delete [] b;
    String s3(s); // call copy constructor
    s3.change();
    String s4 = s; // call copy constructor
    return 0;
}