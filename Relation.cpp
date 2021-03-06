#include "Relation.h"
#include "Tuple.h"

#include <stdexcept>

Relation::Relation(unsigned int numAttributes) {
    this->tuples = new Tuple*[4];
    this->numAttributes = numAttributes;
    this->cardinality = 0;
    this->capacity = 4;
}

Relation::~Relation() {
    for (unsigned int i = 0; i < this->cardinality; ++i) {
        delete this->tuples[i];
    }
    delete[] this->tuples;
}

void Relation::resize() {
    // Policy: double the capacity
    Tuple **newTuples = new Tuple*[this->capacity * 2];
    for (unsigned int i = 0; i < this->capacity; ++i) {
        newTuples[i] = this->tuples[i];
    }
    this->capacity *= 2;
    delete[] this->tuples;
    this->tuples = newTuples;
}

unsigned int Relation::getNumAttributes() const {
    return this->numAttributes;
}

unsigned int Relation::getCardinality() const {
    return this->cardinality;
}

void Relation::addTuple(const int *values) {
    if (this->cardinality == this->capacity) {
        this->resize();
    }
    Tuple *tuple = new Tuple(values, this->numAttributes);
    this->tuples[this->cardinality] = tuple;
    this->cardinality += 1;
}

const Tuple *Relation::getTuple(unsigned int index) const {
    if (index >= this->cardinality) {
        throw std::invalid_argument("Relation index out of bounds");
    }
    return this->tuples[index];
}
