#pragma once
#include <optional>
#include <string>
#include <system_error>

class INIReader;

namespace Infra {
class Config {
public:
    static Config  &getInstance();
    std::error_code init(const std::string filename);

    std::optional<std::string> getString(const std::string section,
                                         const std::string key);
    std::optional<int>         getInt(std::string section, std::string key);

private:
    Config() = default;
    INIReader *m_reader{nullptr};
};
}  // namespace Infra
