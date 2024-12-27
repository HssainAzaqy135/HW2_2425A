////
//// Created by kingh on 25/12/2024.
////
//
//#include <iostream>
//#include <ostream>
//
//#include "Matrix.h"
//#include "MataMvidia.h"
//
//int main() {
//	int n = 2;
//	int m = 2;
//	Matrix m1;
//	Matrix m2(m,n);
//	Matrix m3(m,n,4);
//	m2 =m3;
//	m2(0,0) = 2;
//    const Matrix m4(2,2,5);
//
//	// Print all matrices
//	std::cout << "Matrix " << "1" << std::endl;
//	std::cout << m1 << std::endl;
//	std::cout << "Matrix " << "2" << std::endl;
//	std::cout << m2 << std::endl;
//	std::cout << "Matrix " << "3" << std::endl;
//	std::cout << m3 << std::endl;
//	std::cout << "Matrix " << "4" << std::endl;
//	std::cout << m4 << std::endl;
//	std::cout<< "---------------------------" << std::endl;
//
//	const Matrix matArray1[] = {m1,m2,m3,m4};
//	const Matrix matArray2[] = {m4,m3,m2,m1};
//	MataMvidia movie1("What are those?","Obama",matArray1,4);
//	MataMvidia movie2("What are those 2?","Obama 2",matArray2,4);
//	MataMvidia movie3(movie2);
//	movie1 = movie1;
//	// print all movies
//	std::cout << "---------- All movies -----------" << std::endl;
//	std::cout << "Movie " << "1" << std::endl;
//	std::cout << movie1 << std::endl;
//	std::cout << "Movie " << "2" << std::endl;
//	std::cout << movie2 << std::endl;
//	std::cout << "Movie " << "3" << std::endl;
//	std::cout << movie3 << std::endl;
//
//	// Manipulations
//	std::cout << "---------- Manipulations -----------" << std::endl;
//	std::cout << movie1[3] << std::endl;
//	movie1 += movie2;
//	std::cout << movie1 << std::endl;
//	std::cout << movie2 + movie3 << std::endl;
//
//	return 0;
//}
