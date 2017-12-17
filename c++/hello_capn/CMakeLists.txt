# MIT License
# 
# Copyright (c) 2017 
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

set(TGT_NAME hello_capn)

set(HEADER_FILES
    hello.capnp.h
)

set(SOURCE_FILES
    main.cpp

    hello.capnp.c++
)

add_executable(${TGT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Take care - on Linux the order of the link dependencies seems
# to matter.  On Windows and Mac it doesn't seem to (as much).
# While not a tutorial on CMake I was recently nipped by this.
target_link_libraries(${TGT_NAME} capnp kj)

install(TARGETS ${TGT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin)
