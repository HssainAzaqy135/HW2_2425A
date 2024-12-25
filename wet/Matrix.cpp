//
// Created by kingh on 25/12/2024.
//

#include "Matrix.h"

// Constructors and destructor, yipeeeeeee
Matrix::Matrix(int rows, int cols): rows(rows), cols(cols),data(new int[rows * cols]()) {
	// zero initializer
}
Matrix::Matrix(int rows, int cols, int init_val) :rows(rows), cols(cols),data(new int[rows * cols]) {
	// init val initializer
	for (int i = 0; i < rows*cols; i++) {
		this->data[i] = init_val;
	}
}
Matrix::Matrix() : rows(0), cols(0),data(nullptr){
	// parameter less constructor
}
Matrix::~Matrix() {
	delete[] data;
}

//---------------------------------