#pragma once

#include <string>

#include "Matrix.h"
#include "Utilities.h"

using std::string;

class MataMvidia {
private:
    string movieName;
    string creatorName;
    int frameCount;
    Matrix* frames;

public:
    //Constructors and destructors
    MataMvidia(string movieName, string creatorName, Matrix* framesArray, int frameCount);
    ~MataMvidia();
    MataMvidia(const MataMvidia& movie);

    //operators
    MataMvidia& operator=(const MataMvidia& movie);


};