#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

#include "page_rank.cpp"


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

			fout[2].open("dump/degree_dump.txt");
			for(i=0;i<50000;i++)
			{
				fout[2]<<graph.node_degree[i]<<"\n";
			}

			fout[3].open("dump/credit_dump.txt");
			for(i=0;i<=graph.largest_node;i++)
			{
				fout[3]<<i<<" "<<graph.credit[i][1]<<"\n";
			}

		
			
			
		}

		int accumulator()
		{
			read.graph_reader();
			data.get_data();
			pr.initial_credits_populator();
			pr.credits_exchanger();
			display_dump();
		}

}et;

int main()
{
	et.accumulator();
}