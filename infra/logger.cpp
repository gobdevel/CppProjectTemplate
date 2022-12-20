#include "logger.h"

#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Infra {
std::shared_ptr<spdlog::logger> Logger::s_logger{nullptr};

void Logger::init() { s_logger = spdlog::stdout_color_mt("console"); }

void Logger::init(const std::string appName, const std::string filename) {
    constexpr auto max_size  = 1048576 * 5;  // 5mb
    constexpr auto max_files = 3;
    if (s_logger) {
        s_logger.reset();
    }
    s_logger =
        spdlog::rotating_logger_mt(appName, filename, max_size, max_files);
}
}  // namespace Infra
