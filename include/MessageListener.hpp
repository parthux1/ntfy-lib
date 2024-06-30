//
// Created by parthu on 6/30/24.
//

#pragma once

#include <future>
#include <iostream>
#include <thread>
#include <vector>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include "Message.hpp"
#include "jsonFunc.hpp"

namespace ntfy {

    class MessageListener {
    public:
        using HandlerType = std::function<void(const ntfy::Message&)>;

        explicit MessageListener(cpr::Session session);
        ~MessageListener();

        /*!
         * Start the Listener
         * \throws std::logic_error if the listener is already running
         */
        void start();
        /*!
         * Stop the Listener
         * \note Stopping the session may take up to 1 second.
         * \throws std::logic_error if listener wasn't started
         */
        cpr::Response stop();

        bool is_running() const;

        /*!
         * Add a handler which will receive incoming messages.
         * \note all registered handlers will receive all messages. Use early-returns to keep stuff fast.
         * \param id unique ID for this handler
         * \param callback function to execute
         * \returns this MessageListener
         */
        MessageListener& add_handler(const std::string& id, std::function<void(ntfy::Message)> callback);

    private:
        std::shared_ptr<cpr::Session> session;
        std::optional<cpr::AsyncResponse> response{};
        //! A running session will read this
        bool m_running = false;

        //! protects handlers
        std::mutex m_handlers;
        std::unordered_map<std::string, HandlerType> handlers;

        /*!
         * \brief Print a log-message preface containing a unique ID for this MessageListener
         */
        std::string log_preface();
    };

}; // namespace ntfy
