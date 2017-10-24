#pragma once

class Tuple {
private:
    int *values;
    unsigned int numValues;

public:
    Tuple(int *values, unsigned int numValues);

    ~Tuple();

    int getValue(unsigned int index);
};
