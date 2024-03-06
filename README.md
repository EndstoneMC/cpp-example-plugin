# Endstone C++ Plugin Template

Welcome to the official C++ plugin template for Endstone. This repository serves as a starting point for developers
aiming to craft C++ plugins for the Bedrock Dedicated Servers using Endstone.

## Prerequisites

### Windows

- Visual Studio 2017 or newer

### Linux

- Clang 5 or higher
- libc++ installed

## Structure Overview

```
cpp-plugin-template/
├── include/                      # Header files for the plugin
│   ├── example_plugin.h          # Header for the ExamplePlugin class
│   └── fibonacci_command.h       # Header for the FibonacciCommand class
├── src/                          # Source files for the plugin
│   └── example_plugin.cpp        # Implementation for the ExamplePlugin class
├── .clang-format                 # Configuration for Clang format rules
├── .gitignore                    # Git ignore rules
├── CMakeLists.txt                # CMake configuration for building the plugin
├── LICENSE                       # License details
└── README.md                     # This file
```

## Getting Started

1. **Clone this Repository**

   ```bash
   git clone https://github.com/EndstoneMC/cpp-plugin-template.git
   ```

2. **Navigate to the Cloned Directory**

   ```bash
   cd cpp-plugin-template
   ```

3. **Modify & Extend**

   Modify the `EndstoneCppPlugin` class within `include/endstone_cpp_plugin.h` and `src/endstone_cpp_plugin.cpp`.

4. **Building Your Plugin**

   ```bash
   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Release ..
   cmake --build .
   ```

   This process will compile your code and produce a shared library that Endstone can load.

   **Note: If you wish to build against a specific version of Endstone, you can modify the `GIT_TAG` in
   the `CMakeLists.txt` file to point to the desired tag or commit.**

5. **Testing Your Plugin**

   Once built, install your plugin's output binary to the `plugins` directory of your Endstone server. Start the
   Endstone server and check the logs to ensure your plugin loads and operates as expected.

## Documentation

For a deeper dive into the Endstone API and its functionalities, refer to the main Endstone documentation (WIP).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.