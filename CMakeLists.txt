cmake_minimum_required(VERSION 3.10)
project(InventoryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

# Add the source files
add_executable(Inventory 
        main.cpp 
        ./src/Store.cpp
        ./src/Admin.cpp 
        ./src/Customer.cpp)

# # Add Google Test
# add_subdirectory(googletest)
# include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)

# # Link the test executable with Google Test libraries
# add_executable(runTests 
#         Test.cpp
#         # ./Test/InventoryTest.cpp
#         ./src/Store.cpp
#         ./src/Admin.cpp 
#         ./src/Customer.cpp)

# target_link_libraries(runTests gtest gtest_main)

# If you want to run using g++
# g++ -std=c++17 -o Inventory main.cpp ./src/Admin.cpp ./src/Store.cpp ./src/Customer.cpp
