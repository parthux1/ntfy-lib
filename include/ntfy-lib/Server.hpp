//
// Created by parthu on 6/29/24.
//
#pragma once

#include <chrono>
#include <ctime>
#include <vector>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include "Credentials.hpp"
#include "Message.hpp"
#include "MessageListener.hpp"
#include "jsonFunc.hpp"

namespace ntfy {
    /*!
     * Represents a ntfy server which can be accessed.
     */
    class Server {
    public:
        explicit Server(std::string url);

        /*!
         * \brief Send a message to the ntfy server
         * \param topic topic name to send to
         * \param message Message content
         * \param credentials Credentials required for topic access
         * \return Response from the server
         */
        cpr::Response send(const std::string& topic, const Message& message,
                           const std::optional<Credentials>& credentials = std::nullopt);

        /*!
         * \brief Listen for messages from the ntfy server
         * \param topic Topic to listen to
         * \param credentials Credentials required for topic access
         * \returns a ServerMessageStream which can be listened to
         */
        MessageListener listen_to(const std::string& topic,
                                  const std::optional<Credentials>& credentials = std::nullopt);

    private:
        cpr::Url server_url;

        /*!
         * \brief Add basic auth if credentials are set
         * \param session Session to handle auth for
         * \param credentials credentials to add to session
         */
        static void handle_basic_auth(cpr::Session& session, const std::optional<Credentials>& credentials);
    };
} // namespace ntfy
