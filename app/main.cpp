#include "app.h"
#include "config.h"

int main()
{
  Config::getInstance().init("filename");
  App app;
  app.init();
  app.run();
  app.stop();
}