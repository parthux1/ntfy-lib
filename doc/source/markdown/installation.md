# Installation

## using vcpkg

Currently only installation using an [overlay port](https://learn.microsoft.com/en-us/vcpkg/concepts/overlay-ports) is
implemented. Files can be found in `port/` or in releases.

### Tutorial for manifest mode

1. Save files vcpkg files to your local disk, for example `<proj_root>/ports/`.
    1. You may find them added to release tags
    2. If your targeted release does not contain vcpkg file:
        1. copy files from `port/`
        2. update `REF` to your release tag and continue with steps 2-4.
        3. Step 4 might crash because of a Hash-Mismatch, update `SHA512` to the hash vcpkg shows you
2. register port dir, for example by creating `<proj_root>/vcpkg-configuration.json`:

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
target_link_libraries(<target> PRIVATE ntfy-lib::ntfy)
```

6. Follow [Examples](./examples.md)

