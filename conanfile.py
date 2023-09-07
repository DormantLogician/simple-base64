import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake

class ConfigConan(ConanFile):
    name = "sb64"
    version = "1.0"
    author = "Stephen Aaron Hannon <hannonstephen19@gmail.com>"
    license = "MIT"
    description = """Simple base 64 encoder/decoder library."""
    upload_policy = "skip"

    requires = "boost/1.83.0"
    generators = "CMakeDeps"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    exports_sources = "CMakeLists.txt", "CMakePresets.json", "LICENSE.txt", ".clang-tidy", "target/*", "util/*"

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.user_presets_path = False
        tc.generate()

    def layout(self):
        self.folders.build = os.path.join("built", "single")
        self.folders.generators = os.path.join(self.folders.build, "generators")

    def build(self):
        self.run("cmake --preset release", cwd=self.source_folder)
        self.run("cmake --build --preset release", cwd=self.source_folder)

    def package(self):
        self.run("ctest --preset release", cwd=self.source_folder)
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["sb64"]
