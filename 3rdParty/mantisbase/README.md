# MantisBase C++ Developer Package (linux, v0.4.5-beta.1)

Prebuilt MantisBase shared library + headers for Linux.
Static archives are not shipped in this package.

> New here? Start with the [C++ Dev Package Guide](https://github.com/allankoechke/mantisbase/blob/master/doc/cpp-dev-package.md)
> for the full walkthrough (download, setup, CMake, troubleshooting).

## Layout

```
CMakeLists.txt   add_subdirectory() entry point (defines the `mantisbase` target)
README.md        this file
VERSION          release tag
include/         header tree for this OS (mantisbase headers + bundled
                 third-party headers: drogon, trantor, nlohmann/json,
                 jsoncpp, soci, spdlog, fmt, dukglue, duktape, wolfssl, ...)
libs/
  x86/           prebuilt shared library for x86-64 (libmantisbase.so)
  arm/           prebuilt shared library for aarch64 (libmantisbase.so)
                 (Windows ships x86 only)
lib/cmake/MantisBase/
  MantisBaseConfig.cmake         find_package(MantisBase) entry point
  MantisBaseConfigVersion.cmake  version matching
```

## System prerequisites (linux)

The shared library needs its system dependencies at build and run time. Install them with:

```bash
sudo apt-get update
sudo apt-get install -y libpq-dev uuid-dev
```

Runtime shared libraries on Debian/Ubuntu are `libpq5` and `libuuid1` (see `docker/Dockerfile` in the source repo).

## Quick integration (CMake)

Unzip (e.g. into `mantisbase-linux-cpp-dev/`) and point your project at it:

```cmake
cmake_minimum_required(VERSION 3.22)
project(my_app)

add_subdirectory(path/to/mantisbase-linux-cpp-dev)

add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE mantisbase)
```

Prefer `find_package`? Point CMake at the package instead:

```cmake
# cmake -B build -DCMAKE_PREFIX_PATH=/path/to/mantisbase-linux-cpp-dev
find_package(MantisBase REQUIRED)
target_link_libraries(my_app PRIVATE mantisbase::shared)
```

`main.cpp`:

```cpp
#include <mantisbase/mantisbase.h>

int main(int argc, char* argv[])
{
    auto app = mb::MantisBase::create(argc, argv);
    return app->run();
}
```

## Manual integration (without CMake)

Add `include/` to the header search path and link the matching shared library plus its system dependencies (make sure the `.so` is findable at runtime, e.g. via `rpath` or `LD_LIBRARY_PATH`):

```bash
# Example: Linux x86-64, shared
g++ -std=c++20 main.cpp -I path/to/include -L path/to/libs/x86 -lmantisbase -Wl,-rpath,path/to/libs/x86 -lpq -luuid -ldl -lpthread -lm -o my_app
```

## Help

- Documentation: https://allankoechke.github.io/mantisbase/
- Discord: https://discord.gg/9437XTKRvN
- GitHub Discussions: https://github.com/allankoechke/mantisbase/discussions
- Issues: https://github.com/allankoechke/mantisbase/issues
