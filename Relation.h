#pragma once

#include "Tuple.h"

/**
 * A class that represents a single relation in a database.
 */
class Relation {
private:
    Tuple **tuples;
    unsigned int numAttributes;
    unsigned int cardinality;
    unsigned int capacity;

    void resize();

public:
    /**
     * Relation constructor. Constructs a Relation with cardinality 0.
     * @param numAttributes The number of attributes in the Relation.
     */
    Relation(unsigned int numAttributes);

    /**
     * Relation destructor. Deallocates internal state.
     */
    ~Relation();

    /**
     * Returns the number of attributes in the Relation.
     * @return The arity.
     */
    unsigned int getNumAttributes() const;

    /**
     * Returns the number of tuples in the Relation.
     * @return The cardinality.
     */
    unsigned int getCardinality() const;

    void addTuple(int *values);

    Tuple *getTuple(unsigned int index);
};
