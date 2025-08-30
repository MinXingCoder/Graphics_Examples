file(GLOB_RECURSE GPU ./ *.cpp *.h)
add_library(gpulib STATIC ${GPU}
        raster.h
        raster.cpp)
target_include_directories(gpulib PUBLIC .)