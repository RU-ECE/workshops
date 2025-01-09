class matrix {
private:
    double* m;
    uint32_t rows, cols;
public:
    double operator ()(uint32_t row, uint32_t col) const {
        return m[row * cols + col];
    }
    double& operator ()(uint32_t row, uint32_t col) {
        return m[row * cols + col];
    }

    friend matrix operator +(const matrix& m1, const matrix& m2) {
        //TODO: add if statement to check if the two matrices are the same size
       matrix ans(m1.rows, m1.cols, 0.0);
        //TODO: do the math in here

       return ans;
    }

};

int main() {
    matrix m1(3, 4, 0.0); // create 3 rows of 4 columns each set each value to 0.0
    m1(1,1) = 1.5;
    cout << m1(1,1) << '\n'; // this calls the readonly operator ()
/*
    0   0   0   0
    0   1   0   0
    0   0   0   0
*/
    matrix m2(3, 4, 1.0);
/*
    1   1   1   1
    1   1   1   1
    1   1   1   1
*/

    matrix m3 = m1 + m2; // add each corresponding element and put into m3
/*
    1   1   1   1
    1   2   1   1
    1   1   1   1
*/
    cout << m3 << '\n';
    m3 = m1; // operator = test
    cout << m3 << '\n';
}