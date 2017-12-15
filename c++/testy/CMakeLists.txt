project (testy)

cmake_minimum_required(VERSION 3.5)

if(MSVC)
    set(IDIRS $ENV{HOMEPATH}/apps/capnproto/include)
endif()
if(UNIX)
    set(IDIRS $$ENV{HOME}/apps/capnproto/include)
endif()

include_directories(
    ${IDIRS}
)

if(MSVC)
     set(LDIRS $ENV{HOMEPATH}/apps/capnproto/lib)
endif()
if(UNIX)
     set(LDIRS $$ENV{HOME}/apps/capnproto/lib)
endif()

link_directories(
    ${LDIRS}
)

set(HEADER_FILES
    myproto.cp.h
)

set(SOURCE_FILES
    main.cpp

    myproto.cp.c++
)

if(UNIX)
    add_compile_options(-std=c++11)
endif(UNIX)

add_executable(testy ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(testy capnp kj capnp-json kj-async)