//
// Created by Ionut Stefan Carasel on 11/13/2024.
//

#ifndef PROIECT_MATRIXTEST_H
#define PROIECT_MATRIXTEST_H

#include <iostream>
#include <cstddef>
#include <vector>

class MatrixTest {
protected:
    size_t size;
    size_t repetitions;
    std::vector<std::vector<int>> matrixA;
    std::vector<std::vector<int>> matrixB;
    std::vector<std::vector<int>> matrixC;
    double time;
public:
    MatrixTest(size_t matrix_size, size_t repetitions);
    void run_test();
    double measure_transfer();
    void multiplyMatrix();
    double get_time_in_seconds();
    size_t getByteSize();
    size_t getKBSize();
    size_t getMBSize();
};

#endif //PROIECT_MATRIXTEST_H
