//
// Created by Ionut Stefan Carasel on 11/14/2024.
//

#include "Result.h"

Result::Result(const std::string &name, size_t size, double time):
        test_name(name),size(size),exec_time(time),
        transfer_rate(size/exec_time){}