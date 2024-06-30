/*
 * Model representing a ntfy message which can be sent or received.
 */

#pragma once
#include <optional>
#include <string>
#include <vector>

namespace ntfy {

    //! see https://docs.ntfy.sh/publish/#message-priority
    enum class Priority { min = 1, low, _default, high, max };

    /*!
     * \brief A ntfy message.
     */
    class Message {
    public:
        //! Message body
        std::string content;
        //! Title of the message
        std::optional<std::string> title{};
        //! see https://docs.ntfy.sh/publish/#message-priority
        std::optional<Priority> priority{};
        //! See https://docs.ntfy.sh/emojis/ for emoji-tags
        std::vector<std::string> tags{};
        //! Some clients can display the content of a message as markdown.
        bool enable_markdown = false;

        /*!
         * Serialize to string.
         * \return std::string containing all information
         */
        std::string str();
    };
} // namespace ntfy