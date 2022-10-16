 include (GenerateExportHeader)
cmake_minimum_required(VERSION 3.5)

PROJECT(PrzeszukiwanieGrafu)
OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
SET (LIB_TYPE STATIC)
IF (BUILD_SHARED_LIBS)
SET (LIB_TYPE SHARED)
ENDIF (BUILD_SHARED_LIBS)
SET (sources BFS.cpp DFS.cpp General.cpp Graf.cpp main.cpp)
SET (headers BFS.h DFS.h General.h Graf.h)

add_library (PrzeszukiwanieGrafu SHARED ${sources} ${headers})

GENERATE_EXPORT_HEADER( PrzeszukiwanieGrafu
             BASE_NAME PrzeszukiwanieGrafu
             EXPORT_MACRO_NAME PrzeszukiwanieGrafu_EXPORT
             EXPORT_FILE_NAME PrzeszukiwanieGrafu_Export.h
             STATIC_DEFINE PrzeszukiwanieGrafu_BUILT_AS_STATIC
)

SET_TARGET_PROPERTIES (PrzeszukiwanieGrafu PROPERTIES DEFINE_SYMBOL  "COMPILING_DLL" )
