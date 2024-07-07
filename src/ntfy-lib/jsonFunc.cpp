//
// Created by parthu on 6/29/24.
//

#include <ntfy-lib/jsonFunc.hpp>

namespace ntfy::json {
    Message stream_to_msg(const nlohmann::json& j) {
        // early return cases
        if (j.value("event", "not set") != "message") {
            throw std::domain_error("Expected event to be of type message");
        }
        if (!j.contains("message")) {
            throw std::runtime_error("Message must have a message field");
        }

        // build msg object
        Message msg;
        j.at("message").get_to(msg.content);
        if (j.contains("title")) {
            msg.title = j.at("title");
        }
        if (j.contains("priority")) {
            msg.priority = j.at("priority");
        }
        if (j.value("content_type", "not set") == "text/markdown") {
            msg.enable_markdown = true;
        }

        if (j.contains("tags")) {
            auto tags = j.at("tags");
            for (auto it = tags.begin(); it != tags.end(); it++) {
                msg.tags.push_back(it.value());
            }
        }

        return msg;
    }
} // namespace ntfy::json
