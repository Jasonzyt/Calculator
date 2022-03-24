#pragma once
#include "pch.h"
#include "third-party/CMathParser/CMathParser.h"
#include <functional>

extern std::map<std::string, double> constants;
extern std::map<std::string, std::function<double(std::vector<double>)>> methods;

class Calculator {

    CMathParser parser;

    void setCallbacks();

public:

    Calculator();
    double calculate(const std::string& expression);

};
