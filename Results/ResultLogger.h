//
// Created by Ionut Stefan Carasel on 11/14/2024.
//

#ifndef PROIECT_RESULTLOGGER_H
#define PROIECT_RESULTLOGGER_H

#include "Result.h"
#include <vector>
#include <string>

class ResultLogger {
    std::vector<Result> results;

public:
    void logResult(const Result& result);
    void exportResultsToCSV(const std::string& filename);
    static void generatePlot();
};


#endif //PROIECT_RESULTLOGGER_H
