GCC=mpic++ -std=c++11

all: main.cpp
	$(GCC) ./main.cpp -o main  

 
run: main 
	mpiexec -np 5 ./main test1.txt test_details.txt 5 4
