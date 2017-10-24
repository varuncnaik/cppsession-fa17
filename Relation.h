#pragma once

#include "Tuple.h"

class Relation {
private:
    Tuple **tuples;
    unsigned int numAttributes;
    unsigned int cardinality;
    unsigned int capacity;

    void resize();

public:
    Relation(unsigned int numAttributes);

    ~Relation();

    unsigned int getNumAttributes();

    unsigned int getCardinality();

    void addTuple(int *values);

    Tuple *getTuple(unsigned int index);
};
