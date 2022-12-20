#include <argparse/argparse.hpp>

#include "app.h"
#include "config.h"
#include "logger.h"

constexpr char appName[] = "MyApp";

/**
 * handle Configuration related to Logging
 *
 */
static void handleLoggingConfig(const std::string filename) {
    Infra::Logger::info("Using config file {}", filename);
    auto ec = Infra::Config::getInstance().init(filename);
    if (ec) {
        Infra::Logger::error("Config module init error {}: ", ec.message());
        return;
    }

    // Loglevel
    const auto loglevel =
        Infra::Config::getInstance().getString("Logging", "loglevel");
    if (loglevel) {
        Infra::Logger::setLogLevel(loglevel.value());
    }

    /* If you want to initialise file logging */
    const auto logfilename =
        Infra::Config::getInstance().getString("Logging", "filename");
    if (logfilename) {
        Infra::Logger::init(appName, logfilename.value());
    }
}

/*
 * handle app Configuration
 *
 */
static void handleConfig(int argc, char* argv[]) {
    argparse::ArgumentParser program(appName);
    program.add_argument("-c", "--config").help("Config file name");

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        Infra::Logger::error(err.what());
        std::exit(1);
    }

    // Logging configuration
    if (auto fn = program.present("-c")) {
        handleLoggingConfig(*fn);
    }
}

int main(int argc, char* argv[]) {
    /* Enable console logging */
    Infra::Logger::init();
    handleConfig(argc, argv);

    App app;
    app.init();
    app.run();
    app.stop();
}
