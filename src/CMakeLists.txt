include_directories(${PROJECT_SOURCE_DIR}/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

aux_source_directory(./ DIR_SOURCES)

add_executable(cppDemo ${DIR_SOURCES})


add_executable(removeDuplicates removeDuplicates.cpp)
add_executable(classtest classtest.cpp)
add_executable(containsDuplicate containsDuplicate.cpp)
add_executable(rotate rotate.cpp)
add_executable(slidingPuzzle slidingPuzzle.cpp)
add_executable(maxprofit maxprofit.cpp)

target_link_libraries(cppDemo lib)
