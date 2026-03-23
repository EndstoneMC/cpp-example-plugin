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
| Project name | `CMakeLists.txt` `project(...)` | `project(my_plugin CXX)` |
| Plugin metadata | `src/plugin.cpp` `ENDSTONE_PLUGIN(...)` | `"my_plugin", "0.1.0", MyPlugin` |
| Plugin class | `include/plugin.h` class name | `MyPlugin` |
| Prefix | `src/plugin.cpp` `prefix = ...` | `"MyPlugin"` |
| Permission prefix | `src/plugin.cpp` permission names | `my_plugin.command.*` |

3. Update the `GIT_TAG` in `CMakeLists.txt` to the Endstone version you target
4. Delete the example command/listener code and start building

## Development

### Prerequisites

**Windows:** Visual Studio 2017 or newer

**Linux:** Clang 15+ with libc++ installed

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
cmake -B build -DCMAKE_BUILD_TYPE=Release
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

## Documentation

For more on the Endstone API, see the [documentation](https://endstone.dev/latest/).

## License

[MIT License](LICENSE)
