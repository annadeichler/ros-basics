cmake_minimum_required(VERSION 2.8.3)
project(note_template)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES note_template
  CATKIN_DEPENDS geometry_msgs  roscpp
  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
 add_library(${PROJECT_NAME}
   src/simple_node.cpp
 )
add_dependencies(${PROJECT_NAME} prius_generate_msgs_cpp)
add_dependencies(note_template prius_generate_msgs_cpp ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES})
add_executable(simple_node_node src/simple_node_node.cpp)
add_dependencies(simple_node_node ${simple_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
## Specify libraries to link a library or executable target against
target_link_libraries(simple_node_node
   ${PROJECT_NAME}
   ${catkin_LIBRARIES}
 )

 install(TARGETS ${PROJECT_NAME} simple_node_node
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

## Mark cpp header files for installation
 install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
 )

