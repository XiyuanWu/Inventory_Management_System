# cmake_minimum_required(VERSION 3.10)
# project(YourProject)

# set(CMAKE_CXX_STANDARD 20)  # If you're using C++20 features
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Include the header directory
# include_directories(${PROJECT_SOURCE_DIR}/header)

# # Add executable
# add_executable(Inventory 
#     main.cpp
#     ./header/Inventory.h
#     ./header/Admin.h
#     ./header/Customer.h
#     ./src/Admin.cpp
#     ./src/Customer.cpp)

# # If there are specific compiler flags you want to use:
# if(CMAKE_COMPILER_IS_GNUCXX)
#     target_compile_options(Inventory PRIVATE -Wall -Wextra)
# endif()
