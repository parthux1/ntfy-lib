/*
 * Adds json functionality for
 * - deserializing ntfy::Message from get requests
 */

#pragma once

#include "Message.hpp"
#include <nlohmann/json.hpp>

namespace ntfy::json {

    /*!
     * Parse json data  sent by a ntfy server to a message
     * \param j json data
     * \returns Message object
     * \throws std::domain_error if event-type is not "message"
     * \throws std::runtime_error if message content is not set
     */
    Message stream_to_msg(const nlohmann::json& j);
} // namespace ntfy::json
