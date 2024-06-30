/*!
 * Wrapper around login credentials.
 */
#pragma once
#include <string>

namespace ntfy {
    class Credentials {
    public:
        std::string name;
        std::string password;
    };
} // namespace ntfy