set(ntfy_SRC
        ${PROJECT_SOURCE_DIR}/src/ntfy-lib/jsonFunc.cpp
        ${PROJECT_SOURCE_DIR}/src/ntfy-lib/Message.cpp
        ${PROJECT_SOURCE_DIR}/src/ntfy-lib/MessageListener.cpp
        ${PROJECT_SOURCE_DIR}/src/ntfy-lib/Server.cpp
        ${PROJECT_SOURCE_DIR}/src/ntfy-lib/YamlConfiguration.cpp)

target_sources(ntfy
        PUBLIC
        ${ntfy_SRC}
)