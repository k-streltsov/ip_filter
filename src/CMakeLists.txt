add_library(byte_parser STATIC byte_parser.cpp)
target_include_directories(byte_parser PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_library(ip_parser STATIC ip_parser.cpp ipv4.cpp)
target_link_libraries(ip_parser PUBLIC byte_parser)

add_library(input_reader STATIC input_reader.cpp)
target_link_libraries(input_reader PUBLIC ip_parser)

add_executable(ip_filter main.cpp)
target_link_libraries(ip_filter PUBLIC input_reader)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT dywedodd@gmail.com)

include(CPack)