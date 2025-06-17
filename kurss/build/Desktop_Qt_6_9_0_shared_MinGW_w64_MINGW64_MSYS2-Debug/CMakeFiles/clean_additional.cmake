# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appkurss_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appkurss_autogen.dir\\ParseCache.txt"
  "appkurss_autogen"
  )
endif()
