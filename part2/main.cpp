#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<string.h>
#include<sstream>

#include "mpi.h"
#include "page_rank.cpp"

using namespace std;

class extra
{
public:
	int display_dump()
	{
			int i,j;
			fout[1].open("dump/input_dump.txt");
			

			for(i=0;i<graph.number_of_rows;i++)
			{
				for(j=0;j<2;j++)
				{
					fout[1]<<graph.input_graph[i][j]<<" ";
				}
				fout[1]<<"\n";
			}

			fout[2].open("dump/detail_dump.txt");
			for(i=0;i<graph.number_of_nodes;i++)
			{
				for(j=0;j<3;j++)
				{
					fout[2]<<graph.input_details[i][j]<<" ";
				}
				fout[2]<<"\n";
				//---------
			}

			int temp;
			fout[3].open("dump/relevant_edges_dump.txt");
			for(i=0;i<number_of_partitions;i++)
			{
				temp=graph.relevant_edges[i][0];
				temp++;
				fout[3]<<i<<" ";
				for(j=0;j<temp;j++)   //graph.relevant_edges[i][0]
				{
					fout[3]<<graph.relevant_edges[i][j]<<" ";
				}
				fout[3]<<"\n";
			}

			fout[4].open("dump/credit_dump.txt");
			for(i=0;i<graph.number_of_nodes;i++)
			{
				fout[4]<<i<<" "<<graph.credit[i][1]<<"\n";
			}

						
			fout[5].open("dump/relevant_partition_dump.txt");
			for(i=0;i<graph.number_of_nodes;i++)
			{
				temp=graph.relevant_partitions[i][0];
				temp++;

				fout[5]<<i<<" ";
				for(j=0;j<temp;j++)   
				{
					fout[5]<<graph.relevant_partitions[i][j]<<" ";
				}
				fout[5]<<"\n";
			}


			
			//cerr<<graph.relevant_partitions[1][2];
			
	}

	int accumulator()
		{
			int i=0; 
			int start_s=clock();   
			
			cout<<"started reading"<<endl;
			read.graph_reader();
			cout<<"started degree"<<endl;
			data.get_data();

			cout<<"started initial credits"<<endl; 
			pr.initial_credits_populator();
			/*

			while(i < input.number_of_rounds)
			{
				cout<<endl<<"started round :"<<i+1<<endl;
				pr.credits_exchanger();
				cout<<graph.credit[graph.input_graph[1][0]][graph.current_round]<<endl;
				i++;
				graph.current_round++;
			}
			
			*/
			//cout<<graph.number_of_nodes<<endl;
			
			for(i=0;i<graph.number_of_rows;i++)  
			{
				//pr.credits_exchanger(graph.input_graph[i][0],graph.input_graph[i][1],graph.current_round);	
			}


			for(i=0;i<6;i++)
			{
				cerr<<graph.credit[i][1]<<endl;
			}


			
			//pr.credits_exchanger(2,3,1);
			cout<<"started display"<<endl;
			display_dump();

			int stop_s=clock();
			cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)<< endl;
			
		}

}et;

class process_manager
{
public:
	int trigger;

	process_manager()
	{
		
		trigger=0;
		
	}
}p[number_of_partitions];

int main(int argc, char** argv)
{

	int i, j, k, l=1, tg=0, local[10];
	//string credit_filename;
	int temp[10];
	MPI_Init(&argc, &argv);
  	int world_rank,world_size;
  	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	input.filename=argv[1];
	input.details=argv[2];

	//----------------
		cout<<"started reading"<<endl;
		read.graph_reader();
		cout<<"started degree"<<endl;
		data.get_data();
		cout<<"started initial credits"<<endl; 
		pr.initial_credits_populator();
		cout<<endl<<"done"<<endl;
	//--------------------
	//input.number_of_rounds=atoi(argv[2]);
	

	while(l!=number_of_rounds)
	{

		for(i=0;i<number_of_partitions;i++)
		{
			if(world_rank==i)
			{

				for(j=1;j<=graph.relevant_edges[i][0];j++)
				{
					pr.credits_exchanger(graph.input_graph[graph.relevant_edges[i][j]][0], graph.input_graph[graph.relevant_edges[i][j]][1], 1);
					if(world_rank==0)
					{
						//cout<<endl<<graph.input_graph[graph.relevant_edges[i][j]][0]<<"exg"<<graph.input_graph[graph.relevant_edges[i][j]][1];


					}
					cout<<endl<<j<<"^^"<<i;
					
				}

				//---------------------------------------------
				
				stringstream credit_filename;
	    		credit_filename << "dump/credits_dump" << i << ".txt";
				fout[6+i].open(credit_filename.str());
				for(k=0;k<graph.number_of_nodes;k++)
				{
					//if(graph.input_details[k][2]==i)
						fout[6+i]<<k<<" **"<<graph.credit[k][1]<<"\n";
				}
				
				//MPI_Allreduce(MPI_IN_PLACE, &graph.credit, (graph.number_of_nodes*l), MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
			}
		}
		l++;
	}


	

	if(world_rank==0)
	{
		
		
		//------------------
		

		//cout<<endl<<graph.relevant_partitions[graph.input_graph[1][0]][2]<<endl;
		//cout<<endl<<graph.input_details[graph.input_graph[1][1]][2]<<endl;

		


		//MPI_Send(&tg, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
		
		//et.accumulator();
	}
	et.display_dump();


	if(world_rank==1)
	{
		//MPI_Recv(&tg, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);	

	}


	

	
	
	
	//MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
}

