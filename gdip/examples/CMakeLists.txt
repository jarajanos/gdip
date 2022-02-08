include_directories("../core/src")

set(CMAKE_BUILD_TYPE Debug)

add_executable(hellodubins src/hellodubins.cpp ${SOURCE_FILES} )
target_link_libraries(hellodubins opendubins_core)

install(TARGETS hellodubins DESTINATION bin)

add_executable(gdipexample src/gdipexample.cpp ${SOURCE_FILES} )
target_link_libraries(gdipexample opendubins_core)

install(TARGETS gdipexample DESTINATION bin)

add_executable(hellodubins3D src/hellodubins3D.cpp ${SOURCE_FILES} )
target_link_libraries(hellodubins3D opendubins_core)

install(TARGETS hellodubins3D DESTINATION bin)