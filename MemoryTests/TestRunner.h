//
// Created by Ionut Stefan Carasel on 11/20/2024.
//

#ifndef PROIECT_TESTRUNERVEC_H
#define PROIECT_TESTRUNERVEC_H

#include <vector>
#include "../Results/Result.h"

class TestRunner {

public:
    std::vector<Result> run_test(int option);
};


#endif //PROIECT_TESTRUNERVEC_H
