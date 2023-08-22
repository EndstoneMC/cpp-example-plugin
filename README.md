# Endstone C++ Plugin Template

Welcome to the official C++ plugin template for Endstone. This repository serves as a starting point for developers
aiming to craft C++ plugins for the Bedrock Dedicated Servers using Endstone.

## Prerequisites

- A compiler that supports C++20.

## Structure Overview

```
cpp-plugin-template/
├── include/                      # Header files for the plugin
│   └── sample_plugin.h           # Header for the SamplePlugin class
├── src/                          # Source files for the plugin
│   └── sample_plugin.cpp         # Implementation for the SamplePlugin class
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

   Start by examining and adjusting the `SamplePlugin` class within `include/sample_plugin.h`
   and `src/sample_plugin.cpp`. If you need to introduce more functionalities or classes, be sure to make those changes.

4. **Building Your Plugin**

   First, make sure you have set the required C++20 standard in your compiler.

   Using CMake, you can then build the plugin:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

   This process will compile your code and produce a shared library (or other relevant binary) that Endstone can load.

   **Note: If you wish to build against a specific version of Endstone, you can modify the `GIT_TAG` in
   the `CMakeLists.txt` file to point to the desired tag or commit.**

5. **Testing Your Plugin**

   Once built, copy your plugin's output binary to the `plugins` directory of your Endstone server setup. Then, start
   the server with:

   ```bash
   endstone
   ```

   Check the server logs or console to ensure your plugin loads and operates as expected.

## Documentation

For a deeper dive into the Endstone API and its functionalities, refer to the main Endstone documentation (WIP).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.