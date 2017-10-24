#include "Relation.h"
#include "Tuple.h"

#include <cassert>
#include <iostream>

void test1() {
    std::cout << "Test 1" << std::endl;

    int values[] = {1, 2, 3};
    Tuple t0(values, 3);
    assert(t0.getValue(0) == 1);
    assert(t0.getValue(1) == 2);
    assert(t0.getValue(2) == 3);
    try {
        t0.getValue(3);
        assert(false);
    } catch (std::invalid_argument &e) {}

    std::cout << "Passed Test 1" << std::endl;
}

void test2() {
    std::cout << "Test 2" << std::endl;

    Relation student(3);
    assert(student.getNumAttributes() == 3);
    assert(student.getCardinality() == 0);

    std::cout << "Passed Test 2" << std::endl;
}

int main() {
    test1();
    test2();
    std::cout << "Passed all tests" << std::endl;
    return 0;
}
