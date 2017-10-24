#include "Tuple.h"

#include <stdexcept>

Tuple::Tuple(const int *values, unsigned int numValues) {
    // Copy from values into a new array
    this->values = new int[numValues];
    for (unsigned int i = 0; i < numValues; ++i) {
        this->values[i] = values[i];
    }

    this->numValues = numValues;
}

Tuple::~Tuple() {
    delete[] this->values;
}

int Tuple::getValue(unsigned int index) const {
    if (index >= this->numValues) {
        throw std::invalid_argument("Tuple index out of bounds");
    }
    return this->values[index];
}
