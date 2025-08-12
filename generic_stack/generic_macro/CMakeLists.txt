get_filename_component(DIR_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
add_executable(stack_${DIR_NAME} example.c stack.c)

