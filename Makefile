memcopy_benchmark: memcpy_benchmark.cc
	# gcc -g -O0 -fsanitize=address -msse memcpy_benchmark.cc -o benchmark
	gcc -O3 -msse2 memcpy_benchmark.cc -o benchmark

all:
	memcopy_benchmark
