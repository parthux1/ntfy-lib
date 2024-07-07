set(ntfy_INCLUDE
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/Credentials.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/jsonFunc.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/Message.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/MessageListener.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/ntfy.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/Server.hpp
        ${PROJECT_SOURCE_DIR}/include/ntfy-lib/YamlConfiguration.hpp)

target_sources(ntfy
        PUBLIC FILE_SET HEADERS
        BASE_DIRS ${PROJECT_SOURCE_DIR}/include
        FILES ${ntfy_INCLUDE}
)