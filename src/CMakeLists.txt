############### LIB ########################################################

set(LIB_NAME sample)

add_library(${LIB_NAME})
target_sources(${LIB_NAME} PRIVATE sample.cpp)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)

add_library(template::sample ALIAS ${LIB_NAME})


################ EXE #######################################################

set(EXEC_NAME sample.bin)
add_executable(${EXEC_NAME})
target_sources(${EXEC_NAME} PRIVATE main.cpp)
target_link_libraries(${EXEC_NAME} template::sample)

