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
			
	}	
}read;



