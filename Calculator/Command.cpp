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

- §3First Order:§r
    *  	Multiplication
    /  	Division
    %  	Modulation

- §3Second Order:§r
    +  	Addition
    -  	Subtraction

- §3Third Order:§r
    <> 	Logical Not Equal
    |= 	Bitwise Or Equal
    &= 	Bitwise And Equal
    ^= 	Bitwise XOR Equal
    <= 	Less or Equal
    >= 	Greater or Equal
    != 	Not Equal
    <<	Bitwise Left Shift
    >>	Bitwise Right Shift
    =  	Logical Equals
    >  	Logical Greater Than
    <  	Logical Less Than
    && 	Logical AND
    || 	Logical OR
    |  	Bitwise OR
    &  	Bitwise AND
    ^  	Exclusive OR
    !  	Logical NOT
)"

class CalcCommand : public Command {

    std::string expression;

public:

    void execute(const CommandOrigin& ori, CommandOutput& outp) const {
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