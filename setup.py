import sys

import cmake_build_extension
import setuptools


setuptools.setup(
    ext_modules=[
        cmake_build_extension.CMakeExtension(
            name="InstallAllTargets",
            install_prefix="gazebo_yarp_synchronizer",
            cmake_depends_on=["pybind11", "yarp", "ycm_cmake_modules"],
            disable_editable=True,
            cmake_configure_options=[
                f"-DPython3_EXECUTABLE:PATH={sys.executable}",
                "-DBUILD_SHARED_LIBS:BOOL=OFF",
                "-DGYS_CALL_FROM_SETUP_PY:BOOL=ON",
            ],
        )
    ],
    cmdclass=dict(build_ext=cmake_build_extension.BuildExtension),
)
