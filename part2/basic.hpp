#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#pragma once
#define number_of_partitions 4
#define number_of_rounds 3

using namespace std;

ifstream fin[20];
ofstream fout[20];

class basic_details
{
public:
	int number_of_rows;
	int number_of_nodes;
	int largest_node;
	int largest_partition;
	int current_round;
	float **credit = nullptr;
	vector <int> node_degree;
	//vector <vector <float> > credit;
	vector <vector <int> > input_graph;			//edge list
	vector <vector <int> > input_details;		//node list
	vector <vector <int> > relevant_edges;		//partition list
	vector <vector <int> > relevant_partitions; //node list


	basic_details()
	{
		largest_partition=0;
		current_round=1;
		largest_node=0;
		node_degree.reserve(50000000);
		relevant_edges.reserve(5000);
		relevant_partitions.reserve(500000);
	}

}graph;


class input_parameters
{
public:
	string filename;
	string details;
	//int number_of_rounds;
}input;