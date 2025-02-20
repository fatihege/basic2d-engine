find_package(GTest CONFIG REQUIRED)

add_executable(tests
        test_main.cpp
        test_Logger.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main basic2d_engine_lib)
