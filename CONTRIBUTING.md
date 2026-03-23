# Contributing

Thanks for your interest in improving this template!

## Development Setup

### Windows
- Visual Studio 2017 or newer
- CMake 3.15+

### Linux
- Clang 15+ with libc++
- CMake 3.15+

```bash
git clone https://github.com/EndstoneMC/cpp-example-plugin.git
cd cpp-example-plugin
cmake -B build
cmake --build build
```

## Making Changes

1. Create a branch for your changes
2. Ensure the project builds on at least one platform
3. Update `CHANGELOG.md` under `## [Unreleased]` if your change is user-facing
4. Open a pull request with a clear description of what changed and why

## Code Style

- Follow existing patterns in the codebase
- Keep examples simple and well-commented (this is a teaching template)
- Use the `.clang-format` configuration for consistent formatting

## Reporting Issues

Use [GitHub Issues](https://github.com/EndstoneMC/cpp-example-plugin/issues) for bugs
and feature requests.
