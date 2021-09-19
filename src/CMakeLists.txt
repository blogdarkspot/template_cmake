set(LIB_NAME sample)

add_library(${LIB_NAME})
target_sources(${LIB_NAME} PRIVATE sample.cpp)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)