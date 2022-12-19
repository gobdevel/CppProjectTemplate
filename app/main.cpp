#include <argparse/argparse.hpp>

#include "app.h"
#include "config.h"
#include "logger.h"

int main(int argc, char* argv[]) {
    argparse::ArgumentParser program("app");
    program.add_argument("-c", "--config").help("Config file name");

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    if (auto fn = program.present("-c")) {
        std::cout << "Filename : " << *fn << "\n";
        Infra::Config::getInstance().init(*fn);
    }

    /* If you want to initialise file logging */
    // Infra::Logger::init("mainApp", "/tmp/testLog.log");

    /* Enable console logging */
    Infra::Logger::init();
    Infra::Logger::error("First set of message");

    App app;
    app.init();
    app.run();
    app.stop();
}
