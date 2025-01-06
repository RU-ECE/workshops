class vec3d {
private:
    double x,y,z;
public:
    vec3d(double x, double y, double z);
    friend vec3d operator +(vec3d a, vec3d b);
    friend vec3d operator -(vec3d a, vec3d b);
    friend vec3d operator -(vec3d a);
    friend double dot(vec3d a, vec3d b); // a.x*b.x+a.y*b.y+a.z*b.z
    friend vec3d cross(vec3d a, vec3d b);
    void sum(const vec3d a[], int n);
    friend std::ostream& operator <<(std::ostream& s, vec3d v);
};

vec3d cross(vec3d a, vec3d b) {
    return vec3d(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

void vec3d::sum(const vec3d a[], int n) {
    vec3d result(0,0,0);
    for (int i = 0; i < n; i++) {
        result = result + a[i];
    }
//    x = result.x;
//    y = result.y;
//    z = result.z;
    *this = result;
}


int main() {
  vec3d a(1,2,3);
  vec3d b(1.5, 1.2, -1.5);
  vec3d c = a + b;
  vec3d d = a - b;
  vec3d e = -a;
  double f = dot(a,b);
  cout << a << '\n';
  cout << b << '\n';
  cout << c << '\n';
  cout << d << '\n';
  cout << e << '\n';
  cout << f << '\n';
  const vec3d arr[] = {a,b,c, d, e, {1.2, 3.4, 5.1}, {-1.2, -5.4, -7.2}};
  e.sum(arr, sizeof(arr)/sizeof(arr[0])); // sum the 7 vectors
  cout << e << '\n';
}