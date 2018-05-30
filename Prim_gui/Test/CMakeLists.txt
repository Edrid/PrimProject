cmake_minimum_required(VERSION 3.7)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=8 -I/usr/local/include/ImageMagick-7 -L/usr/local/lib")


add_subdirectory(./lib/googletest)
#add_subdirectory(./lib/googlemock)
set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(TEST_SOURCE_FILES runAllTest.cpp ConvolutionTest.cpp)
add_executable(runPrimTests ${TEST_SOURCE_FILES} )

qt5_use_modules(runPrimTests Core Widgets Gui )

target_link_libraries(runPrimTests Qt5::Core Qt5::Widgets Qt5::Gui)
target_link_libraries (runPrimTests -lMagick++-7.Q8 -lMagickWand-7.Q8 -lMagickCore-7.Q8)
target_link_libraries(runPrimTests gtest gtest_main)