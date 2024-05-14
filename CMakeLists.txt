add_executable (stack "main.cpp" "mystack.h" "stack.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET stack PROPERTY CXX_STANDARD 20)
endif()
