#include "MataMvidia.h"

// Constructors & destructors
MataMvidia::MataMvidia(const string& movieName, const string& creatorName, const Matrix* framesArray, int frameCount) :
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
Matrix& MataMvidia::operator[](int i) {
    if (i < 0 || i >= frameCount) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return frames[i];
}
Matrix MataMvidia::operator[](int i) const {
    if (i < 0 || i >= frameCount) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return frames[i];
}
//Arithmetic operators
MataMvidia& MataMvidia::operator+=(const MataMvidia& otherMovie) {
    Matrix* temp = new Matrix[frameCount + otherMovie.frameCount];
    for (int i = 0; i < frameCount; ++i) {
        temp[i] = frames[i];
    }
    for (int i = 0; i < otherMovie.frameCount; ++i) {
        temp[i + frameCount] = otherMovie.frames[i];
    }
    frameCount = otherMovie.frameCount + frameCount;
    delete[] frames;
    frames = temp;
    return *this;
}
MataMvidia& MataMvidia::operator+=(const Matrix& mat) {
    const Matrix array[] = {mat};
    MataMvidia oneFrameMovie("Skibidi","Sigma",array,1); // Place holder names
    (*this)+= oneFrameMovie;
    return *this;
}
MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2) {
    MataMvidia ret = movie1;
    return ret += movie2;
}
//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& mos, const MataMvidia& movie) {
    mos << "Movie Name: " << movie.movieName << endl;
    mos << "Author: " <<  movie.creatorName << endl << endl;
    for (int i = 0; i < movie.frameCount; ++i) {
        mos<< "Frame " << i << ":" << endl;
        mos << movie.frames[i] << endl;
    }
    mos<< "-----End of Movie-----" <<endl;
    return mos;
}

//-----------------------------------------------------------------------------


