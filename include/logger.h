#pragma once
#include "spdlog/common.h"
#include "spdlog/spdlog.h"

namespace Infra {
class Logger {
public:
    static void init();
    static void init(const std::string appName, const std::string filename);

    template <typename... Args>
    static void info(const std::string msg, Args &&...args) {
        if (s_logger) {
            s_logger->info(msg, std::forward<Args>(args)...);
        }
    }

    template <typename... Args>
    static void warn(const std::string msg, Args &&...args) {
        if (s_logger) {
            s_logger->warn(msg, std::forward<Args>(args)...);
        }
    }

    template <typename... Args>
    static void error(const std::string msg, Args &&...args) {
        if (s_logger) {
            s_logger->error(msg, std::forward<Args>(args)...);
        }
    }

    static void setLogLevel(const std::string &loglevel) {
        auto level = spdlog::level::from_str(loglevel);
        s_logger->set_level(level);
    }

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};
}  // namespace Infra
