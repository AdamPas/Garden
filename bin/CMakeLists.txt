
# create the executable target
add_executable(app ver2.cpp)

# for running the app code, min version of C++
target_compile_features(app PRIVATE cxx_std_11)

# link my library
target_link_libraries(app PRIVATE ${LIBRARY_VERSIONED})
