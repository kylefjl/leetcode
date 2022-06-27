cmake_minimum_required(VERSION 3.13)
project(cppDemo)

set(CMAKE_CXX_STANDARD 14)

function(include_sub_directories_recursively ROOT_DIR)
    if (IS_DIRECTORY ${ROOT_DIR})
        message("include dir: " ${ROOT_DIR})
        include_directories(${ROOT_DIR})
    endif ()

    file(GLOB ALL_SUB RELATIVE ${ROOT_DIR} ${ROOT_DIR}/*)
    foreach (SUB ${ALL_SUB})
        if (IS_DIRECTORY ${ROOT_DIR}/${SUB})
            include_sub_directories_recursively(${ROOT_DIR}/${SUB})
        endif ()
    endforeach ()
endfunction()

include_sub_directories_recursively(${PROJECT_SOURCE_DIR})

add_subdirectory(lib)
add_subdirectory(src)
