.PHONY: clean

all: 431project.cpp 431project.h 431projectUtils.cpp YOURCODEHERE.cpp
	rm -rf DSE
	g++ -O3 431project.cpp 431projectUtils.cpp YOURCODEHERE.cpp -lm -o DSE

DSE: 431project.cpp 431project.h 431projectUtils.cpp YOURCODEHERE.cpp
	g++ -O3 431project.cpp 431projectUtils.cpp YOURCODEHERE.cpp -lm -o DSE

clean:
	rm -rf DSE

testclean:
	rm -rf TEST

test: 431project.h 431projectUtils.cpp test.cpp YOURCODEHERE.cpp YOURCODEHERE.h
	g++ -O3 431projectUtils.cpp test.cpp YOURCODEHERE.cpp -lm -o TEST
