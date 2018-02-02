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
			
			
			if(graph.input_details[graph.input_graph[i][0]][2] == graph.input_details[graph.input_graph[i][1]][2]) //Finding relevant edges to each partition
			{

				//cout<<endl<<"edge no : "<<i<<" **"<<graph.input_details[graph.input_graph[i][0]][0];
				graph.relevant_edges[graph.input_details[graph.input_graph[i][0]][2]].push_back(i);
				graph.relevant_edges[graph.input_details[graph.input_graph[i][0]][2]][0]++;
				
			}
			
			else																			//Using if block so that each unique partition gets the edge only once
			{
				graph.relevant_edges[graph.input_details[graph.input_graph[i][0]][2]].push_back(i);	
				graph.relevant_edges[graph.input_details[graph.input_graph[i][0]][2]][0]++;	
				graph.relevant_edges[graph.input_details[graph.input_graph[i][1]][2]].push_back(i);
				graph.relevant_edges[graph.input_details[graph.input_graph[i][1]][2]][0]++;
			}
			

			

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
		

		i=0,j=0;
		
		/*
		while(i < graph.number_of_nodes)
		{
			for(j=0;j<3;j++)
			{

		}
		*/
	}

}data;