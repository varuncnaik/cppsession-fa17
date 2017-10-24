#include "Relation.h"
#include "Tuple.h"

Relation::Relation(unsigned int numAttributes) {
    this->tuples = new Tuple*[4];
    this->numAttributes = numAttributes;
    this->cardinality = 0;
    this->capacity = 4;
}

Relation::~Relation() {
    delete[] this->tuples;
}

unsigned int Relation::getNumAttributes() const {
    return this->numAttributes;
}

unsigned int Relation::getCardinality() const {
    return this->cardinality;
}

void Relation::addTuple(int *values) {
}

Tuple *Relation::getTuple(unsigned int index) {
    return this->tuples[0];
}
