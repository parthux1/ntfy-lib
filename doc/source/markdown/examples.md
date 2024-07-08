# Examples

Sending a message to a topic:

```C++
#include <ntfy-lib/ntfy.hpp>

auto server = ntfy::Server{"https://example-url.com"};
const auto msg = ntfy::Message{.content="hello world", .title="Sent from my cpp program"};

server.send("mytopic", msg);
```

Load an external configuration to hide information

```C++
#include <ntfy-lib/ntfy.hpp>
#include <ntfy-lib/YamlConfiguration.hpp>

const auto config = ntfy::YamlConfiguration::from_file("example.ntfy.config");

auto server = ntfy::Server{config.server_url};
const auto msg = ntfy::Message{.content="hello world", .title="Sent from my cpp program"};

server.send(config.topics.at("secret-topic"), msg, config.credentials);
```

Listen for messages in a topic

```C++
#include <iostream>
#include <ntfy-lib/ntfy.hpp>
#include <ntfy-lib/YamlConfiguration.hpp>

const auto config = ntfy::YamlConfiguration::from_file("example.ntfy.config");
auto server = ntfy::Server{config.server_url};

auto listener = server.listen_to(config.topics.at("test"), config.credentials);
listener.add_handler("print_msg", 
                     [](const ntfy::Message m) {
                        std::cout << m.str() << std::endl;
                     });
listener.start();
// block main thread so listener is not destroyed
std::string input{};
while (input != "stop") {
    std::cout << "> ";
    std::cin >> input;
}
listener.stop()
```