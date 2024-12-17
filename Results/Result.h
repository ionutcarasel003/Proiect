//
// Created by Ionut Stefan Carasel on 11/14/2024.
//

#ifndef PROIECT_RESULT_H
#define PROIECT_RESULT_H

#include <string>

struct Result {
    std::string test_name;
    size_t size;
    double exec_time;
    double transfer_rate;
    Result(const std::string& name, size_t size, double time);
};



#endif //PROIECT_RESULT_H
