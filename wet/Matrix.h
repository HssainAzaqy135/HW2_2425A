//
// Created by kingh on 25/12/2024.
//
#pragma once
#include "Utilities.h"
class Matrix {
private:
	int rows;
	int cols;
	int* data;

public:
	// Construction and destruction (Bob the builder stuff)
	Matrix(int rows, int cols); // zero initializer
	Matrix(int rows, int cols, int init_val);// init val initializer
	Matrix();// parameter less constructor
	~Matrix();

	// Copy constructor and assignment Operator
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	int &operator()(int i, int j);
	int operator()(int i, int j) const;
};
