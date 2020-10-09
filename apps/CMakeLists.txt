add_executable(rabbit-seq rabbit-seq.cpp)
target_compile_features(rabbit-seq PRIVATE cxx_std_17)

target_link_libraries(rabbit-seq PRIVATE rseq_library)
