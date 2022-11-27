

include_directories("C:/Boost/include/boost-1_79/")

file(GLOB CPP-SRC-LIST *.cpp)
foreach(src ${CPP-SRC-LIST})
    message(${src})
    string(REGEX MATCH "boost.geometry/.*" relative_path ${src})
    string(REGEX REPLACE "boost.geometry/" "" target_name ${relative_path})
    message(${target_name})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})
    message(${target_name})
    add_executable(${target_name} ${src})
endforeach()