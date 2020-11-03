cmake_minimum_required(VERSION 3.17)
project(Project_1_B_Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_1_B_Tree main.cpp disk.cpp disk.h BTreeNode.cpp BTreeNode.h)