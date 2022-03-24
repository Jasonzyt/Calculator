#include "pch.h"
#include "Calculator.h"

std::map<int, std::string> errMsgs{
    {CMathParser::ResultFoundNegative, "ERR::FoundNegative"},
    {CMathParser::ResultOk, "ERR::OK"},
    {CMathParser::ResultInfiniteOrNotANumber, "ERR::InfiniteOrNotANumber"},
    {CMathParser::ResultMissingOperator, "ERR::MissingOperator"},
    {CMathParser::ResultInvalidOperator, "ERR::InvalidOperator"},
    {CMathParser::ResultInvalidToken, "ERR::InvalidToken"},
    {CMathParser::ResultIntegerunderflow, "ERR::Integerunderflow"},
    {CMathParser::ResultIntegerOverflow, "ERR::IntegerOverflow"},
    {CMathParser::ResultIntegerTextConversionFailed, "ERR::IntegerTextConversionFailed"},
    {CMathParser::ResultDoubleTextConversionFailed, "ERR::DoubleTextConversionFailed"},
    {CMathParser::ResultRightValueFailed, "ERR::RightValueFailed"},
    {CMathParser::ResultParenthesesMismatch, "ERR::ParenthesesMismatch"},
    {CMathParser::ResultMemoryAllocationError, "ERR::MemoryAllocationError"},
    {CMathParser::ResultUndefiendVariable, "ERR::UndefiendVariable"}
};
std::map<std::string, double> constants{};
std::map<std::string, std::function<double(std::vector<double>)>> methods{};

Calculator::Calculator() {
    setCallbacks();
}

void Calculator::setCallbacks() {
    CMathParser::TVariableSetCallback cb1 = 
        [](CMathParser* parser, const char* var, double* ret) -> bool {
        for (auto& [k, v] : constants) {
            if (k == var) {
                *ret = v;
                return true;
            }
        }
        return false;
    };
    CMathParser::TMethodCallback cb2 =
        [](CMathParser* parser, const char* mtd, double* params, int count, double* ret) -> bool {
        for (auto& [k, v] : methods) {
            if (k == mtd) {
                std::vector<double> vec(params, params + count);
                *ret = v(vec);
                return true;
            }
        }
        return false;
    };
    parser.SetVariableSetCallback(cb1);
    parser.SetMethodCallback(cb2);
}

double Calculator::calculate(const std::string& expression) {
    double res = 0;
    auto status = parser.Calculate(expression.c_str(), &res);
    if (status != CMathParser::ResultOk) {
        throw std::exception(errMsgs[status].c_str());
    }
    return res;
}
