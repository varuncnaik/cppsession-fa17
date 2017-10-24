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

    /**
     * Creates a Tuple using the specified parameters and stores it in the
     * Relation. Runs in O(1) amortized time, but O(cardinality) time if a
     * resize occurs.
     * @param values The values for the Tuple constructor.
     */
    void addTuple(const int *values);

    /**
     * Gets the Tuple at the specified index in the Relation in O(1) time,
     * or throws an std::invalid_argument.
     * @param index The index of the desired Tuple.
     * @return A pointer to the Tuple at the specified index. The Tuple cannot
     * be modified. If the Relation is deallocated, then the pointer is a
     * dangling pointer.
     */
    const Tuple *getTuple(unsigned int index) const;
};
