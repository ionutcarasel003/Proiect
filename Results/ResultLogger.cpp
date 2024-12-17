//
// Created by Ionut Stefan Carasel on 11/14/2024.
//

#include "ResultLogger.h"
#include <fstream>

void ResultLogger::logResult(const Result &result) {
    results.push_back(result);
}

void ResultLogger::exportResultsToCSV(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Test Name,Size,Execution Time (s),Transfer Rate\n";
        for (const auto& result : results) {
            file << result.test_name << "," << result.size << ","
                 << result.exec_time << "," << result.transfer_rate << "\n";
        }

        file.close();
    }
}

void ResultLogger::generatePlot(){
    system("python H:/SSC/Proiect/plot.py");
}
