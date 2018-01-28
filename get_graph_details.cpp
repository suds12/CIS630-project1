#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

#include "reader.cpp"

class details_collector
{
public:
	int get_data()
	{
		int i=0,j;

		graph.number_of_rows=graph.input_graph.size();
		while(i<graph.number_of_rows)
		{
			for(j=0;j<2;j++)
			{
				
				graph.node_degree[graph.input_graph[i][j]]++;   //Find degree

				if(graph.input_graph[i][j]>graph.largest_node)	
				{
					graph.largest_node=graph.input_graph[i][j];	//Find largest node
				}
			}
			i++;
		}
	}

}data;