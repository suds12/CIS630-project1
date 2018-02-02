GCC=mpic++

all: Final_PageRank.cpp
	$(GCC) ./Final_PageRank.cpp -o main  

 
run: main 
	mpiexec -np 4 main test1.txt test1_details 5 4

