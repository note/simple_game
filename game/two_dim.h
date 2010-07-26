#ifndef TWO_DIM_H
#define TWO_DIM_H
#include "exceptions.h"

template <class T>
class TwoDim{
    public:
    T * ptr;
    int columns, rows;
    TwoDim(const unsigned int columns, const unsigned int rows){
        ptr = new T[columns*rows];
        this->columns = columns;
        this->rows = rows;
    }
    ~TwoDim(){
        delete []ptr;
    }
    T * operator [] (int i) const throw(OutOfRange){
        if(i>=rows)
            throw OutOfRange();
        return &ptr[i*columns];
    }
};

#endif // TWO_DIM_H
