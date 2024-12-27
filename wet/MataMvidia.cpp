#include "MataMvidia.h"

// Constructors & destructors
MataMvidia::MataMvidia(string movieName, string creatorName, Matrix* framesArray, int frameCount) :
movieName(movieName), creatorName(creatorName), frameCount(frameCount), frames(new Matrix[frameCount]) {
    for (int i = 0; i < this->frameCount; ++i) {
        this->frames[i] = framesArray[i];
    }
}
MataMvidia::~MataMvidia(){
    delete[] frames;
}

MataMvidia::MataMvidia(const MataMvidia& movie) :
movieName(movie.movieName), creatorName(movie.creatorName), frameCount(movie.frameCount), frames(new Matrix[movie.frameCount]) {
    for (int i = 0; i < this->frameCount; ++i) {
        this->frames[i] = movie.frames[i];
    }
}
//-----------------------------------------------------------------------------
//Operators
MataMvidia& MataMvidia::operator=(const MataMvidia& movie) {
    if (this == &movie) {
        return *this;
    }

    Matrix* temp = new Matrix[frameCount];
    movieName = movie.movieName;
    creatorName = movie.creatorName;
    frameCount = movie.frameCount;
    delete[] frames;

    for (int i = 0; i < frameCount; ++i) {
        temp[i] = movie.frames[i];
    }

    frames = temp;
    return *this;
}
//-----------------------------------------------------------------------------
