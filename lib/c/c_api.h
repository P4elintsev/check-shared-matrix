#pragma once
#include <export.h>

#ifdef MATH_DOUBLE_PREC_DEFINE
    typedef double real;
#else
    typedef float real;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Matrix Matrix;

    MATRIXLIB_EXPORT Matrix *math_createMatrix(int rows, int cols);

    // Matrix* MATRIXLIB_EXPORT math_createMatrix(int rows, int cols);// ?????? ??? ???, ?? ????????

    void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *M);

    real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col);

    void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val);

    void MATRIXLIB_EXPORT math_print(const Matrix *M);

    MATRIXLIB_EXPORT Matrix *math_add(const Matrix *A, const Matrix *B);

    MATRIXLIB_EXPORT Matrix *math_subtract(const Matrix *A, const Matrix *B);

    MATRIXLIB_EXPORT Matrix *math_dot(const Matrix *A, const Matrix *B);

#ifdef __cplusplus
}
#endif
