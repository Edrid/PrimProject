cmake_minimum_required(VERSION 3.7)
project(Prim_gui)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

#imgmagick
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=8 -I/usr/local/include/ImageMagick-7 -L/usr/local/lib")


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#find_package( Qt5Core REQUIRED )
#find_package( Qt5Widgets REQUIRED )
#find_package( Qt5Gui REQUIRED )

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(SOURCE_FILES
        main.cpp
        MVC_view/mainwindow.cpp
        MVC_view/mainwindow.h
        MVC_view/mainwindow.ui
        MVC_view/Prim_gui.pro
        MVC_view/Prim_gui.pro.user
        MVC_model/ImageElaborator.cpp MVC_model/ImageElaborator.h MVC_model/FilterApplyer.cpp MVC_model/FilterApplyer.h MVC_model/KernelFilter.cpp MVC_model/KernelFilter.h MVC_model/GaussianBlur.cpp MVC_model/GaussianBlur.h MVC_model/EdgeDetection.cpp MVC_model/EdgeDetection.h MVC_model/UndoManager.cpp MVC_model/UndoManager.h
        MVC_interfaces/Observer.h MVC_interfaces/Subject.h MvcController.cpp MvcController.h MVC_model/Sharpen.cpp MVC_model/Sharpen.h MVC_model/Emboss.cpp MVC_model/Emboss.h FileSelector.cpp FileSelector.h)


add_executable(Prim_gui ${SOURCE_FILES})


qt5_use_modules( Prim_gui Core Widgets Gui )

target_link_libraries(Prim_gui Qt5::Core Qt5::Widgets Qt5::Gui)

target_link_libraries (Prim_gui -lMagick++-7.Q8 -lMagickWand-7.Q8 -lMagickCore-7.Q8)