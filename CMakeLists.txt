# Set the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the C++ standard
project(InventoryManagementSystem VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable target called "InventoryApp" to be built from the specified source files
add_executable(InventoryApp main.cpp Customer.cpp Admin.cpp)

# If there are specific compiler flags you want to use:
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(InventoryApp PRIVATE -Wall -Wextra -pedantic)
endif()

# If you need to link against any libraries:
# target_link_libraries(InventoryApp name_of_library)
