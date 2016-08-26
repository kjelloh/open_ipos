cmake_minimum_required(VERSION 3.5)
set (This_Project "open_ipos")
project(${This_Project})

# Console target definitions
set (This_App ${This_Project}_app)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CONSOLE_SOURCE_FILES 
    src/app/main.cpp
	src/app/OpeniPosFrontEnd.cpp
	src/app/OpeniPosFrontEnd.h
	# tris sub-module (frontend, core, backend idiom)    
    src/external/tris/build/src/Active.cpp
    src/external/tris/build/src/Active.h
    src/external/tris/build/src/BackEnd.cpp
    src/external/tris/build/src/BackEnd.h
    src/external/tris/build/src/Core.cpp
    src/external/tris/build/src/Core.h
    src/external/tris/build/src/FrontEnd.cpp
    src/external/tris/build/src/FrontEnd.h
    )
add_executable(${This_App} ${CONSOLE_SOURCE_FILES})

# Library target definition
set (This_Api ${This_Project}_api)
include (GenerateExportHeader)
set(API_SOURCE_FILES 
	src/api/dllmain.cpp 
	src/api/iPOSApiImpl.cpp
	src/api/iPOSApiImpl.h
    src/api/iPOSApiImpl.def
	src/api/APIFiniteStateMachine.cpp
	src/api/APIFiniteStateMachine.h
	src/api/ZeposApiCore.cpp
	src/api/ZeposApiCore.h
	# tris Core, Backend idiom classes
    src/external/tris/build/src/Active.cpp
    src/external/tris/build/src/Active.h
    src/external/tris/build/src/BackEnd.cpp
    src/external/tris/build/src/BackEnd.h
    src/external/tris/build/src/Core.cpp
    src/external/tris/build/src/Core.h
	)
add_library(${This_Api} SHARED ${API_SOURCE_FILES})
GENERATE_EXPORT_HEADER( ${This_Api}
             BASE_NAME ${This_Api}
             EXPORT_MACRO_NAME ${This_Api}_EXPORT
             EXPORT_FILE_NAME ${This_Api}_Export.h
             STATIC_DEFINE ${This_Api}_BUILT_AS_STATIC)
include_directories(src/external)

