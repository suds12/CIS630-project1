#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

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
				fout[3]<<i<<" "<<std::fixed<<graph.credit[i][input.number_of_rounds]<<"\n";
			}

		
			
			
		}

		int accumulator()
		{
			int i=0; 
			int start_s=clock();   
			
			read.graph_reader();
			data.get_data();
			pr.initial_credits_populator();
			while(i < input.number_of_rounds)
			{
				pr.credits_exchanger();
				cout<<graph.credit[graph.input_graph[1][0]][graph.current_round]<<endl;
				i++;
				graph.current_round++;
			}
			display_dump();

			int stop_s=clock();
			cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*10 << endl;
			
		}

}et;

int main(int argc, char** argv)
{
	int i;

	input.filename=argv[1];
	input.number_of_rounds=atoi(argv[2]);
	et.accumulator();
}