//
// Created by parthu on 6/30/24.
//

#include "MessageListener.hpp"

ntfy::MessageListener::MessageListener(cpr::Session session)
    : session(std::make_shared<cpr::Session>(std::move(session))) {
    cpr::priv::set_option(*this->session,
                          // callback for distributing to potential handlers
                          cpr::WriteCallback([&](std::string data, intptr_t userdata) -> bool {
                              nlohmann::json j = nlohmann::json::parse(data);
                              // only forward to callback if a message was sent
                              if (j.value("event", "not set") == "message") {
                                  Message m = ntfy::json::stream_to_msg(j);

                                  // const std::lock_guard<std::mutex> lock(m_handlers);
                                  for (auto& [id, handler] : handlers) {
                                      handler(m);
                                  }
                              }

                              return true;
                          }),
                          // callback for stopping the session
                          cpr::ProgressCallback([&](cpr::cpr_off_t downt, cpr::cpr_off_t downn, cpr::cpr_off_t upt,
                                                    cpr::cpr_off_t upn, intptr_t userdata) -> bool {
                              if (m_running) {
                                  return true;
                              }

                              spdlog::debug("{} thread received stop-signal.", log_preface());
                              return m_running;
                          }));
}

ntfy::MessageListener::~MessageListener() {
    if (is_running()) {
        stop();
    }
}

void ntfy::MessageListener::start() {

    if (is_running()) {
        throw std::logic_error("Listener already running.");
    }
    m_running = true;
    response = session->GetAsync();
}

cpr::Response ntfy::MessageListener::stop() {

    // never started?
    if (!is_running()) {
        throw std::logic_error("Listener was not started.");
    }

    m_running = false;
    return response->get();
}
ntfy::MessageListener& ntfy::MessageListener::add_handler(const std::string& id, HandlerType callback) {
    const std::lock_guard<std::mutex> lock(m_handlers);
    handlers.insert_or_assign(id, callback);
    spdlog::debug("{}Added Handler with ID {}", log_preface(), id);
    return *this;
}

bool ntfy::MessageListener::is_running() const { return m_running && response.has_value(); }

std::string ntfy::MessageListener::log_preface() {
    return std::string("MessageListener<") + std::to_string(long(this)) + ">: ";
}
