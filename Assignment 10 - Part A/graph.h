#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct nodeEdge {
	string startCity;
	string endCity;
	bool discEdge;
	int weight;
	nodeEdge() {
		startCity = "";
		endCity = "";
		discEdge = false;
		weight = 0;
	}
};


struct nodeVertex {
	string city;
	bool visited;
	vector<nodeEdge> edgeList;

	nodeVertex() {
		city = "";
		visited = false;
	}
};

// graph - adjacency list structure
class Graph {
public:
	Graph();
	~Graph();
	void insertVertex(string city);
	int findVertex(string city);
	void insertEdge(string startCity, string endCity, int weight);
	vector<string> vertices();
	vector<string> edges();
	int DFS(string startingCity, vector<string> &dfsGraph);
	vector<string> getDiscoveryEdges(vector<string> &dfsGraph);
	vector<string> getBackEdges(vector<string> &dfsGraph);

private:
	int smallestEdgeDFS(int currVertex, vector<string> &dfs);
	int verticesVisited();
	int edgesDiscovered(int currVertex);
	void deleteDuplicates(vector<nodeEdge> &edgeList);
	vector<nodeVertex> graph;
	int dfsDistance;
	string otherVertex(nodeEdge currEdge, string startingCity);
	int distance(nodeVertex * v1, nodeVertex * v2);
};

// default constructor
Graph::Graph() {
	dfsDistance = 0;
}

// destructor
Graph::~Graph() {
}

// insert vertex
void Graph::insertVertex(string city) {
	if (findVertex(city) == graph.size()) {	// adds the vertex if not added already
		nodeVertex newVertex;

		newVertex.city = city;
		newVertex.visited = false;
		graph.push_back(newVertex);
	}
}

// insert edge
void Graph::insertEdge(string startCity, string endCity, int weight) {
	int index = findVertex(startCity);	// returns the vertex

	if (index == graph.size()) {		// adds the vertex if not added already
		insertVertex(startCity);
		insertEdge(startCity, endCity, weight);
	} else {
		nodeEdge newEdge;

		newEdge.startCity = startCity;
		newEdge.endCity = endCity;
		newEdge.weight = weight;

		graph.at(index).edgeList.push_back(newEdge);
	}
}

// gets the city nodes
vector<string> Graph::vertices() {
	vector<string> cityNames;						// vector of city names

	for (int i = 0; i < graph.size(); i++) {
		cityNames.push_back(graph[i].city);
	}

	return cityNames;
}

// gets the edges
vector<string> Graph::edges() {
	vector<string> edgeList; 			// edges

	for (int i = 0; i < graph.size(); i++) {// adds the edges if node has edges
		if (graph.at(i).edgeList.size() != 0) {
			for (int j = 0; j < graph.at(i).edgeList.size(); j++) {	// adds it in (startCity, endCity) format
				edgeList.push_back(
						"(" + graph.at(i).edgeList.at(j).startCity + ", "
								+ graph.at(i).edgeList.at(j).endCity + ")");
			}
		}
	}
	return edgeList;
}

// distance/weight
int Graph::distance(nodeVertex * v1, nodeVertex * v2) {
	for (int i = 0; i < v1->edgeList.size(); i++) {		// get connecting edge
		if (v1->edgeList.at(i).startCity == v2->city
				|| v1->edgeList.at(i).endCity == v2->city)
			return v1->edgeList.at(i).weight;
	}
	return -1;
}


// DFS search
int Graph::DFS(string startingCity, vector<string> &dfsGraph) {
	int currVertex = findVertex(startingCity);		// gets the vertex

	graph.at(currVertex).visited = true;			// marks it as visited

	vector<string>::iterator nextCityIt = find(dfsGraph.begin(), dfsGraph.end(),
			startingCity);	// gets the cities visited

	if (nextCityIt == dfsGraph.end()) {
		dfsGraph.push_back(startingCity);
	}

	if (verticesVisited() != graph.size()) {				// recursive call
		int nextVertex = smallestEdgeDFS(currVertex, dfsGraph);
		DFS(graph.at(nextVertex).city, dfsGraph);
	}
	return dfsDistance;
}

// get the discovery edges
vector<string> Graph::getDiscoveryEdges(vector<string> &dfsGraph) {
	vector<nodeEdge> discEdges;					// vector of discovery edges

	for (int i = 0; i < graph.size(); i++) {		// gets all the disc edges
		int dfsIndex = findVertex(dfsGraph.at(i));

		for (int j = 0; j < graph.at(dfsIndex).edgeList.size(); j++) {
			if (graph.at(dfsIndex).edgeList.at(j).discEdge) {
				discEdges.push_back(graph.at(dfsIndex).edgeList.at(j));
			}
		}
	}

	deleteDuplicates(discEdges);		// delete duplicates

	vector<nodeEdge>::iterator edgeIt = discEdges.begin();// goes to the beginning disc edges

	vector<string> discoveryEdges; 							// disc edge pairs

	while (edgeIt != discEdges.end()) {
		discoveryEdges.push_back(
				"\t(From):" + edgeIt->startCity + " ---> (To):"
						+ edgeIt->endCity);

		edgeIt++;
	}

	return discoveryEdges;
}

