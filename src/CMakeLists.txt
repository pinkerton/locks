include_directories(${COMMON_INCLUDES})

# Library
add_library(${PROJECT_NAME} ${SOURCES})

# target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)
# or
# add_library(lib${PROJECT_NAME} ${PROJECT_NAME}.c)
# or
#file(GLOB SOURCES "*.c")

# Main executable
add_executable(run_${PROJECT_NAME} main.c) # or ${SOURCES}?
target_link_libraries(run_${PROJECT_NAME} ${PROJECT_NAME})
