cmake_minimum_required(VERSION 3.8)
project(PICASO)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp src/Picaso.cpp src/Picaso.h src/BitmapFileHeader.h src/BitmapInfoHeader.h
        src/Bitmap.cpp src/Bitmap.h src/Mandelbrot.cpp src/Mandelbrot.h
        src/Zoom.h src/ZoomList.cpp src/ZoomList.h src/RGB.cpp src/RGB.h)
set(EXECUTABLE_OUTPUT_PATH bin)
add_executable(Picaso ${SOURCE_FILES})
