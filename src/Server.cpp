//
// Created by parthu on 6/29/24.
//
#include <Server.hpp>

ntfy::Server::Server(std::string url) : server_url(std::move(url)) {
    // URL error handling
    if (server_url.str().back() != '/') {
        server_url += "/";
    }
}

cpr::Response ntfy::Server::send(const std::string& topic, const Message& message,
                                 const std::optional<Credentials>& credentials) {

    cpr::Url topic_url = server_url + topic;

    // setup post request
    cpr::Session session;
    cpr::Header header{};
    cpr::priv::set_option(session, topic_url, cpr::Body{message.content});

    // maybe add header content
    if (message.title.has_value()) {
        header.insert({"t", message.title.value()});
    }

    if (message.priority.has_value()) {
        header.insert({"p", std::to_string(static_cast<int>(message.priority.value()))});
    }

    if (!message.tags.empty()) {
        std::string tag_str;
        for (const auto& tag : message.tags) {
            tag_str += tag + ",";
        }
        // rm last ,
        tag_str.pop_back();

        header.insert({{"ta", tag_str}});
    }

    if (message.enable_markdown) {
        header.insert({{"Markdown", "yes"}});
    }

    if (!header.empty()) {
        cpr::priv::set_option(session, header);
    }

    // maybe add base auth
    handle_basic_auth(session, credentials);

    spdlog::debug("Sending to {}", topic_url.str());
    // send msg
    return session.Post();
}

ntfy::MessageListener ntfy::Server::listen_to(const std::string& topic, const std::optional<Credentials>& credentials) {
    cpr::Url topic_url = server_url + topic + "/json";
    cpr::Session session;
    handle_basic_auth(session, credentials);
    cpr::priv::set_option(session, topic_url);

    // handler
    spdlog::debug("target URL: {}", topic_url.str());

    return MessageListener(std::move(session));
}

void ntfy::Server::handle_basic_auth(cpr::Session& session, const std::optional<Credentials>& credentials) {
    if (credentials.has_value()) {
        const cpr::Authentication auth{credentials->name, credentials->password, cpr::AuthMode::BASIC};
        cpr::priv::set_option(session, auth);
    }
}
