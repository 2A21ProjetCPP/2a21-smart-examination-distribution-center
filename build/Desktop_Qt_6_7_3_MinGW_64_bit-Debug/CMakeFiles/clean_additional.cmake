# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Q_employer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Q_employer_autogen.dir\\ParseCache.txt"
  "Q_employer_autogen"
  )
endif()
