#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <LLAPI.h>

Logger logger("Calculator");

void registerCommands(CommandRegistry* reg);

void entry() {
    logger.info("Calculator v{} loaded! Author: Jasonzyt  Build at {}",
        version.toString(), __DATE__ " " __TIME__);
    Event::RegCmdEvent::subscribe([&](Event::RegCmdEvent ev) {
        registerCommands(ev.mCommandRegistry);
        return true;
    });
}
