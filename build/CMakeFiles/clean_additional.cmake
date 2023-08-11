# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/vscode-generator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/vscode-generator_autogen.dir/ParseCache.txt"
  "vscode-generator_autogen"
  )
endif()
