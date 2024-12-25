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
//-----------------------------------------------------------------------------
// Copy constructor and assignment operator
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {
	if (other.rows * other.cols > 0) {
		data = new int[rows * cols];
		//actual copying
		for (int i = 0; i < rows * cols; i++) {
			this->data[i] = other.data[i];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this == &other) {// is Mua???
		return *this;
	}
	// Compatibility check
	if(this->rows != other.rows || this->cols != other.cols) {
		exitWithError(MatamErrorType::UnmatchedSizes);
	}

	int* tmp = new int[other.rows * other.cols];
	for (int i = 0; i < other.rows * other.cols; i++) {
		tmp[i] = other.data[i];
	}
	// from here it is safe
	delete[] data;
	this->data = tmp;
	// Kind of redundant but to be safe
	this->rows = other.rows;
	this->cols = other.cols;

	return *this;
}

//-----------------------------------------------------------------------------
// Operators
int &Matrix::operator()(int i, int j) {
	if ((i >= rows || j >= cols)) {
		exitWithError(MatamErrorType::OutOfBounds);
	}
	return this->data[i * this->cols + j];
}
int Matrix::operator()(int i, int j) const {
	if ((i >= rows || j >= cols)) {
		exitWithError(MatamErrorType::OutOfBounds);
	}
	return this->data[i * this->cols + j];
}

