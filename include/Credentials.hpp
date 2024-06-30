/*!
 * Wrapper around login credentials.
 */
#pragma once
#include <string>

namespace ntfy {
    /*!
     * \brief Credentials which can be used to access topics.
     */
    class Credentials {
    public:
        std::string name;
        std::string password;
    };
} // namespace ntfy