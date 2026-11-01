cmake_minimum_required(VERSION 3.16)

option(USE_CLANG "Build using Clang instead of the default compiler" OFF)
if(USE_CLANG)
  find_program(CLANG_C_COMPILER NAMES clang)
  find_program(CLANG_CXX_COMPILER NAMES clang++)
  if(CLANG_C_COMPILER AND CLANG_CXX_COMPILER)
    set(CMAKE_C_COMPILER "${CLANG_C_COMPILER}")
    set(CMAKE_CXX_COMPILER "${CLANG_CXX_COMPILER}")
  else()
    message(WARNING "USE_CLANG requested but clang/clang++ was not found; falling back to the default compiler")
  endif()
endif()

project(MarkdownToHTML VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

option(ENABLE_CLANG_TIDY "Run clang-tidy during the build" ON)
if(ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
  else()
    message(WARNING "clang-tidy requested but not found; skipping")
  endif()
endif()

file(GLOB_RECURSE PROJECT_SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx"
)

if(NOT PROJECT_SOURCE_FILES)
  message(FATAL_ERROR "No source files were found in ${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()

set(PROJECT_MAIN_SOURCE_FILES ${PROJECT_SOURCE_FILES})
list(FILTER PROJECT_MAIN_SOURCE_FILES INCLUDE REGEX ".*/main\\.(c|cc|cpp|cxx)$")

set(PROJECT_LIBRARY_SOURCE_FILES ${PROJECT_SOURCE_FILES})
list(FILTER PROJECT_LIBRARY_SOURCE_FILES EXCLUDE REGEX ".*/main\\.(c|cc|cpp|cxx)$")

if(PROJECT_LIBRARY_SOURCE_FILES)
  add_library(${PROJECT_NAME}_lib ${PROJECT_LIBRARY_SOURCE_FILES})
  target_include_directories(${PROJECT_NAME}_lib
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/inc
    )
  target_compile_features(${PROJECT_NAME}_lib PUBLIC cxx_std_17)
endif()

if(PROJECT_MAIN_SOURCE_FILES)
  add_executable(${PROJECT_NAME} ${PROJECT_MAIN_SOURCE_FILES})
  target_include_directories(${PROJECT_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/inc
    )
  target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

  if(TARGET ${PROJECT_NAME}_lib)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)
  endif()
endif()

if(BUILD_TESTING)
  file(GLOB_RECURSE PROJECT_TEST_SOURCE_FILES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/test/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cc"
        "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cxx"
    )

  if(PROJECT_TEST_SOURCE_FILES)
    find_package(GTest REQUIRED)
    include(GoogleTest)

    add_executable(${PROJECT_NAME}_tests ${PROJECT_TEST_SOURCE_FILES})
    target_include_directories(${PROJECT_NAME}_tests
            PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/inc
        )
    target_compile_features(${PROJECT_NAME}_tests PRIVATE cxx_std_17)
    target_link_libraries(${PROJECT_NAME}_tests
            PRIVATE
                GTest::gtest
                GTest::gtest_main
        )

    if(TARGET ${PROJECT_NAME}_lib)
      target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME}_lib)
    endif()

    gtest_discover_tests(${PROJECT_NAME}_tests)
  endif()
endif()
