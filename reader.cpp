#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

ifstream fin;
ofstream fout;
class reader 	
{

	public:

		vector <vector <int> > input_graph; 	//member variable
		int graph_reader()
		{
			int i=0,x,len,j=0,flag=1;
			fin.open("facebook_combined.txt");
			
			while(!fin.eof())
			{
				input_graph.push_back(vector<int>());
				for(i=0;i<2;i++)
				{
					fin>>x;
					 input_graph[j].push_back(x); 
				}
				j++;
			}
			
		}

		int display_dump()
		{
			int i,j,len;
			fout.open("display_dump.txt");
			len=input_graph.size();

			for(i=0;i<len;i++)
			{
				for(j=0;j<2;j++)
				{
					fout<<input_graph[i][j]<<" ";
				}
				fout<<"\n";
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
	read.display_dump();
	return 0;
}



