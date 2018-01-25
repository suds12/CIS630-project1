#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#pragma once

using namespace std;

ifstream fin[5];
ofstream fout[5];

class basic_details
{
public:
	int number_of_rows;
	int largest_node;
	int current_round;
	vector <int> node_degree;
	vector <vector <float> > credit;
	vector <vector <int> > input_graph;

	basic_details()
	{
		current_round=1;
		largest_node=0;
		node_degree.reserve(50000);
	}

}graph;