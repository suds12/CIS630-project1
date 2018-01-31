#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
#include "basic.hpp"



class reader 	
{

	public:

		 	

		int graph_reader()
		{
			int i=0,x,j=0,flag=1;
			fin[0].open(input.filename.c_str());
			
			
			while(!fin[0].eof())
			{
				graph.input_graph.push_back(vector<int>());
				for(i=0;i<2;i++)
				{
					fin[0]>>x;
					 graph.input_graph[j].push_back(x); 
				}
				j++;
			}
			fin[0].close();
			
			j=0;
			fin[1].open(input.details.c_str());
			while(!fin[1].eof())
			{
				graph.input_details.push_back(vector<int>());
				for(i=0;i<3;i++)
				{
					fin[1]>>x;
					 graph.input_details[j].push_back(x); 
				}

				//graph.input_details[j].push_back(0);      // Creating place holder column count of relevant edges

				j++;
			}

			graph.number_of_rows=graph.input_graph.size();//Finding size
			graph.number_of_rows--;  //Adjusting index
			graph.number_of_nodes=graph.input_details.size();//Finding size
			graph.number_of_nodes--; // Adjusting index
			
			

			for(i=0;i<number_of_partitions;i++)				//populating initial count of relevating edges of each node to 0 
			{
				graph.relevant_edges.push_back(vector<int>());
				graph.relevant_edges[i].push_back(0);
			}
			
			
	}	
}read;



