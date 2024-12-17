//
// Created by Ionut Stefan Carasel on 11/20/2024.
//

#include "TestRunner.h"
#define CACHE_1 262144
#define CACHE_2 4194304
#define CACHE_3 16777216

#define RAM 12884901888
#define VM 19327352832

#include "MatrixTest.h"
#include "VectorTest.h"
#include <cmath>

std::vector<Result> TestRunner::run_test(int option) {
    std::vector<Result> results;
    if(option == 1){
        MatrixTest cache1Test((int)sqrt(CACHE_1)/12,5);
        cache1Test.run_test();
        results.push_back(Result("Cache L1 Test",cache1Test.getKBSize(),cache1Test.get_time_in_seconds()));

        MatrixTest cache2Test((int)sqrt(CACHE_2)/12,5);
        cache2Test.run_test();
        results.push_back(Result("Cache L2 Test",cache2Test.getKBSize(),cache2Test.get_time_in_seconds()));

        MatrixTest cache3Test((int)sqrt(CACHE_3)/12,5);
        cache3Test.run_test();
        results.push_back(Result("Cache L3 Test",cache3Test.getKBSize(),cache3Test.get_time_in_seconds()));

    }
    else{
        VectorTest cacheTest(CACHE_3/8,10);
        cacheTest.run_test();
        results.push_back(Result("Cache Test",cacheTest.getMBSize(),cacheTest.get_time_in_seconds()));

        VectorTest ramTest(RAM/8,5);
        ramTest.run_test();
        results.push_back(Result("Ram test",ramTest.getMBSize(),ramTest.get_time_in_seconds()));

        VectorTest vmTest(VM/8,2);
        vmTest.run_test();
        results.push_back(Result("Virtual Memory test",vmTest.getMBSize(),vmTest.get_time_in_seconds()));
    }
    return results;
}