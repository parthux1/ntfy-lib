# ntfy-lib

Third party ntfy API for C++.  
Partial implementation of ntfy functionality as stated in https://docs.ntfy.sh/subscribe/api/

- [Features](#features)
- [Examples](#examples)
- [Installation](#installation)
- [Documentation](#documentation)
- [Development](#development)
- [Attributions and Licence](#attributions-and-licence)

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

## Examples

Code snippets can be found in [this markdown](doc/source/markdown/examples.md).

## Installation

See [this markdown](doc/source/markdown/installation.md).

## Documentation

Statically included markdown files can be found in [`doc/source/markdown`](doc/source/markdown).

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

## Development

### Building with vcpkg

- Have a working vcpkg installation.
- set env variable `VCPKG_ROOT` to point to its dir
- build with the suplied `CMakePresets.json`

```shell
cmake --preset ntfy-lib
cmake --build --preset ntfy-lib
```

## Attributions and Licence

- Check out [ntfy](https://github.com/binwiederhier/ntfy).
- This project is not affiliated to ntfy in any way.

ntfy-lib
Copyright (c) 2024, parthux1
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.