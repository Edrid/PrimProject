cmake_minimum_required(VERSION 3.7)
project(Prim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=8 -I/usr/local/include/ImageMagick-7 -L/usr/local/lib")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ImageElaborator.cpp ImageElaborator.h FilterApplyer.cpp FilterApplyer.h KernelFilter.cpp KernelFilter.h)
add_executable(Prim ${SOURCE_FILES})

target_link_libraries (Prim -lMagick++-7.Q8 -lMagickWand-7.Q8 -lMagickCore-7.Q8)