#include "Relation.h"
#include "Tuple.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

/**
 * Tests for Tuple class.
 */
void test1() {
    std::cout << "Test 1" << std::endl;

    // Create a Tuple t0
    int values[] = {1, 2, 3};
    Tuple t0(values, 3);

    // Get values at valid indices
    assert(t0.getValue(0) == 1);
    assert(t0.getValue(1) == 2);
    assert(t0.getValue(2) == 3);

    // Get a value with an index out of bounds
    try {
        t0.getValue(3);
        assert(false);
    } catch (std::invalid_argument &e) {}

    std::cout << "Passed Test 1" << std::endl;
}

/**
 * Tests for Relation class.
 */
void test2() {
    std::cout << "Test 2" << std::endl;

    // Create a Relation student
    Relation student(3);
    assert(student.getNumAttributes() == 3);
    assert(student.getCardinality() == 0);

    // Insert a Tuple and make sure it was inserted correctly
    int values[] = {1, 2, 3};
    student.addTuple(values);
    const Tuple *t0 = student.getTuple(0);
    assert(t0 != nullptr);
    assert(t0->getValue(0) == 1);
    assert(t0->getValue(1) == 2);
    assert(t0->getValue(2) == 3);

    // Get a Tuple with an index out of bounds
    try {
        student.getTuple(1);
    } catch (std::invalid_argument &e) {}

    std::cout << "Passed Test 2" << std::endl;
}

int main() {
    test1();
    test2();
    std::cout << "Passed all tests" << std::endl;
    return 0;
}
