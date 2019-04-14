# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
#add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
#                 ${CMAKE_BINARY_DIR}/googletest-build
#                 EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(DDS_Linker_Test src/main.cpp src/Base_test.cpp)
target_compile_features(DDS_Linker_Test PRIVATE cxx_auto_type)
target_link_libraries(DDS_Linker_Test gtest_main gmock DDSLinker::ddslinker)
