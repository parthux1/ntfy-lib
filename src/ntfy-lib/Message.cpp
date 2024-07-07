//
// Created by parthu on 6/29/24.
//
#include <ntfy-lib/Message.hpp>

[[maybe_unused]] std::string ntfy::Message::str() {
    std::string ret_str{};
    ret_str += "Title: " + title.value_or("not set");
    ret_str += "\nContent: " + content;
    ret_str += "\nPriority: " + std::to_string(static_cast<int>(priority.value_or(ntfy::Priority::_default)));
    ret_str += std::string("\nmarkdown: ") + (enable_markdown ? "yes" : "no");

    std::string tag_str = "[";
    for (const auto& tag : tags) {
        tag_str += tag + ",";
    }
    // rm last , if tags were inserted
    if (tag_str.size() > 1) {
        tag_str.pop_back();
    }
    tag_str += "]";
    ret_str += "\nTags: " + std::move(tag_str);
    return ret_str;
}
