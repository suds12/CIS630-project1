GCC=mpic++ -std=c++11

all: main.cpp
	$(GCC) ./main.cpp -o main  

 
run: main 
	mpiexec -np 4 ./main test1.txt test_details.txt 5 4
