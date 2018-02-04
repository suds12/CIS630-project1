#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<string.h>
#include<sstream>

//#include "mpi.h"
#include "page_rank.cpp"


int main(int argc, char** argv)
{
	input.filename=argv[1];
	input.details=argv[2];

	int i=0; 
			int start_s=clock();   
			
			cout<<"started reading"<<endl;
			read.graph_reader();
			cout<<"started degree"<<endl;
			data.get_data();

			cout<<"started initial credits"<<endl; 
			pr.initial_credits_populator();

			cout<<"started display"<<endl;
			//et.display_dump();

			int stop_s=clock();
			cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)<< endl;


	//pr.credits_exchanger(graph.input_graph[graph.relevant_edges[0][3]][0], graph.input_graph[graph.relevant_edges[0][3]][1], 1);
	//cout<<graph.credit[4][1]<<endl;

			for(i=0;i<number_of_partitions;i++)
	{
		if(graph.input_details==i)
		{

			for(j=1;j<graph.relevant_edges[i][0];j++)
			{
				pr.credits_exchanger(graph.input_graph[graph.relevant_edges[i][j]][0], graph.input_graph[graph.relevant_edges[i][j]][1], 1);
				//cout<<endl<<graph.input_graph[graph.relevant_edges[i][j]][0]<<" "<<graph.input_graph[graph.relevant_edges[i][j]][1];

			}

			//---------------------------------------------
			/*
			stringstream credit_filename;
    		credit_filename << "dump/credits_dump" << i << ".txt";
			fout[6+i].open(credit_filename.str());
			for(k=0;i<graph.number_of_nodes;i++)
			{
				if(graph.input_details[k][2]==i)
					fout[6+i]<<k<<" "<<graph.credit[k][1]<<"\n";
			}
			*/
			
			
		}
	}
}