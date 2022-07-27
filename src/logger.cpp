#include "logger.h"

std::shared_ptr<spdlog::logger> Logger::s_logger{nullptr};

void Logger::init() { s_logger = spdlog::stdout_color_mt("console"); }
