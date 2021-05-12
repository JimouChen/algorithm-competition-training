# include<iostream>
using namespace std;

class Matrix {
private:
    int *m;
    int row, col;
public:
    Matrix(int r, int c);
    friend Matrix &operator+(Matrix &a, Matrix &b);
    friend Matrix &operator-(Matrix &a, Matrix &b);
    friend Matrix &operator*(Matrix &a, Matrix &b);
    Matrix &operator=(Matrix &a);
    Matrix &operator+=(Matrix &a);
    void input();
    void output();
};

Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    m = new int[row * col];
    for (int i = 0; i < row * col; ++i)
        m[i] = 0;

}

void Matrix::input() {
    cout << "please input matrix:" << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> m[i * col + j];

}

void Matrix::output() {
    cout << "output matrix" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << m[i * col + j] << " ";
        }
        cout << endl;
    }
}

Matrix &operator+(Matrix &a, Matrix &b) {
    int r = a.row, c = a.col;
    Matrix res(r, c);
    for (int i = 0; i < r * c; i++)
        res.m[i] = a.m[i] + b.m[i];
    return res;
}

Matrix &operator-(Matrix &a, Matrix &b) {
    int r = a.row, c = a.col;
    Matrix res(r, c);
    for (int i = 0; i < r * c; ++i)
        res.m[i] = a.m[i] - b.m[i];
    return res;
}

Matrix &operator*(Matrix &a, Matrix &b) {
    Matrix res(a.row, b.col);
    for (int i = 0; i < a.row; ++i) {
        for (int j = 0; j < b.col; ++j) {
            for (int k = 0; k < a.col; ++k) {
                res.m[b.col * i + j] += a.m[a.col * i + k] * b.m[b.col * k + j];
            }
        }
    }

    return res;
}

Matrix &Matrix::operator=(Matrix &a) {
    for (int i = 0; i < row * col; ++i)
        m[i] = a.m[i];
    return *this;
}

Matrix &Matrix::operator+=(Matrix &a) {
    for (int i = 0; i < row * col; ++i)
        m[i] += a.m[i];
    return *this;
}

int main() {
    Matrix matrix1(2, 3), matrix2(2, 3);
    matrix1.input();
    matrix2.input();

    Matrix matrix1add2 = matrix1 + matrix2;
    cout << "after +:" << endl;
    matrix1add2.output();

    Matrix matrix1sub2 = matrix1 - matrix2;
    cout << "after -:" << endl;
    matrix1sub2.output();

    Matrix matrix3(3, 2);
    matrix3.input();
    Matrix matrix1mul3 = matrix1 * matrix3;
    cout << "after *:" << endl;
    matrix1mul3.output();

    matrix2 = matrix1;
    cout << "after =:" << endl;
    matrix2.output();

    matrix1 += matrix2;
    cout << "after +=:" << endl;
    matrix1.output();

    return 0;
}
/**

1 2 3
4 5 6
1 2
3 4
5 6
 */
