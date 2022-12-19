#include "config.h"

#include <system_error>

#include "INIReader.h"

namespace Infra {
Config &Config::getInstance() {
    static Config s_config;
    return s_config;
}

std::error_code Config::init(std::string filename) {
    m_reader = new INIReader(filename);
    if (m_reader->ParseError() < 0) {
        return std::make_error_code(std::errc::io_error);
    }
    return std::error_code();
}

std::optional<int> Config::getInt(std::string section, std::string key) {
    std::optional<int> ret;
    if (m_reader) {
        ret = m_reader->GetInteger(section, key, 0);
    }
    return ret;
}

std::optional<std::string> Config::getString(std::string section,
                                             std::string key) {
    std::optional<std::string> ret;
    if (m_reader) {
        ret = m_reader->Get(section, key, "");
    }
    return ret;
}
}  // namespace Infra
