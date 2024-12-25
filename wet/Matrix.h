//
// Created by kingh on 25/12/2024.
//
#pragma once
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
};
