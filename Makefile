test:
	c++ tests.cpp gausslib.cpp -o tests
	./tests
	rm tests || true

bench:
	c++ bench.cpp gausslib.cpp -Ofast -mavx2 -o bench
	./bench
	rm bench || true
