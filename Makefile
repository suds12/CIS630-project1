
all: main output

main: main.cpp
	g++ main.cpp -o output.out 

output: output.out
	./output.out orkut.txt 2
