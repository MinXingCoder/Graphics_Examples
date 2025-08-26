file(GLOB_RECURSE GPU ./ *.cpp *.h)
add_library(gpulib STATIC ${GPU})
target_include_directories(gpulib PUBLIC .)