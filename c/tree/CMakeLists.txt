cmake_minimum_required(VERSION 3.17)
project(ITree_01 LANGUAGES C)

enable_testing()

add_executable(ITree_01
    Test_ITree_01.c
)
set_property(TARGET ITree_01 PROPERTY C_STANDARD 11)

target_compile_definitions(ITree_01 PUBLIC __ISOC11_SOURCE)
target_link_libraries(ITree_01 PRIVATE $<TARGET_OBJECTS:ITree>)
target_link_libraries(ITree_01 PRIVATE $<TARGET_OBJECTS:IList2d>)

add_library( ITree OBJECT ./ITree_01.c)
add_library( IList2d OBJECT ./IList2d.c)
list(APPEND my_objects
    ITree
    IList2d
)

foreach(my_object IN LISTS ${my_objects})
    set_property(TARGET ${my_object} PROPERTY C_STANDARD 11)
    target_compile_definitions(${my_object} PUBLIC __ISOC11_SOURCE)
endforeach()