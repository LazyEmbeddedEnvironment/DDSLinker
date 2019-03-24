cmake_minimum_required(VERSION 3.5)
project(libddslinker VERSION 1.0.0 LANGUAGES CXX)

#Make sure that custom modules like FindRapidJSON are found
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

##############################################
# Declare dependencies
find_package(Boost 1.55 REQUIRED COMPONENTS regex)
find_package(RapidJSON 1.0 REQUIRED MODULE)
find_package(YARP REQUIRED)

##############################################
# Create target and set properties

add_library(ddslinker
        src/Input.cpp
        src/Base.h include/ddslinker/GetTypeName.h)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(DDSLinker::ddslinker ALIAS ddslinker)

#Set target properties
target_include_directories(ddslinker
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(ddslinker PRIVATE cxx_std_17)
target_compile_options(ddslinker PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

target_link_libraries(ddslinker
    PUBLIC
        Boost::boost RapidJSON::RapidJSON
    PRIVATE
        Boost::regex
        ${YARP_LIBRARIES}
)

##############################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/DDSLinker)

install(TARGETS ddslinker
    EXPORT ddslinker-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#This is required so that the exported target has the name DDSLinker and not ddslinker
set_target_properties(ddslinker PROPERTIES EXPORT_NAME DDSLinker)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT ddslinker-targets
  FILE
    DDSLinkerTargets.cmake
  NAMESPACE
    DDSLinker::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/DDSLinkerConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/DDSLinkerConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/DDSLinkerConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_LIST_DIR}/cmake/FindRapidJSON.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DDSLinkerConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DDSLinkerConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##############################################
## Exporting from the build tree
configure_file(${CMAKE_CURRENT_LIST_DIR}/cmake/FindRapidJSON.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/FindRapidJSON.cmake
    COPYONLY)

export(EXPORT ddslinker-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/DDSLinkerTargets.cmake NAMESPACE DDSLinker::)

#Register package in user's package registry
export(PACKAGE DDSLinker)

add_subdirectory(test)
