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

project (capnsamples)

cmake_minimum_required(VERSION 3.5)

if(MSVC)
    set(IDIRS $ENV{HOMEPATH}/apps/capnproto/include)
    set(LDIRS $ENV{HOMEPATH}/apps/capnproto/lib)
endif()
if(UNIX)
    add_compile_options(-std=c++11)
    set(IDIRS $ENV{HOME}/apps/capnproto/include)
    set(LDIRS $ENV{HOME}/apps/capnproto/lib)
endif()

include_directories(${IDIRS})
link_directories(${LDIRS})

add_subdirectory(c++/testy)
add_subdirectory(c++/hello_capn)