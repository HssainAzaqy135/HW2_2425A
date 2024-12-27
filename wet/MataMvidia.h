#pragma once

#include <string>

#include "Matrix.h"
#include "Utilities.h"

using std::string;
using std::endl;



class MataMvidia {
private:
    string movieName;
    string creatorName;
    int frameCount;
    Matrix* frames;


    friend std::ostream& operator<<(std::ostream& mos, const MataMvidia& movie);

public:
    //Constructors and destructors
    MataMvidia(const string& movieName, const string& creatorName, const Matrix* framesArray, int frameCount);
    ~MataMvidia();
    MataMvidia(const MataMvidia& movie);

    //operators
    MataMvidia& operator=(const MataMvidia& movie);
    Matrix operator[](int i) const; //enables reading only
    Matrix& operator[](int i); //enables writing
    MataMvidia& operator+=(const MataMvidia& otherMovie);
    MataMvidia& operator+=(const Matrix& mat);

};

MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2);