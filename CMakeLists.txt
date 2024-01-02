cmake_minimum_required(VERSION 3.15)



set(PROJECT_NAME chat) 	 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


include_directories("inc/graphic/" "inc/network" "inc/exceptions" "src/graphic/" "src/network" "src/exceptions")

set(
    SOURCES
    main.cpp
    src/graphic/input_form.cpp
    src/graphic/buttons.cpp
    src/exceptions/button_exceptions.cpp
)


set(
    HEADERS
    inc/graphic/input_form.hpp
    inc/graphic/buttons.hpp
    inc/exceptions/button_exceptions.hpp
)

add_compile_options(
    -Werror
    -Wall
    -Wextra
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)


