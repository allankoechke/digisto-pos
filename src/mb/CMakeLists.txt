
add_library(mbdigisto PRIVATE mantisbaseimpl.cpp)

target_link_libraries(digisto PRIVATE mbdigisto)
