cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(torchtest)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(torchtest main.cpp)
target_link_libraries(torchtest "${TORCH_LIBRARIES}")
set_property(TARGET torchtest PROPERTY CXX_STANDARD 17)

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET torchtest
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:torchtest>)
endif (MSVC)
