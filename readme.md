# ntfy-lib

ntfy API for C++.  
Implements partially ntfy functionality stated in https://docs.ntfy.sh/subscribe/api/

- [Examples](#examples)
- [Features](#features)
- [Building with vcpk](#building-with-vcpkg)
- [Documentation](#documentation)
- [Attributions and Licence](#attributions-and-licence)

## Examples

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

## Features

- login to ntfy server
    - [x] baseauth
    - [ ] token
- messages
    - [x] sending
    - [X] listening (async with handlers)
    - [x] priority
    - [x] tags
    - [x] title
    - [x] markdown
    - [ ] actions
    - [ ] attachments
    - [ ] UTF8 support
    - [ ] scheduled delivery

## Building with vcpkg

- clone with submodules to get vcpkg
- run bootstrap and install dependencies

```bash
# run in project root or install dependecies by yourself from vcpkg.json
sh ./scripts/vcpkg_setup.sh
```

Toolchain-File of Vcpkg is included in the CMakeLists.txt.  
Build the library by running cmake or by running:

```bash
# run in project root
sh ./scripts/build.sh
```

## Documentation

You can generate a documentation by using doxygen.  
Documentation will be written to `doc/out/`.

```bash
# run in project root
doxygen doc/DoxyFile

# open the documentation
# windows
start doc/out/html/index.html
# linux
open doc/out/html/index.html
```

## Attributions and Licence

- Check out [ntfy](https://github.com/binwiederhier/ntfy).
- This project is not affiliated to ntfy in any way.

ntfy-lib
Copyright (c) 2024, parthux1
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree. 