#include "config.h"
#include "INIReader.h"

namespace Infra
{
    Config &Config::getInstance()
    {
        static Config s_config;
        return s_config;
    }

    void Config::init(std::string filename)
    {
        m_reader = new INIReader(filename);
    }

    std::optional<int> Config::getInt(std::string section, std::string key)
    {
        std::optional<int> ret;
        if (m_reader)
        {
            ret = m_reader->GetInteger(section, key, 0);
        }
        return ret;
    }

    std::optional<std::string> Config::getString(std::string section, std::string key)
    {
        std::optional<std::string> ret;
        if (m_reader)
        {
            ret = m_reader->GetString(section, key, "");
        }
        return ret;
    }
}
