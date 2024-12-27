#pragma once

#include <iostream>
#include <cmath>

#include "Utilities.h"

#define BAR '|'


class Matrix {
private:
    int width;
    int length;
    int* nums = new int[width * length];

    friend std::ostream& operator<<(std::ostream& mos, const Matrix& mat);

    static bool isCompatibleDims(int width1, int width2, int length1, int length2);

    static void swap(int& num1, int& num2);


public:
    Matrix();
    Matrix(int length, int width, int num_init = 0);
    Matrix(const Matrix& mat);
    ~Matrix();

    Matrix& operator=(const Matrix& mat);

    int operator()(int i, int j) const; //enables reading only

    int& operator()(int i, int j); //enables writing

    Matrix& operator+=(const Matrix& mat);
    Matrix& operator-=(const Matrix& mat);
    Matrix& operator*=(const Matrix& mat);

    Matrix& operator*=(const int& a); //scalar multiplication

    Matrix operator-() const;

    Matrix rotateClockwise() const;
    Matrix rotateCounterClockwise() const;

    Matrix transpose() const;

    static double CalcFrobeniusNorm(Matrix& mat);

    friend bool operator==(const Matrix& mat1, const Matrix& mat2);
    //One matrix one scaler
    friend Matrix operator*(const int& a, const Matrix& mat); //scalar multiplication left

};

// Two matrix operators
Matrix operator+(const Matrix& mat1, const Matrix& mat2);
Matrix operator-(const Matrix& mat1, const Matrix& mat2);
Matrix operator*(const Matrix& mat1, const Matrix& mat2);

//One matrix one scaler
Matrix operator*(const int& a, const Matrix& mat); //scalar multiplication left
Matrix operator*(const Matrix& mat, const int& a); //scalar multiplication right

bool operator!=(const Matrix& mat1, const Matrix& mat2);
