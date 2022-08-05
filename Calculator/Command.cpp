#include "pch.h"
#include "Calculator.h"
#include "RegCommandAPI.h"

#define HELP_TEXT \
R"(
§e§lCalculator§r
Calculate a math expression

§bUsage:§r
/calc <expression: string>
/calc help

§bOperators:§r

- §3First Order 第一级:§r
    *  	Multiplication 乘
    /  	Division 除
    %  	Modulation 求余

- §3Second Order 第二级:§r
    +  	Addition 加
    -  	Subtraction 减

- §3Third Order 第三级:§r
    <> 	Logical Not Equal 逻辑不等于
    |= 	Bitwise Or Equal 二进制位或等于
    &= 	Bitwise And Equal 二进制位与等于
    ^= 	Bitwise XOR Equal 二进制位异或等于
    <= 	Less or Equal 小于等于
    >= 	Greater or Equal 大于等于
    != 	Not Equal 不等于
    <<	Bitwise Left Shift 二进制位左移
    >>	Bitwise Right Shift 俄日禁止位右移
    =  	Logical Equals 逻辑等于
    >  	Logical Greater Than 逻辑大于
    <  	Logical Less Than 逻辑小于
    && 	Logical AND 逻辑和
    || 	Logical OR 逻辑或
    |  	Bitwise OR 二进制位或
    &  	Bitwise AND 二进制位与
    ^  	Exclusive OR 二进制异或
    !  	Logical NOT 逻辑否

- §3Functions 函数:§r
    pow(x, a) 求x的a次幂(Power a of x)
    sqrt(x) 开x的二次方(Square root of x)
    sin(x) = sin x
    cos(x) = cos x
    tan(x) = tan x

)"

class CalcCommand : public Command {

    CommandRawText expression;

public:

    void execute(const CommandOrigin& ori, CommandOutput& outp) const {
        std::string expression = this->expression.getText();
        if (expression == "help") {
            outp.success(HELP_TEXT);
            return;
        }
        std::ostringstream oss;
        oss << expression << " = ";
        try {
            auto res = Calculator().calculate(expression);
            oss << std::fixed << res;
            outp.success(oss.str());
        } catch (std::exception e) {
            oss << e.what();
            outp.error(oss.str());
            return;
        }
    }

    static void setup(CommandRegistry* registry) {
        using namespace RegisterCommandHelper;
        registry->registerCommand(
            "calc", "Calculate a math expression", 
            CommandPermissionLevel::Any, 
            { CommandFlagValue::None },
            { (CommandFlagValue)0x80 }
        );
        registry->registerOverload<CalcCommand>(
            "calc", 
            makeMandatory(&CalcCommand::expression, "expression")
        );
    }

};

void registerCommands(CommandRegistry* reg) {
    CalcCommand::setup(reg);
}