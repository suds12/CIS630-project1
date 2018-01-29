#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

#include "get_graph_details.cpp"
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
			}

			
			fout[3].open("dump/relevant_edges_dump.txt");
			for(i=0;i<number_of_partitions;i++)
			{
				fout[3]<<i<<" ";
				for(j=0;j<graph.relevant_edges[i][0];j++)   //graph.relevant_edges[i][0]
				{
					fout[3]<<graph.relevant_edges[i][j]<<" ";
				}
				fout[3]<<"\n";
			}
			
	}

	int accumulator()
		{
			int i=0; 
			int start_s=clock();   
			
			cout<<"started reading"<<endl;
			read.graph_reader();
			cout<<"started degree"<<endl;
			data.get_data();
			/*
			cout<<"started initial credits"<<endl; 
			pr.initial_credits_populator();
			while(i < input.number_of_rounds)
			{
				cout<<endl<<"started round :"<<i+1<<endl;
				pr.credits_exchanger();
				cout<<graph.credit[graph.input_graph[1][0]][graph.current_round]<<endl;
				i++;
				graph.current_round++;
			}
			*/
			cout<<"started display"<<endl;
			display_dump();

			int stop_s=clock();
			cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)<< endl;
			
		}

}et;

int main(int argc, char** argv)
{
	int i;

	input.filename=argv[1];
	input.details=argv[2];
	//input.number_of_rounds=atoi(argv[2]);
	et.accumulator();
}

