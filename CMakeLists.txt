cmake_minimum_required(VERSION 3.10)

include( VersionFromGit.cmake )

# Use it
version_from_git(
  LOG       ON
  TIMESTAMP "%Y%m%d%H%M%S"
)

# set the project name and version
project(HelloGit VERSION ${VERSION})

set(CMAKE_BUILD_TYPE "RelWithDebInfo")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(HelloGitConfig.h.in HelloGitConfig.h)

# add the executable
add_executable(HelloGit hellogit.cc) 

# add the binary tree to the search path for include files
# so that we will find HelloGit.h
target_include_directories(HelloGit PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

install(TARGETS HelloGit DESTINATION bin/hellogit)

### GLOBAL CPACK ###
set(CPACK_GENERATOR "DEB;RPM;TGZ")
set(CPACK_PACKAGE_VERSION ${VERSION_DESCRIBE})

### DEB ###
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Anthony Gauchy") # required

### RPM ###
#set(CPACK_RPM_PACKAGE_DEBUG 1)
set(CPACK_RPM_BUILD_SOURCE_DIRS_PREFIX "/usr/src/debug/hellogit")
set(CPACK_RPM_DEBUGINFO_PACKAGE ON)


include(CPack)