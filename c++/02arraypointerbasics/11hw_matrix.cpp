class matrix {
private:
  double* m;
  uint32_t rows, cols;
public:
  matrix(uint32_t rows, uint32_t cols);  
  ~matrix();  
  matrix(const matrix& orig);
  matrix& operator =(const matrix& orig);
  friend matrix operator +(const matrix& m1, const matrix& m2);
};