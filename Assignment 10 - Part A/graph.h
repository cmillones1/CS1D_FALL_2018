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
	vector<node> edge{vector<node>(12)};
	int distancetraveled;
	int count;


public:

	graph();
	~graph();
	void insertVertex(string city);
	void insertedge(int start, int end, int distance);
	void displayVertex();
	void displayEdges();
	void DFS(int startingCity);
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

void graph::displayEdges()
{

	for(unsigned int i = 0; i <= edge.size()-1; i++)
	{
		node* temp = edge.at(i).next;
		cout << "\nCity Start -> " << vertex.at(i).city;
		while(temp != NULL)
		{
			cout << "\nStart: " << temp->start;
			cout << "\nEnd: " << temp->end;
			cout << "\nDistance: " << temp->distance << endl;
			temp = temp->next;
		}
	}


}
void graph::insertedge(int start, int end, int distance)
{
	// 0, 1, 661  (ATL - > MIAMI, 661)
	node* temp = new node;
	temp->start = start;
	temp->end = end;
	temp->distance = distance;
	temp->discEdge = false;
	temp->next = NULL;



	if(edge.at(start).next == NULL)
	{
		edge.at(start).next = temp;
//		cout << "\nBEING ADDED";
//		cout << "\nStart: " << temp->start;
//		cout << "\nEnd: " << temp->end;
//		cout << "\nDistance: " << temp->distance << endl;

	}
	else
	{
		node* head = edge.at(start).next;
		while(head != NULL)
		{
			if(head->next == NULL)
			{
				head->next = temp;
//				cout << "\nBEING ADDED";
//				cout << "\nStart: " << temp->start;
//				cout << "\nEnd: " << temp->end;
//				cout << "\nDistance: " << temp->distance << endl;
				break;
			}

			head = head->next;
		}


	}
	//delete(temp);
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
		cout << "Element [" << i << "]" << vertex.at(i).city << endl;
	}

}


void graph::DFS(int startingCity)
{

//	int shortestDistance = 9000;
//	int endCity;
//	node* temp = edge.at(startingCity).next;
//	vertex.at(startingCity).visited = true;
//	while(temp != NULL)
//	{
//		if(temp->distance < shortestDistance)
//		{
//			endCity = temp->end;
//			shortestDistance = temp->distance;
//		}
//	}
//
//	vertex.at(endCity).visited = true;


}




















#endif /* GRAPH_H_ */
