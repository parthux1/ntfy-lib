//
// Created by parthu on 6/29/24.
//

#include <ntfy-lib/YamlConfiguration.hpp>
ntfy::YamlConfiguration ntfy::YamlConfiguration::from_file(std::filesystem::path file_path) {

    if (!file_path.has_filename()) {
        throw std::invalid_argument("Passed file_path does not point to a file. Got: " + file_path.string());
    }

    YamlConfiguration config{};

    const YAML::Node n_root = YAML::LoadFile(file_path.string());

    auto throw_if_key_is_missing = [](const YAML::Node& node, std::string_view key) {
        if (!node[key]) {
            const std::string msg = std::string("section '") + key.data() + "' is missing.";
            throw std::domain_error(msg);
        }
    };

    throw_if_key_is_missing(n_root, "server");

    // required server information
    const auto& n_server = n_root["server"];
    throw_if_key_is_missing(n_server, "url");
    config.server_url = n_server["url"].as<std::string>();

    // optional user information
    if (n_root["user"]) {
        const auto& n_user = n_root["user"];
        throw_if_key_is_missing(n_user, "name");
        throw_if_key_is_missing(n_user, "password");
        Credentials c;
        c.name = n_user["name"].as<std::string>();
        c.password = n_user["password"].as<std::string>();
        config.credentials = c;
    }

    // optional topic mapping
    if (n_root["topics"]) {
        const auto& n_topics = n_root["topics"];
        for (const auto& item : n_topics) {
            const auto key = item.first.as<std::string>();
            const auto val = item.second.as<std::string>();
            config.topics[key] = val;
        }
    }

    return config;
}
