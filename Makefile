test: test.o tmanip.h
	g++ -std=c++17 -Wall  test.cpp -o test

run: test
	./test

clean:
	rm test
	rm test.o
