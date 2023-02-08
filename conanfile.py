from conans import ConanFile, CMake

class ConfigConan(ConanFile):
    name = "sb64"
    version = "1.0"
    author = "Stephen Aaron Hannon <hannonstephen19@gmail.com>"
    license = "MIT"
    description = """Simple base 64 encoder/decoder library."""

    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    tool_requires = "boost/1.81.0"
    upload_policy = "skip"

    exports_sources = "CMakeLists.txt", "CMakePresets.json", "LICENSE.txt", "target/*", "util/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["sb64"]
