/*
 * graph.h
 *
 *  Created on: Nov 8, 2018
 *      Author: Chris
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct node
{
	int start;
	int end;
	int distance;
	bool discEdge;
	node *next;
};

struct cityNode
{
	string city;
	bool visited;
};


class graph
{
private:
	vector<cityNode> vertex;
	vector<node> edge{vector<node>(11)};
	int distancetraveled;
	int count;


public:

	graph();
	~graph();
	void insertVertex(string city);
	void insertedge(int start, int end, int distance);
	void displayVertex();
	void displayEdges(int x);
};


graph::graph()
{
	distancetraveled = 0;
	count = 0;

}

graph::~graph()
{
	distancetraveled = 0;
	count = 0;
}

void graph::displayEdges(int x)
{

	cout << edge.at(x).next->distance;

}
void graph::insertedge(int start, int end, int distance)
{
	node* temp = new node;
	temp->start = start;
	temp->end = end;
	temp->distance = distance;
	temp->discEdge = false;
	temp->next = NULL;

	if(count == 0)
	{
		edge.at(start).next = temp;
		cout << "\n\n" << edge.at(start).next->distance << "\n\n" ;
		count ++;
	}
	delete(temp);
}

void graph::insertVertex(string city)
{
	cityNode temp;
	temp.city = city;
	temp.visited = false;

	vertex.push_back(temp);
}

void graph::displayVertex()
{
	for(unsigned int i=0; i <= vertex.size()-1; i++)
	{
		cout << "Element [" << i+1 << "]" << vertex.at(i).city << endl;
	}

}






















#endif /* GRAPH_H_ */
