#include <iostream>
#include <cmath>
#include <vector>

#include "MemoryTests/MatrixTest.h"
#include "Results/Result.h"
#include "Results/ResultLogger.h"
#include "MemoryTests/VectorTest.h"
#include "MemoryTests/TestRunner.h"

#define CACHE_1 262144
#define CACHE_2 4194304
#define CACHE_3 16777216

#define RAM 12884901888
#define VM 17185000000

int main() {

    ResultLogger logger;
    TestRunner testRunner;
    printf("Ce fel de test alegi?\nApasa 1 pentru testul cu nivelele de cache\nApasa 2 pentru testul integral cu RAM is memoria virtuala\n");
    int n;
    scanf("%d",&n);
    std::vector<Result> results = testRunner.run_test(n);

    for(const auto & result : results){
        logger.logResult(result);
    }

    logger.exportResultsToCSV("result.csv");
    logger.generatePlot();
    return 0;
}
