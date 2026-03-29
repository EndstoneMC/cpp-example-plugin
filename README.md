# Endstone C++ Example Plugin

[![Build](https://github.com/EndstoneMC/cpp-example-plugin/actions/workflows/build.yml/badge.svg)](https://github.com/EndstoneMC/cpp-example-plugin/actions/workflows/build.yml)

A starter template for building [Endstone](https://github.com/EndstoneMC/endstone) plugins in C++.
Endstone is a plugin framework for Minecraft Bedrock Dedicated Server, similar to
Bukkit/Spigot/Paper for Java Edition. This template demonstrates commands, events,
and permissions.

## Use This Template

1. Click **Use this template** on GitHub (or fork/clone it)
2. Rename the following to match your plugin:

| What | Where | Example |
|------|-------|---------|
| Project name | `CMakeLists.txt` `project(...)` | `project(my_plugin VERSION 0.1.0 LANGUAGES CXX)` |
| Plugin version | `CMakeLists.txt` `project(... VERSION ...)` | `0.1.0` |
| Plugin metadata | `src/plugin.cpp` `ENDSTONE_PLUGIN(...)` | `"my_plugin", MY_PLUGIN_VERSION, MyPlugin` |
| Plugin class | `include/plugin.h` class name | `MyPlugin` |
| Prefix | `src/plugin.cpp` `prefix = ...` | `"MyPlugin"` |
| Permission prefix | `src/plugin.cpp` permission names | `my_plugin.command.*` |

3. Update `ENDSTONE_API_VERSION` in `CMakeLists.txt` to the Endstone version you target
4. Delete the example command/listener code and start building

## Development

### Prerequisites

**Windows:** [Visual Studio](https://visualstudio.microsoft.com/) 2019 or newer with the
"Desktop development with C++" workload. CMake is included with Visual Studio, or install it
separately from [cmake.org](https://cmake.org/download/).

**Linux:** Clang 15+ with libc++. Install via [apt.llvm.org](https://apt.llvm.org/):

```bash
# Install CMake and Ninja
sudo apt-get install -y cmake ninja-build

# Install LLVM/Clang (replace 18 with desired version)
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 18
sudo apt-get install -y libc++-18-dev libc++abi-18-dev
```

### Building

```bash
git clone https://github.com/EndstoneMC/cpp-example-plugin.git
cd cpp-example-plugin
```

**Windows:**
```bash
cmake -B build
cmake --build build --config Release
```

**Linux:**
```bash
CC=clang-18 CXX=clang++-18 cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Project Structure

```
include/
  plugin.h       Plugin lifecycle, commands
  listener.h     Event listener (player join/quit)
src/
  plugin.cpp     Plugin metadata, command and permission declarations
```

## Install on a Server

After building, copy the output binary to your server's `plugins/` folder:
- **Windows:** `build/Release/endstone_cpp_example.dll`
- **Linux:** `build/endstone_cpp_example.so`

Restart the server to load the plugin.

## Releasing

This template includes a GitHub Actions release workflow. To make a release:

1. Add your changes under `## [Unreleased]` in `CHANGELOG.md`
2. Go to **Actions > Release > Run workflow**
3. Enter the version (e.g. `0.1.0`) and run

The workflow validates the version, updates the changelog, creates a git tag and GitHub release,
builds for both Windows and Linux, and attaches the binaries to the release.

Use **dry run** to preview without making changes.

## Troubleshooting

**`GLIBC_2.xx not found` when loading the plugin on Linux**

Plugins are linked against glibc at build time and require the same or newer version at
runtime. A plugin built on Ubuntu 24.04 will not load on a server running Ubuntu 22.04.

To maximize compatibility, build on an older OS. GitHub Actions runners (Ubuntu 22.04)
are a good default for this reason.

## Documentation

For more on the Endstone API, see the [documentation](https://endstone.dev/latest/).

## License

[MIT License](LICENSE)
