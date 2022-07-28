#include "app.h"
#include "logger.h"

using namespace Infra;

void App::init()
{
  Logger::info("Initialised app");
}

void App::run() { Logger::warn("App is running ..."); }

void App::stop() { Logger::error("Stopping app ..."); }
