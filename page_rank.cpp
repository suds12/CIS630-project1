#include<iostream>
#include<fstream>
#include<vector>
#include<string>
//#define number_of_rounds 5

#include "get_graph_details.cpp"

using namespace std;

ifstream fin1;
ofstream fout2;

class pr_algorithm
{
public:

	int initial_credits_populator()
	{
		int i,j,count=0;
		
		for(i=0;i<=graph.largest_node;i++)
		{
			graph.credit.push_back(vector<float>());
			graph.credit[i].push_back(1);
			//cout<<graph.credit[graph.input_graph[i][1]][graph.current_round-1];
		}
		//cout<<graph.input_graph[4][1];
		//cout<<graph.credit[5][graph.current_round-1];
	}

	int credits_exchanger()
	{
		int i,j;
		
		vector <int> visited;
		for(i=0;i<graph.number_of_rows;i++)
		{

			graph.credit[graph.input_graph[i][0]][graph.current_round] += (graph.credit[graph.input_graph[i][1]][graph.current_round-1]/graph.node_degree[graph.input_graph[i][1]]);
			graph.credit[graph.input_graph[i][1]][graph.current_round] += (graph.credit[graph.input_graph[i][0]][graph.current_round-1]/graph.node_degree[graph.input_graph[i][0]]);
		}
			
	}
}pr;

