cmake_minimum_required(VERSION 3.20)

project(BlackJack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

file(GLOB_RECURSE SOURCES "./BlackJack/src/*.cpp")
file(GLOB_RECURSE HEADERS "./BlackJack/lib/*.h")

include_directories("./vendor/raylib/include" "./BlackJack/src" "./BlackJack/lib")
link_directories("./vendor/raylib/lib" "./BlackJack/lib")

add_executable(BlackJack ${SOURCES} ${HEADERS}
        lib/precompile.h
        src/app.cpp
        lib/app.h
        lib/precompile.h
        src/main.cpp
        src/Deck.cpp
        lib/Deck.h
)
set_target_properties(BlackJack PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(BlackJack PUBLIC raylibdll)

add_custom_command(TARGET BlackJack POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_SOURCE_DIR}/vendor/raylib/lib/raylib.dll"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

target_compile_definitions(BlackJack PRIVATE $<$<CONFIG:Debug>:OD_DEBUG>)
target_compile_options(BlackJack PRIVATE $<$<CONFIG:Debug>:-g>)

target_compile_definitions(BlackJack PRIVATE $<$<CONFIG:Release>:OD_RELEASE>)
target_compile_options(BlackJack PRIVATE $<$<CONFIG:Release>:-O3>)