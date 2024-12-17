//
// Created by Ionut Stefan Carasel on 11/13/2024.
//

#include "MatrixTest.h"
#include <chrono>
#include <random>

MatrixTest::MatrixTest(size_t size, size_t rep)
        : size(size), repetitions(rep),
          matrixA(size, std::vector<int>(size)),
          matrixB(size, std::vector<int>(size)),
          matrixC(size, std::vector<int>(size,0)) {

    // popularea matricilor cu valori random
    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_int_distribution<int> distribution(1,100);
    for(size_t i = 0; i<size; i++) {
        for (size_t j = 0; j < size; j++) {
            matrixA[i][j] = distribution(generate);
            matrixB[i][j] = distribution(generate);
            matrixC[i][j] = 0;
        }
    }
}
void MatrixTest::multiplyMatrix(){
    //implementarea inmultirii matricii
    for(size_t rep = 0; rep < repetitions; rep++){
        for(size_t i = 0; i < size; i++){
            for(size_t k = 0; k < size; k++){
                for(size_t j = 0; j < size; j++){
                    matrixC[i][j] += matrixA[i][k]*matrixB[k][j];
                }
            }
        }
    }
}

double MatrixTest::measure_transfer(){
    //pornirea timer-ului
    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatrix();
    //oprirea timer-ului
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::micro> duration = stop - start;
    return duration.count()/repetitions;
}

void MatrixTest::run_test(){
    MatrixTest::time = measure_transfer();
    printf("Programului i-a luat %.3f secunde sa inmulteasca cele 2 matrici\n",MatrixTest::time/1000000);
    size_t byteAmount = (size*size*3*4);
    printf("Performanta: %f B/micros\n",byteAmount/MatrixTest::time);
}

size_t MatrixTest::getByteSize(){
    return size * size * 12;
}

size_t MatrixTest::getKBSize() {
    return getByteSize()/1024;
}

size_t MatrixTest::getMBSize() {
    return getKBSize()/1024;
}

double MatrixTest::get_time_in_seconds(){
    return time/1000000;
}
