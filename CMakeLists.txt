project(Hexman) # the name of your project

cmake_minimum_required(VERSION 2.8.0)

find_package(Qt4 REQUIRED) # find and setup Qt4 for this project

# tell cmake to proces CMakeLists.txt in that subdirectory
#add_subdirectory(src)
ADD_SUBDIRECTORY(build)
# the next line sets up include and link directories and defines some variables that we will use.
# you can modify the behavior by setting some variables, e.g.
#   set(QT_USE_OPENGL TRUE)
# -> this will cause cmake to include and link against the OpenGL module
include(${QT_USE_FILE})
# see http://cmake.org/cmake/help/cmake2.6docs.html#module:FindQt4 for a complete list

# the variable "Hexman_SRCS" contains all .cpp files of this project
set(Hexman_SRCS main.cpp  hexmanwindow.cpp)

# tell cmake to create .moc files for all files in the variable Hexman_SRCS that require such a file.
# note: this assumes that you use #include "header.moc" in your files
#qt4_automoc(${Hexman_SRCS})

SET( Hexman_UIS 
    hexmanwindow.ui
    )
SET( Hexman_MOC_HEADERS
    hexmanwindow.h
    )

QT4_WRAP_UI(Hexman_UIS_H ${Hexman_UIS})
QT4_WRAP_CPP (Hexman_MOC_HEADERS ${Hexman_MOC_HEADERS})

# Don't forget to include output directory, otherwise
# the UI file won't be wrapped!
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#Now add these generated files to the ADD_EXECUTABLE step
# If this is NOT done, then the ui_*.h files will not be generated
add_executable(Hexman ${Hexman_SRCS} ${Hexman_UIS_H} ${Hexman_MOC_HEADERS})

# link the "Hexman" target against the Qt libraries. which libraries exactly, is defined by the "include(${QT_USE_FILE})" line above, which sets up this variable.
target_link_libraries(Hexman ${QT_LIBRARIES})

