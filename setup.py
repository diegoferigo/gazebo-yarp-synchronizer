import os
from setuptools import setup
from cmake_build_extension import BuildExtension, CMakeExtension

# Read the contents of your README file
this_directory = os.path.abspath(os.path.dirname(__file__))
with open(os.path.join(this_directory, "README.md"), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name="gazebo_python_synchronizer",
    author="Diego Ferigo",
    author_email="diego.ferigo@iit.it",
    description="Synchronization between Python and Gazebo Classic via YARP.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/diegoferigo/gazebo-python-synchronizer",
    keywords="gazebo classic simulator simulations robot robotics yarp",
    license="MIT",
    platforms="any",
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Operating System :: OS Independent",
        "Operating System :: POSIX :: Linux",
        "Operating System :: MacOS",
        "Operating System :: Microsoft :: Windows",
        "Topic :: Games/Entertainment :: Simulation",
        "Framework :: Robot Framework",
        "Intended Audience :: Science/Research",
        "Intended Audience :: Developers",
        "Intended Audience :: Education",
        "Programming Language :: C++",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3 :: Only",
        "License :: OSI Approved :: MIT License",
    ],
    use_scm_version=dict(local_scheme="dirty-tag"),
    setup_requires=[
        "setuptools_scm",
        "cmake",
        "ninja",
        "cmake-build-extension",
        "pybind11",
    ],
    python_requires='>=3.7',
    install_requires=[],
    ext_modules=[
        CMakeExtension(name='InstallAllTargets',
                       install_prefix="gazebo_python_synchronizer",
                       cmake_depends_on=["pybind11"],
                       disable_editable=True,
                       cmake_configure_options=[
                           "-DGPS_CALL_FROM_SETUP_PY:BOOL=ON",
                       ])],
    cmdclass=dict(build_ext=BuildExtension),
    zip_safe=False,
)
