cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME "vscode-generator")
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "-Wall")

find_package(Qt5Widgets)
# find_package(Qt5 REQUIRED COMPONENTS Network)
set(TS_FILES ${PROJECT_NAME}_ja_JP.ts)

add_executable(${PROJECT_NAME}
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
)

set(EXECUTABLE_OUTPUT_PATH "../")
