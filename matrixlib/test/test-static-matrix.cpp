#include <iostream>
#include <matrixlib/matrix.h>

int main()
{
    // std::cout << "Hello world" << std::endl;
    math::Matrix m(3, 3);
    m(0,0) = 1.;
    m(1,1) = 1.;

    math::Matrix m1(3, 3);
    m1(0,0)=3.;
    m1(1,1)=3.;

    std::cout << "Matrix m is" << std::endl;
    m.print();

    std::cout << "Matrix m1 is"<< std::endl;
    m1.print();

    math::Matrix m2 = m + m1;
    std::cout << "Matrix m2 is"<< std::endl;
    m2.print();

    math::Matrix m3 = m - m1;
    std::cout << "Matrix m3 is"  << std::endl;
    m3.print();

    math::Matrix m4 = m * m1;
    std::cout << "Matrix m4 is" << std::endl;
    m4.print();

    return 0;
}