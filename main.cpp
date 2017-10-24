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
 * Helper function to add a Tuple of 3 specified values to a Relation. Note
 * that the Relation is passed by reference!
 * @param relation The Relation to which the Tuple will be added
 * @param val1 The first value to be used in the Tuple
 * @param val2 The second value to be used in the Tuple
 * @param val3 The third value to be used in the Tuple
 */
void addTuple3(Relation &relation, int val1, int val2, int val3) {
    int values[] = {val1, val2, val3};
    relation.addTuple(values);

    // Even after values goes out of scope, the Relation should not be affected
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
    addTuple3(student, 1, 2, 3);
    const Tuple *t0 = student.getTuple(0);
    assert(t0 != nullptr);
    assert(t0->getValue(0) == 1);
    assert(t0->getValue(1) == 2);
    assert(t0->getValue(2) == 3);

    // Get a Tuple with an index out of bounds
    try {
        student.getTuple(1);
        assert(false);
    } catch (std::invalid_argument &e) {}

    std::cout << "Passed Test 2" << std::endl;
}

/**
 * Tests for Relation class with resize.
 */
void test3() {
    std::cout << "Test 3" << std::endl;

    // Create a Relation student
    Relation student(3);
    assert(student.getNumAttributes() == 3);
    assert(student.getCardinality() == 0);

    // Insert 5 Tuples
    addTuple3(student, 1, 2, 3);
    addTuple3(student, 4, 5, 6);
    addTuple3(student, 7, 8, 9);
    addTuple3(student, 10, 11, 12);
    addTuple3(student, 13, 14, 15);

    // Make sure Tuples were inserted correctly
    const Tuple *t0 = student.getTuple(0);
    const Tuple *t1 = student.getTuple(1);
    const Tuple *t2 = student.getTuple(2);
    const Tuple *t3 = student.getTuple(3);
    const Tuple *t4 = student.getTuple(4);
    assert(t0 != nullptr);
    assert(t1 != nullptr);
    assert(t2 != nullptr);
    assert(t3 != nullptr);
    assert(t4 != nullptr);
    assert(t0->getValue(0) == 1);
    assert(t0->getValue(1) == 2);
    assert(t0->getValue(2) == 3);
    assert(t1->getValue(0) == 4);
    assert(t1->getValue(1) == 5);
    assert(t1->getValue(2) == 6);
    assert(t2->getValue(0) == 7);
    assert(t2->getValue(1) == 8);
    assert(t2->getValue(2) == 9);
    assert(t3->getValue(0) == 10);
    assert(t3->getValue(1) == 11);
    assert(t3->getValue(2) == 12);
    assert(t4->getValue(0) == 13);
    assert(t4->getValue(1) == 14);
    assert(t4->getValue(2) == 15);

    // Get a Tuple with an index out of bounds
    try {
        student.getTuple(5);
        assert(false);
    } catch (std::invalid_argument &e) {}

    std::cout << "Passed Test 3" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    std::cout << "Passed all tests" << std::endl;
    return 0;
}
