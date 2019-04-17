# Add googletest comes from parent friendappbase
add_executable(DDS_Linker_Test src/main.cpp src/Base_test.cpp)
target_compile_features(DDS_Linker_Test PRIVATE cxx_auto_type)
target_link_libraries(DDS_Linker_Test gtest_main gmock Friend::DDSLinker)
