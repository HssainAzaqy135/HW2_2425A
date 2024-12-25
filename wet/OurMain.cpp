//
// Created by kingh on 25/12/2024.
//

#include <iostream>
#include <ostream>

#include "Matrix.h"
#include "MataMvidia.h"

int main() {
	int n = 2;
	int m = 2;
	Matrix m1;
	Matrix m2(m,n);
	Matrix m3(m,n,4);
	std::cout << m2(0,0) << std::endl;
	m2 =m3;
	std::cout << m2(0,0) << std::endl;
	m2(0,0) = 2;
	std::cout << m2(0,0) << std::endl;
	return 0;
}
