project(Hexman) # the name of your project

cmake_minimum_required(VERSION 2.8.0)

set(CMAKE_BUILD_TYPE Debug)
#get machine
EXECUTE_PROCESS(
    COMMAND ${CMAKE_C_COMPILER} -dumpmachine
    OUTPUT_VARIABLE MACHINE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
MESSAGE(STATUS  "Machine: ${MACHINE}, void pointer size: ${CMAKE_SIZEOF_VOID_P}")
STRING(REGEX MATCH "(i?86-*)|(athlon-*)|(pentium-*)" _machine_x86 "${MACHINE}")
IF (_machine_x86)
    MESSAGE(STATUS "Found target X86")
    SET(ARCH_X86 1)
ENDIF (_machine_x86)
IF (APPLE AND CMAKE_SIZEOF_VOID_P EQUAL 8 AND ARCH_X86 EQUAL 1)
  MESSAGE(STATUS "Found Snow Leopard Target: Apple, 64 bit, X86")
  UNSET(ARCH_X86)
  SET(ARCH_X86_64 1)
  SET(APPLE_10_6_X 1 CACHE TYPE BOOL)
ENDIF (APPLE AND CMAKE_SIZEOF_VOID_P EQUAL 8 AND ARCH_X86 EQUAL 1)

#######################################################################
if (APPLE)
  set(QT_QMAKE_EXECUTABLE /Users/anders/QtSDK/Desktop/Qt/4.8.0/gcc/bin/qmake)
 
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
  set(CMAKE_CSS_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

endif (APPLE)
######################################################################

ENABLE_TESTING()
find_package(Qt4 REQUIRED) # find and setup Qt4 for this project
## google test
ADD_SUBDIRECTORY (gtest-1.6.0 test)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# tell cmake to proces CMakeLists.txt in that subdirectory
#add_subdirectory(src)
#ADD_SUBDIRECTORY(build)
# the next line sets up include and link directories and defines some variables that we will use.
# you can modify the behavior by setting some variables, e.g.
#   set(QT_USE_OPENGL TRUE)
# -> this will cause cmake to include and link against the OpenGL module
include(${QT_USE_FILE})
# see http://cmake.org/cmake/help/cmake2.6docs.html#module:FindQt4 for a complete list


# the variable "Hexman_SRCS" contains all .cpp files of this project
set(Hexman_SRCS main.cpp  hexmanwindow.cpp FileBuffer.cpp)
set(Hexman_TST ${CMAKE_SOURCE_DIR}/test/FileBuffer_test.cpp
  FileBuffer.cpp
  ${CMAKE_SOURCE_DIR}/test/Formatter_test.cpp
  Formatter.cpp 
  )

## tests
add_test(test1 tester)


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
add_executable(tester ${Hexman_TST})
# link the "Hexman" target against the Qt libraries. which libraries exactly, is defined by the "include(${QT_USE_FILE})" line above, which sets up this variable.
target_link_libraries(Hexman ${QT_LIBRARIES} )
target_link_libraries(tester ${QT_LIBRARIES} gtest gtest_main )

