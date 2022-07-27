#include "app.h"
#include "logger.h"

void App::init()
{
  Logger::init();
  Logger::info("Initialised app {}", 22);
}

void App::run() { Logger::warn("Initialised app..."); }

void App::stop() { Logger::error("Initialised app..."); }
