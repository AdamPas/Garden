# -------- Set some variables ------------ #
set(HEADERS ${CMAKE_SOURCE_DIR}/include/Garden/)
set(SOURCES Plant.cpp Garden.cpp)
# -------- Set some variables ------------ #

# Make a library
add_library(${LIBRARY_VERSIONED} STATIC ${SOURCES} ${HEADERS})

# include the files of our library and of the other packages
target_include_directories(${LIBRARY_VERSIONED} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# All users of this library will need at least C++11
target_compile_features(${LIBRARY_VERSIONED} PUBLIC cxx_std_11)