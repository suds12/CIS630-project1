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
	vector <int> node_degree;
	vector <vector <int> > input_graph;

	basic_details()
	{
		node_degree.reserve(50000);
	}

}graph;