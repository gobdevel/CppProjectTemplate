#include "app.h"
#include "config.h"
#include "logger.h"

int main()
{
  Infra::Config::getInstance().init("filename");

  // If you want to initialise file logging
  // Infra::Logger::init("mainApp", "/tmp/testLog.log");

  // Enable console logging
  Infra::Logger::init();

  App app;
  app.init();
  app.run();
  app.stop();
}