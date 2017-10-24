#pragma once

/**
 * A class that represents a single tuple in a Relation.
 */
class Tuple {
private:
    int *values;
    unsigned int numValues;

public:
    /**
     * Tuple constructor. Stores a copy of the specified values.
     * @param values An array of int values to be copied into the Tuple.
     * @param numValues The length of the array.
     */
    Tuple(const int *values, unsigned int numValues);

    /**
     * Tuple destructor. Deallocates internal state.
     */
    ~Tuple();

    /**
     * Returns the value at the specified index in the Tuple in O(1) time, or
     * throws an std::invalid_argument.
     * @param index The index of the desired value.
     * @return The value at the specified index.
     * @throw std::invalid_argument if index >= the number of values.
     */
    int getValue(unsigned int index) const;
};
