find_package(GTest CONFIG REQUIRED)

target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main basic2d_engine_lib)
