#pragma once
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

class Logger
{
public:
  static void init();

  template <typename... Args>
  static void info(const std::string msg, Args &&...args)
  {
    if (s_logger)
    {
      s_logger->info(msg, std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  static void warn(const std::string msg, Args &&...args)
  {
    if (s_logger)
    {
      s_logger->warn(msg, std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  static void error(const std::string msg, Args &&...args)
  {
    if (s_logger)
    {
      s_logger->error(msg, std::forward<Args>(args)...);
    }
  }

private:
  static std::shared_ptr<spdlog::logger> s_logger;
};