vector<string> Graph::getBackEdges(vector<string> &dfsGraph) {
	vector<nodeEdge> backEdges; 					// vector - back edges

	for (int i = 0; i < graph.size(); i++) {				// adds back edges
		int dfsIndex = findVertex(dfsGraph.at(i));

		for (unsigned int j = 0; j < graph.at(dfsIndex).edgeList.size(); j++) {
			if (!(graph.at(dfsIndex).edgeList.at(j).discEdge)) {// adds only if its a back edge
				backEdges.push_back(graph.at(dfsIndex).edgeList.at(j));
			}
		}
	}

	deleteDuplicates(backEdges);		// delete duplicates

	vector<nodeEdge>::iterator edgeIt = backEdges.begin();// starts at begin of vector

	vector<string> backEdgeList; // back edge pairs

	while (edgeIt != backEdges.end()) {	// (startCity, endCity)
		backEdgeList.push_back(
				"\t(From):" + edgeIt->startCity + " ---> (To):"
						+ edgeIt->endCity);

		edgeIt++;
	}

	return backEdgeList;
}

// goes to the smallest edge for DFS search
int Graph::smallestEdgeDFS(int currVertex, vector<string> &dfsGraph) {
	if (edgesDiscovered(currVertex) != graph.at(currVertex).edgeList.size()) {
		int smallestIndex = 0;
		int compIndex = smallestIndex + 1;

		int size = graph.at(currVertex).edgeList.size();	// get current size

		while (compIndex < size) {
			int smallestVertex = findVertex(
					graph.at(currVertex).edgeList.at(smallestIndex).endCity);
			int compVertex = findVertex(
					graph.at(currVertex).edgeList.at(compIndex).endCity);

			if (graph.at(smallestVertex).visited) {
				smallestIndex++;
			} else {
				if (!(graph.at(compVertex).visited)) {
					if (graph.at(currVertex).edgeList.at(smallestIndex).weight
							>= graph.at(currVertex).edgeList.at(compIndex).weight) {
						smallestIndex = compIndex;
					}
				}
			}
			compIndex++;
		}
		graph.at(currVertex).edgeList.at(smallestIndex).discEdge = true;
		dfsDistance += graph.at(currVertex).edgeList.at(smallestIndex).weight;
		string nextCity =
				graph.at(currVertex).edgeList.at(smallestIndex).endCity;
		smallestIndex = findVertex(nextCity);

		for (int i = 0; i < graph.at(smallestIndex).edgeList.size(); i++) {
			if (graph.at(currVertex).city
					== graph.at(smallestIndex).edgeList.at(i).endCity) {
				graph.at(smallestIndex).edgeList.at(i).discEdge = true;
			}
		}
		return smallestIndex;
	} else {
		vector<string>::iterator dfsIt = find(dfsGraph.begin(), dfsGraph.end(),
				graph.at(currVertex).city);
		dfsIt--;

		int backIndex = findVertex(*dfsIt);

		return smallestEdgeDFS(backIndex, dfsGraph);
	}
}

// find other vertex of the node
string Graph::otherVertex(nodeEdge currEdge, string startingCity) {
	if (currEdge.startCity == startingCity) {
		return currEdge.endCity;
	} else {
		return currEdge.startCity;
	}
}

// get all the vertices visited
int Graph::verticesVisited() {
	int numVisited = 0;

	vector<nodeVertex>::iterator graphIt = graph.begin();

	while (graphIt != graph.end()) {
		if (graphIt->visited) {
			numVisited++;
		}

		graphIt++;
	}
	return numVisited;
}


// delete duplicates
void Graph::deleteDuplicates(vector<nodeEdge> &edgeList) {
	vector<nodeEdge>::iterator listIt = edgeList.begin();

	while (listIt != edgeList.end()) {
		vector<nodeEdge>::iterator compIt = listIt + 1;

		bool deleted = false;

		while (compIt != edgeList.end() && !deleted) {
			if (listIt->startCity == compIt->endCity
					&& listIt->endCity == compIt->startCity) {
				edgeList.erase(compIt);

				deleted = true;
			} else {
				compIt++;
			}
		}
		listIt++;
	}
}

// finds how many edges discovered
int Graph::edgesDiscovered(int currVertex) {
	int numVisited = 0;

	for (int i = 0; i < graph.at(currVertex).edgeList.size(); i++) {
		if (graph.at(findVertex(graph.at(currVertex).edgeList.at(i).endCity)).visited) {
			numVisited++;
		}
	}

	return numVisited;
}

// finds the vertex of the city
int Graph::findVertex(string city) {
	int index = 0;
	bool found = false;

	while (index < graph.size() && !found) {		// finds the city
		if (graph.at(index).city == city) {
			found = true;
		} else {
			index++;
		}
	}
	return index;
}

#endif /* GRAPH_H_ */
