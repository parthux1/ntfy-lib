/*
 * Adds yaml functionality for
 * - configuration import
 */
#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <unordered_map>

#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>

#include <Credentials.hpp>

namespace ntfy {
    /*!
     * An external configuration file for keeping secrets. See res/examples.ntfy.yml for configuration.
     */
    class YamlConfiguration {
    public:
        /*!
         *
         * \param file_path Path to a configuration file
         * \note configuration file example can be found in res/example.ntfy.yml
         * \throws std::invalid_argument if the filepath does not point to a file
         * \return parsed configuration file
         */
        static YamlConfiguration from_file(std::filesystem::path file_path);

    private:
        // Force instantiation through YamlConfiguration::from_file
        YamlConfiguration() = default;

    public:
        // Members
        std::string server_url{};
        std::optional<Credentials> credentials{};
        std::unordered_map<std::string, std::string> topics{};
    };
} // namespace ntfy