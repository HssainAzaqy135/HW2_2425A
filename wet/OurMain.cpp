//
// Created by kingh on 25/12/2024.
//

#include <iostream>
#include <ostream>

#include "Matrix.h"
#include "MataMvidia.h"

int main() {
	Matrix m1(2,2,0);
//    m1(0,0) = 1;
//    m1(0,1) = 0;
//    m1(0,2) = 2;
//    m1(1,0) = 3;
//    m1(1,1) = 1;
//    m1(1,2) = 0;
    std::cout << m1 << std::endl;

    Matrix m2(m1);

    Matrix m3;

    m3 = m2;

    std::cout << m3.rotateClockwise() << std::endl;

    std::cout << m3.rotateCounterClockwise() << std::endl;

    std::cout << m3.transpose() << std::endl;

	return 0;
}