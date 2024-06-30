# ntfy-lib

ntfy API for C++.  
Implements partially ntfy functionality stated in https://docs.ntfy.sh/subscribe/api/

- [Examples](#examples)
- [Capabilities](#capabilities)
- [Building with vcpk](#-building-with-vcpkg)
    - [using CLI](#-using-cli)
    - [using CLion UI](#-using-clion-ui)
- [Documentation](#-documentation)

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

const auto config = ntfy::YamlConfiguration::from_file("example.ntfy.config");

auto server = ntfy::Server{config.server_url};
const auto msg = ntfy::Message{.content="hello world", .title="Sent from my cpp program"};

server.send(config.topics.at("secret-topic"), msg, config.credentials);
```

## Capabilities

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

## 🛠️ Building with vcpkg

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

## 📃 Documentation

You can generate a documentation using doxygen.
This will include files from `src/` and `doc/source/`.  
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
