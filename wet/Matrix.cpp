#include "Matrix.h"

using std::cout;
using std::endl;

// Constructors & destructors
Matrix::Matrix() : width(0), length(0), nums(nullptr) {};

Matrix::Matrix(int length, int width, int num_init) : width(width), length(length), nums(new int[width * length]) {
    if(length == 0 || width == 0){
        this->length = 0;
        this->width = 0;
    }
    for (int i = 0; i < width * length; ++i) {
        nums[i] = num_init;
    }
};

Matrix::Matrix(const Matrix& mat) : width(mat.width), length(mat.length), nums(new int[mat.width * mat.length]) {
    for (int i = 0; i < width * length; ++i) {
        nums[i] = mat.nums[i];
    }
};

Matrix::~Matrix() {
    delete[] nums;
};
//-----------------------------------------------------------------------------

// helper functions
bool Matrix::isCompatibleDims(int width1, int width2, int length1, int length2) {
    if (width1 != width2 || length1 != length2) {
        return true;
    }
    return false;
}

void Matrix::swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
//-----------------------------------------------------------------------------
//Operators

std::ostream& operator<<(std::ostream& mos, const Matrix& mat) {
    for (int i = 0; i < mat.length; ++i) {
        for (int j = 0; j < mat.width; ++j) {
            mos << BAR << mat(i, j);
        }
        mos << BAR << endl;
    }
    return mos;
}

Matrix& Matrix::operator=(const Matrix& mat) {
    if (this == &mat) {
        return *this;
    }

    width = mat.width;
    length = mat.length;
    int *temp = new int[width * length];
    delete[] nums;
    for (int i = 0; i < width * length; ++i) {
        temp[i] = mat.nums[i];
    }
    this->nums = temp;

    return *this;
};

int Matrix::operator()(int i, int j) const {
    if (i >= length || j >= width || i < 0 || j < 0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return nums[i*width + j];
}

int& Matrix::operator()(int i, int j) {
    if (i >= length || j >= width || i < 0 || j < 0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return nums[i*width + j];
}

bool operator==(const Matrix& mat1, const Matrix& mat2) {
    if (Matrix::isCompatibleDims(mat1.width, mat2.width, mat1.length, mat2.length)) {
        return false;
    }

    for (int i = 0; i < mat1.width * mat1.length; ++i) {
        if (mat1.nums[i] != mat2.nums[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const Matrix& mat1, const Matrix& mat2) {
    return !(mat1 == mat2);
}

Matrix& Matrix::operator+=(const Matrix& mat) {
    if (Matrix::isCompatibleDims(width, mat.width, length, mat.length)) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    for (int i = 0; i < width * length; ++i) {
        nums[i] += mat.nums[i];
    }

    return *this;
}
// Arithmetic operators
Matrix& Matrix::operator*=(const Matrix& mat) {
    Matrix ret(this->length, mat.width);
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < mat.width; ++j) {
            int sum = 0;
            for (int k = 0; k < this->width; ++k) {
                sum += (*this)(i,k) * mat(k, j);
            }
            ret(i,j) = sum;
        }
    }
    *this = ret;
    return *this;
}

Matrix& Matrix::operator*=(const int& a) {
    for (int i = 0; i < width * length; ++i) {
        nums[i] *= a;
    }
    return *this;
}

Matrix Matrix::operator-() const{
    Matrix ret = *this;
    ret *= -1;
    return ret;
}

Matrix& Matrix::operator-=(const Matrix& mat) {
    *this += -mat;
    return *this;
}

Matrix operator*(const int& a, const Matrix& mat){//scalar multiplication left
    Matrix ret = mat;
    for (int i = 0; i < mat.width * mat.length; ++i) {
        ret.nums[i] *= a;
    }
    return ret;
}

Matrix operator*(const Matrix& mat, const int& a) { //scalar multiplication right
    return a*mat;
}

Matrix operator+(const Matrix& mat1, const Matrix& mat2){
    Matrix ret = mat1;
    return ret += mat2;
}
Matrix operator-(const Matrix& mat1, const Matrix& mat2){
    Matrix ret = mat1;
    return ret -= mat2;
}
Matrix operator*(const Matrix& mat1, const Matrix& mat2){
    Matrix ret = mat1;
    return ret *= mat2;
}

//-----------------------------------------------------------------------------
// Special functions
Matrix Matrix::transpose() const {
    Matrix ret(width, length);
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            ret(j,i) = (*this)(i,j);
        }
    }

    return ret;
}

Matrix Matrix::rotateClockwise() const {
    Matrix ret(*this);
    ret = ret.transpose();
    for (int j = 0; j < ret.width / 2; ++j) {
        for (int i = 0; i < ret.length; ++i) {
            swap(ret(i,j), ret(i, ret.width - j - 1));
        }
    }
    return ret;
}

Matrix Matrix::rotateCounterClockwise() const {
    return this->rotateClockwise().rotateClockwise().rotateClockwise();
}

double Matrix::CalcFrobeniusNorm(const Matrix& mat) {
    int sum = 0;
    for (int i = 0; i < mat.width * mat.length; ++i) {
        sum += mat.nums[i] * mat.nums[i];
    }
    return sqrt(sum);
}

//-----------------------------------------------------------------------------

