cmake_minimum_required(VERSION 3.23)

# ------------------------------------------------------------
# Project Configuration
# ------------------------------------------------------------
project(CMakeProjectMaker
    VERSION 0.1.0
    DESCRIPTION "Simplify CMake Setup And Configuration For Complexe Projects"
    HOMEPAGE_URL "https://github.com/trenaud5298/CPM"
    LANGUAGES CXX
)

# ------------------------------------------------------------
# Global Build Settings
# ------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build Directory Setup
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # executables + dlls
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # shared libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # static libs


# ------------------------------------------------------------
# Global Install Directories
# ------------------------------------------------------------
# Standard install directories (portable across platforms)
include(GNUInstallDirs)

# ------------------------------------------------------------
# External Dependencies
# ------------------------------------------------------------

# Include Dedicated .cmake Files For Each Library

# This Project Currently Is Not Planning To Use Any External Libraries

# ------------------------------------------------------------
# Subprojects / Components / Executable
# ------------------------------------------------------------

# Single Executable File Does Not Require Sub-Directory Setup
set(EXECUTABLE_NAME "cpm")

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${EXECUTABLE_NAME}
    ${SRC_FILES}
)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

#Link To Any External Libraries Here If Needed


set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    OUTPUT_NAME_DEBUG   "${EXECUTABLE_NAME}-Debug"
    OUTPUT_NAME_RELEASE "${EXECUTABLE_NAME}-Release"
    OUTPUT_NAME_RELWITHDEBINFO "${EXECUTABLE_NAME}-RelWithDebInfo"
    OUTPUT_NAME_MINSIZEREL "${EXECUTABLE_NAME}-MinSizeRel"
)

#Install Rules For Executable
install(TARGETS ${EXECUTABLE_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # for .exe/.dll on Windows, binaries on Linux
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # if it were a shared lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # if it were a static lib
)

# Install public headers (everything in include/)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

# ------------------------------------------------------------
# Packaging (CPack) | Not Yet Working On This
# ------------------------------------------------------------

        # set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
        # set(CPACK_PACKAGE_VENDOR "Tyler Renaud")
        # set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
        # set(CPACK_PACKAGE_HOMEPAGE_URL "${PROJECT_HOMEPAGE_URL}")

        # set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
        # set(CPACK_PACKAGE_CONTACT "trenaud_5298@email.ric.edu")

        # # Resource files (optional, replace with actual files if present)
        # set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
        # set(CPACK_RESOURCE_FILE_README  "${CMAKE_SOURCE_DIR}/README.md")

        # # Default generators (choose based on platform)
        # if(WIN32)
        #     set(CPACK_GENERATOR "ZIP")
        # else()
        #     set(CPACK_GENERATOR "TGZ")
        # endif()

        # include(CPack)

# -> Customize further if needed
