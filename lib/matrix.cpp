#include <cmath>
#include <iostream>
#include <matrix.h>

using namespace math;

void math::Matrix::getVec(std::vector<real> &mvec) const
{
    mvec = this->mvec_;
}

int math::Matrix::rows() const
{
    return this->rows_;
}

int math::Matrix::cols() const
{
    return this->cols_;
}

real &Matrix::operator()(int row, int col)
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: row" << std::endl;
        // return 0;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Matrix: col" << std::endl;
        // return 0;
    }

    int pos{0};

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: row" << std::endl;
        // return 0;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Matrix: col" << std::endl;
        // return 0;
    }

    int pos{0};

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

namespace math
{
    std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.rows_; ++i)
        {
            for (int j = 0; j < matrix.cols_; ++j)
            {
                out << matrix.mvec_.at(matrix.cols_ * i + j) << " ";
            }
            out << std::endl;
        }

        return out;
    }

    Matrix operator+(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Matrix: Matrices can't be added!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator-(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Matrix: Matrices can't be subtracted!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator*(const Matrix &A, const Matrix &B)
    {
        if (A.cols_ != B.rows_)
        {
            std::cerr << "Matrix: Matrices can't be multiplied!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.rows_, B.cols_);

        for (int pos = 0; pos < M.mvec_.size(); ++pos)
        {
            int row = (int)std::floor(pos / M.cols_);
            int col = pos - row * M.cols_;

            for (int k = 0; k < A.cols_; ++k)
            {
                M.mvec_.at(pos) += A(row, k) * B(k, col);
            }
        }

        return M;
    }

    void Matrix::print() const{
            for (int i = 0; i < this ->rows_; ++i)
            {
                for (int j = 0; j < this ->cols_; ++j)
                {
                    std::cout<<this ->mvec_.at(cols_ * i + j)<<" ";
                }
                std::cout<<std::endl;
            }
    }
    } // namespace math
