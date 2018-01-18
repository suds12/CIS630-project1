#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

ifstream fin;

class read
{

	public:
		
		int graph_reader()
		{
			int i=0,x,len;
			vector <int> oned_graph;
			fin.open("test_input1.txt");
			if (!fin)
		       	{
				cerr << "Unable to open file datafile.txt";
			        exit(1);   // call system to stop
			}
			while(fin>>x)
			{
				 oned_graph.push_back(x);
								 
			}
		}
		
		int input_graph[oned_graph.size()/2][oned_graph.size()/2];
		int convert_to_array()
		{
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

int main()
{
	reader.graph_reader();
	reader.convert_to_array();
	reader.display();
	return 0;
}



