add_executable(run run.cpp)
target_compile_features(run PRIVATE cxx_std_14)

target_link_libraries(run PRIVATE app)
