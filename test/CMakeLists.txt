set(for_gtest ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_executable(byte_parser_test byte_parser_test.cpp)
target_link_libraries(byte_parser_test byte_parser ${for_gtest})

add_executable(ip_parser_test ip_parser_test.cpp)
target_link_libraries(ip_parser_test ip_parser ${for_gtest})

add_executable(input_reader_test input_reader_test.cpp)
target_link_libraries(input_reader_test input_reader ${for_gtest})

add_test(NAME byte_parser_test COMMAND byte_parser_test)
add_test(NAME ip_parser_test COMMAND ip_parser_test)
add_test(NAME input_reader_test COMMAND input_reader_test)