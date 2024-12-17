//
// Created by Ionut Stefan Carasel on 11/20/2024.
//

#include "VectorTest.h"
#include <chrono>
#include <random>
#include <vector>

VectorTest::VectorTest(size_t vec_size, size_t rep):
size(vec_size),repetitions(rep),time(0.0),
vecA(vec_size),vecB(vec_size){
    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_int_distribution<int> distribution(1,100);

    for(size_t i = 0; i<vec_size; i++){
        vecA[i] = distribution(generate);
        vecB[i] = 0;
    }
}

void VectorTest::vector_op() {
    for(size_t j = 0; j<repetitions; j++) {
        for (size_t i = 0; i < size; i++) {
            vecB[i] += vecA[i];
        }
    }
}

double VectorTest::measure_transfer() {
    auto start = std::chrono::high_resolution_clock::now();
    vector_op();
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::micro> duration = stop - start;
    return duration.count()/ repetitions;
}

void VectorTest::run_test() {
    time = measure_transfer();
    printf("Programului i-a luat in medie %f secunde sa proceseze vectorul\n",time/1000000);
    size_t byte_amount = size * 2 * 4;
    printf("Performanta: %f byte/micros\n",byte_amount/time);
}

size_t VectorTest::getByteSize(){
    return size * 2 * 4;
}

size_t VectorTest::getKBSize() {
    return getByteSize()/1024;
}

size_t VectorTest::getMBSize() {
    return getKBSize()/1024;
}

double VectorTest::get_time_in_seconds(){
    return time/1000000;
}