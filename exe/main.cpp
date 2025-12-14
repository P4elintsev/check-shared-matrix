#include <iostream>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern __declspec(dllimport) Matrix* math_createMatrix(int, int);
    extern void __declspec(dllimport) math_deleteMatrix(Matrix *);
    extern void __declspec(dllimport) math_set(Matrix *, int, int, double);
    extern void __declspec(dllimport) math_print(Matrix *);
    extern __declspec(dllimport) Matrix* math_add(Matrix *A, Matrix *B);
#ifdef __cplusplus
}
#endif

int main()
{

    Matrix *m = math_createMatrix(3, 3);
    Matrix *m1 = math_createMatrix(3, 3);

    math_set(m, 0, 0, 1.);
    math_set(m, 1, 1, 1.);
    math_set(m, 2, 2, 1.);
    math_set(m1, 2, 2, 1.);
    math_print(m);
    
    math_print(math_add(m1, m));



//     // ? ????? ??????????? ???????? ??????????
    math_deleteMatrix(m);

    return 0;
}