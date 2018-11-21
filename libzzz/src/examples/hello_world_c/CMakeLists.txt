#
# Locate project sources
#
FILE (GLOB_RECURSE eg_hello_world_c_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

#
# Configure common project settings
#
SET (eg_hello_world_c_LIBS ${PROJECT_NAME} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

#
# Executable build rules
#
ADD_EXECUTABLE (eg_hello_world_c ${eg_hello_world_c_SRCS})
TARGET_LINK_LIBRARIES (eg_hello_world_c ${eg_hello_world_c_LIBS})
INSTALL (TARGETS eg_hello_world_c DESTINATION bin)
