from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class EndstoneCppPluginRecipe(ConanFile):
    name = "endstone_cpp_plugin"
    version = "0.1.0"
    package_type = "shared-library"

    # Optional metadata
    license = "MIT-License"
    author = "Endstone Developers <hello@endstone.dev>"
    url = "https://github.com/EndstoneMC/cpp-plugin-template"
    description = "C++ plugin template for Endstone"
    topics = ("endstone", "plugin")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def requirements(self):
        # use a released version
        self.requires("endstone/1.20.51")
        # or to use a pre-release version of endstone such as 1.20.51-alpha
        # self.requires("endstone/[~1.20.51, include_prerelease]")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
