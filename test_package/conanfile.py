import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
from conan.tools.build import can_run

class ConfigTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def requirements(self):
        self.requires(self.tested_reference_str)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.user_presets_path = False
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)

    def test(self):
        if can_run(self):
          cmd = os.path.join(self.cpp.build.bindir, "sb64_conan_package_test")
          self.run(cmd, env="conanrun")
