//
// Created by Ionut Stefan Carasel on 11/20/2024.
//

#ifndef PROIECT_VECTORTEST_H
#define PROIECT_VECTORTEST_H

#include <iostream>
#include <cstddef>
#include <vector>

class VectorTest {
protected:
    double time;
    size_t size;
    size_t repetitions;
    std::vector<int> vecA;
    std::vector<int> vecB;
    void generateVec();
    void generateVecTh(size_t start_id, size_t end_id);
    void vector_opTh(size_t start_id, size_t end_id);
public:
    VectorTest(size_t vec_size, size_t rep);
    void run_test();
    double measure_transfer();
    void vector_op();
    double get_time_in_seconds();
    size_t getByteSize();
    size_t getKBSize();
    size_t getMBSize();
};

#endif //PROIECT_VECTORTEST_H
