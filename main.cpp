#include "SqrMatrix.h"
#include <iostream>
int main()
{
    SqrMatrix A(3);
    A.FillMatrix();
    A.OutputMatrix();
    int i, j,error;
    std::cout << "enter i and j";
    std::cin >> i;
    std::cin >> j;
    A.Set(2, i, j);
    std::cout <<"Invalid set :"<< A.Set(2, 8, 8) << std::endl;
    A.OutputMatrix();
    std::cout <<"Get 2 2 =" <<A.Get(2, 2, error)<< std::endl;
    std::cout << A.Get(8, 8, error) << std::endl;
    std::cout <<"Invalid Get error = " << error << std::endl;
    SqrMatrix B(3);
    B = A;
    B.OutputMatrix();
    SqrMatrix C(3);
    C = A + B;
    std::cout << "A+B" << std::endl;
    C.OutputMatrix();
    C = A - B;
    std::cout << "A-B" << std::endl;
    C.OutputMatrix();
    std::cout << "A*B" << std::endl;
    C = A * B;
    C.OutputMatrix();
    C *= 2.0;
    std::cout << "C*2" << std::endl;
    C.OutputMatrix();
    C = A / B;
    std::cout << "A/B" << std::endl;
    C.OutputMatrix();
	return 0;
}