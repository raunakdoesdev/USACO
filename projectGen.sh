#!/bin/bash
echo Please enter your task name:
read taskName
mkdir $taskName
cd $taskName
cat > CMakeLists.txt <<- EOM
cmake_minimum_required(VERSION 3.5)
project($taskName)

set(CMAKE_CXX_FLAGS "\${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES $taskName.cpp)
add_executable($taskName \${SOURCE_FILES})
EOM
cat > $taskName.cpp <<- EOM
/*
ID: sauhaar1
PROG: $taskName
LANG: C++
*/

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>

using namespace std;

int main() {

    ofstream cout ("$taskName.out");
    ifstream cin ("$taskName.in");

    return 0;
}
EOM
cmake .
make
touch $taskName.in
