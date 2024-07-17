# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\Condottiere-_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Condottiere-_autogen.dir\\ParseCache.txt"
  "Condottiere-_autogen"
  )
endif()
