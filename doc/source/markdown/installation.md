# Installation

## using vcpkg

Currently only installation using custom a GitHub repo port ist implemented: See for relevant files.
You may need to update `SHA512` in [`portfile.cmake`](./port/portfile.cmake).

### Tutorial for manifest mode

1. Save files in [`port/`](./port) to your local disk, for example `<proj_root>/ports/`.
2. register port dir for example by creating `<proj_root>/vcpkg-configuration.json`:

```json
{
  "overlay-ports": [
    "./ports"
  ]
}
```

3. include this project in your `vcpkg.json`:

```json
{
  "name": "ntfy-lib",
  "version>=": "1.0.0"
}
```

4. install using

```bash
vcpkg install
```

5. include lib in your `CmakeLists.txt`

```cmake
find_package(ntfy-lib)
target_link_libraries(<proj> PRIVATE ntfy-lib::ntfy)
```

6. Follow [Examples](#examples)

