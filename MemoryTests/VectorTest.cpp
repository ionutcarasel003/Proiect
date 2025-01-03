//
// Created by Ionut Stefan Carasel on 11/20/2024.
//

#include "VectorTest.h"
#include <chrono>
#include <random>
#include <vector>
#include <thread>

VectorTest::VectorTest(size_t vec_size, size_t rep):
size(vec_size),repetitions(rep),time(0.0),
vecA(vec_size),vecB(vec_size){
    generateVec();
}

void VectorTest::generateVecTh(size_t start_id, size_t end_id) {
    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t i = start_id; i < end_id; i++) {
        vecA[i] = distribution(generate);
        vecB[i] = 0;
    }
}

void VectorTest::generateVec() {
    const size_t numThreads = 8;
    std::vector<std::thread> threads;
    size_t elementsPerThread = size / numThreads;
    size_t extraElements = size % numThreads;

    size_t current_id = 0;

    for (size_t t = 0; t < numThreads; t++) {
        size_t start_id = current_id;
        size_t end_id = start_id + elementsPerThread + (t < extraElements ? 1 : 0);
        threads.emplace_back(&VectorTest::generateVecTh, this, start_id, end_id);
        current_id = end_id;
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

void VectorTest::vector_opTh(size_t start_id, size_t end_id) {
    for (size_t j = 0; j < repetitions; j++) {
        for (size_t i = start_id; i < end_id; i++) {
            vecB[i] += vecA[i];
        }
    }
}

void VectorTest::vector_op() {
    const size_t numThreads = 8;
    std::vector<std::thread> threads;
    size_t elementsPerThread = size / numThreads;
    size_t extraElements = size % numThreads;

    size_t current_id = 0;

    for (size_t t = 0; t < numThreads; t++) {
        size_t start_id = current_id;
        size_t end_id = start_id + elementsPerThread + (t < extraElements ? 1 : 0);
        threads.emplace_back(&VectorTest::vector_opTh, this, start_id, end_id);
        current_id = end_id;
    }

    for (auto &thread : threads) {
        thread.join();
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