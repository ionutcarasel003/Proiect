//
// Created by Ionut Stefan Carasel on 11/13/2024.
//

#include "MatrixTest.h"
#include <chrono>
#include <random>
#include <thread>

MatrixTest::MatrixTest(size_t size, size_t rep)
        : size(size), repetitions(rep),
          matrixA(size, std::vector<int>(size)),
          matrixB(size, std::vector<int>(size)),
          matrixC(size, std::vector<int>(size, 0)) {
    populateMatrix();
}

void MatrixTest::populateMatrixTh(size_t startRow, size_t endRow) {
    std::random_device rand;
    std::mt19937 generate(rand());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t i = startRow; i < endRow; i++) {
        for (size_t j = 0; j < size; j++) {
            matrixA[i][j] = distribution(generate);
            matrixB[i][j] = distribution(generate);
            matrixC[i][j] = 0; // Inițializare la 0
        }
    }
}

void MatrixTest::populateMatrix() {
    const size_t numThreads = 8;
    std::vector<std::thread> threads;
    size_t rowsPerThread = size / numThreads;
    size_t extraRows = size % numThreads;

    size_t currentRow = 0;

    for (size_t t = 0; t < numThreads; t++) {
        size_t startRow = currentRow;
        size_t endRow = startRow + rowsPerThread + (t < extraRows ? 1 : 0);
        threads.emplace_back(&MatrixTest::populateMatrixTh, this, startRow, endRow);
        currentRow = endRow;
    }

    for (auto &thread : threads) {
        thread.join();
    }
}

void MatrixTest::multiplyMatrixTh(size_t startRow, size_t endRow) {
    for (size_t i = startRow; i < endRow; i++) {
        for (size_t k = 0; k < size; k++) {
            for (size_t j = 0; j < size; j++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void MatrixTest::multiplyMatrix() {
    // Numărul de fire
    const size_t numThreads = 8;
    std::vector<std::thread> threads;
    size_t rowsPerThread = size / numThreads;
    size_t extraRows = size % numThreads;

    size_t currentRow = 0;

    for (size_t t = 0; t < numThreads; t++) {
        size_t startRow = currentRow;
        size_t endRow = startRow + rowsPerThread + (t < extraRows ? 1 : 0);
        threads.emplace_back(&MatrixTest::multiplyMatrixTh, this, startRow, endRow);
        currentRow = endRow;
    }

    // Așteaptă toate firele să termine execuția
    for (auto &thread : threads) {
        thread.join();
    }
}

double MatrixTest::measure_transfer() {
    // Pornirea timer-ului
    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatrix();
    // Oprirea timer-ului
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = stop - start;
    return duration.count() / repetitions;
}

void MatrixTest::run_test() {
    MatrixTest::time = measure_transfer();
    printf("Programului i-a luat %.3f secunde sa inmulteasca cele 2 matrici\n", MatrixTest::time / 1000000);
    size_t byteAmount = (size * size * 3 * 4);
    printf("Performanta: %f B/micros\n", byteAmount / MatrixTest::time);
}

size_t MatrixTest::getByteSize() {
    return size * size * 12;
}

size_t MatrixTest::getKBSize() {
    return getByteSize() / 1024;
}

size_t MatrixTest::getMBSize() {
    return getKBSize() / 1024;
}

double MatrixTest::get_time_in_seconds() {
    return time / 1000000;
}
