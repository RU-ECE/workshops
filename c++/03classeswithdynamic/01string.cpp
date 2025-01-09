#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char*  data;
    uint32_t len;
public:
    String() : data(nullptr), len(0) {
    }
    String(const char* str) {
        len = strlen(str);
        data = new char[len];
        memcpy(data, str, len);
    }
    String(const String& orig) : data(new char[orig.len]), len(orig.len) {
        memcpy(data, orig.data, len);
    }

    String& operator =(const String& orig) {
        if (this != &orig) {
            delete[] data;
            data = new char[orig.len];
            len = orig.len;
            memcpy(data, orig.data, len);
        }
        return *this;
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

void f(String s) {


}

String h() {
    String s = "hello";
    return s;
}

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
    s4 = s4; // calls operator = and crashes
    s4 = s3 = s;
    return 0;
}