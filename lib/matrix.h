#pragma once
#include <iostream>
#include <vector>

namespace math
{
#ifdef MATH_DOUBLE_PREC_DEFINE
typedef double real;
#else
typedef float real;
#endif

class Matrix
{
protected:
    int cols_;
    int rows_;
    std::vector<real> mvec_;

public:
    Matrix() {};

    Matrix(int rows, int cols)
        : cols_(cols)
        , rows_(rows)
        , mvec_(std::vector<real>(rows * cols)) {};

    void getVec(std::vector<real> &mvec) const;
    int rows() const;
    int cols() const;

    real &operator()(int row, int col);

    real operator()(int row, int col) const;

    void print() const;

    friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);

    friend Matrix operator+(const Matrix &A, const Matrix &B);

    friend Matrix operator-(const Matrix &A, const Matrix &B);

    friend Matrix operator*(const Matrix &A, const Matrix &B);
};
} // namespace math
