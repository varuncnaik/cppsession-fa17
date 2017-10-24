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

    unsigned int getNumAttributes() const;

    unsigned int getCardinality() const;

    void addTuple(int *values);

    Tuple *getTuple(unsigned int index);
};
