#pragma once
#include <optional>
#include <string>

class INIReader;

namespace Infra
{
    class Config
    {
    public:
        void init(const std::string filename);
        std::optional<std::string> getString(const std::string section, const std::string key);
        std::optional<int> getInt(std::string section, std::string key);

        static Config &getInstance();

    private:
        Config() = default;
        INIReader *m_reader{nullptr};
    };

}