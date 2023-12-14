# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BitirmeOdevi_autogen"
  "CMakeFiles/BitirmeOdevi_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BitirmeOdevi_autogen.dir/ParseCache.txt"
  )
endif()
