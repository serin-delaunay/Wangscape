set(tst-src
    main.cpp
    TestMetaOutput.cpp
    TestOptions.cpp
    TestTilePartitionGradient.cpp
    TestTilePartitionSquares.cpp
    TestTilesetGenerator.cpp)

add_executable(WangscapeTest ${tst-src})

include_directories(${PROJECT_SOURCE_DIR}/Wangscape)
target_link_libraries(WangscapeTest wangscape)

find_package(GTest REQUIRED)
if(GTest_FOUND)
    include_directories(${GTest_INCLUDE_DIR})
    target_link_libraries(WangscapeTest ${GTEST_BOTH_LIBRARIES})
endif()

find_package(Boost COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})
    target_link_libraries(WangscapeTest ${Boost_LIBRARIES})
endif()

find_package(SFML 2 REQUIRED system graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(WangscapeTest ${SFML_LIBRARIES})
endif()