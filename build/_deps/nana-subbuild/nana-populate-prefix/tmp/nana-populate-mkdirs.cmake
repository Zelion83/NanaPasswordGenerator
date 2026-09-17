# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-src")
  file(MAKE_DIRECTORY "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-src")
endif()
file(MAKE_DIRECTORY
  "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-build"
  "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix"
  "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix/tmp"
  "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix/src/nana-populate-stamp"
  "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix/src"
  "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix/src/nana-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix/src/nana-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/zelion/Documents/cpptest/PassGen/build/_deps/nana-subbuild/nana-populate-prefix/src/nana-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
