add_executable (stack "main.cpp" "main.h" "stack.cpp" "stack.h" "mystack.cpp" "mystack.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET stack PROPERTY CXX_STANDARD 20)
endif()
