cmake_minimum_required(VERSION 3.8)
project(C__11)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp parsing-txt/main.cpp structs-padding/main.cpp stl/vectors.cpp stl/lists.cpp stl/maps.cpp stl/obj_in_maps.cpp stl/multimaps.cpp stl/sets.cpp stl/stack_queues.cpp stl/other_data_types.cpp operator-overloading/overloading.cpp operator-overloading/complex_numbers.cpp operator-overloading/Complex.cpp operator-overloading/Complex.h templates/templates.cpp functions-functions/functions.cpp functions-functions/ObjectSlicing.cpp functions-functions/AbstractClass.cpp functions-functions/functors.cpp cpp-11/main.cpp cpp-11/Sugar.cpp cpp-11/Sugar.h cpp-11/Cpp11.cpp cpp-11/Cpp11.h cpp-11/ring.cpp cpp-11/ring.h functions-functions/FunctionsFunctions.cpp functions-functions/FunctionsFunctions.h cpp-11/cpp98-elision.cpp cpp-11/Cpp11Bind.cpp cpp-11/UniquePtrs.cpp picaso/src/main.cpp picaso/src/BitmapFileHeader.h picaso/src/BitmapInfoHeader.h picaso/src/Bitmap.cpp picaso/src/Bitmap.h picaso/src/Mandelbrot.cpp picaso/src/Mandelbrot.h picaso/src/Zoom.h picaso/src/ZoomList.h picaso/src/ZoomList.cpp picaso/src/Picaso.cpp picaso/src/Picaso.h picaso/src/RGB.cpp picaso/src/RGB.h)
add_executable(C__11 ${SOURCE_FILES})
