project(qecs_example)

add_executable(qecs_example example.cpp)
target_link_libraries(qecs_example PRIVATE qecs)