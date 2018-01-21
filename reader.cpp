#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

ifstream fin;

class reader
{

	public:

		vector <int> oned_graph;
		int graph_reader()
		{
			int i=0,x,len,flag=1;
			fin.open("facebook_combined.txt");
			
			while(fin>>x)
			{

				 oned_graph.emplace_back(x); 
			}
			
		}

		int display()
		{
			int i,j,len;

			len=oned_graph.size();

			for(i=0;i<len;i++)
			{
				cout<<oned_graph[i]<<" ";
			}
			
		}

}read;

/*
class converter
{

public:

		int input_graph[read.oned_graph.size()/2][read.oned_graph.size()/2];
		int convert_to_array()
		{
			int i,j;

			for(i=0;i<oned_graph.size();i+2)
			{
				input_graph[j][0]=oned_graph[i];
				input_graph[j][1]=oned_graph[i+1]
			}
		}

		int display()
		{
			int i,j;
			for(i=0;i<oned_graph.size()/2;i++)
			{
				for(j=0;j<oned_graph.size()/2;j++)
				{
					cout<<input_graph[i][j]<<" ";
				}
				cout<<endl;
			}
		}

}reader;
*/
int main()
{
	read.graph_reader();
	//read.convert_to_array();
	read.display();
	return 0;
}



