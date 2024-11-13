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

    requires = "boost/1.86.0"
    generators = "CMakeDeps"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": False}

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
        self.folders.source = "."
        self.folders.build = os.path.join("built", self.settings.get_safe("build_type"))
        self.folders.generators = os.path.join(self.folders.build, "generators")

    def build(self):
        # Map CMake configurations to CMake presets so presets can be used with Conan.
        chosen_preset = self.settings.get_safe("build_type", default="default").lower()

        self.run("cmake --preset %s" % (chosen_preset), cwd=self.source_folder)
        self.run("cmake --build --preset %s" % (chosen_preset), cwd=self.source_folder)

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["sb64"]
