#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struct representing an edge in the graph.
struct Edge
{
	string u; // Starting city.
	string v; // Ending city.
	bool discoveryEdge; // Whether or not edge is a discovery edge.
	int weight; // Distance between the cities.

	// Edge object constructor.
	Edge()
	{
		u = "";
		v = "";
		discoveryEdge = false;
		weight = 0;
	}
};

// Struct representing a vertex in the graph.
struct Vertex
{
	string city; // Name of the city in the vertex.
	bool visited; // Whether or not the vertex has already been visited.
	vector<Edge> edgeList; // List of incident edges.

	// Vertex object constructor.
	Vertex()
	{
		city = "";
		visited = false;
	}
};

// Graph class that uses an adjacency list to store edges.
class Graph
{
public:
	Graph();
	~Graph();
	bool empty();
	int size();
	void initializeGraph();
	void insertVertex(string city);
	unsigned int findVertex(string city);
	void insertEdge(string u, string v, int weight);
	vector<string> vertices();
	vector<string> edges();
	void shortestPathsDijkstra(string startingCity, vector<string> &T,int costs[], int parent[]);
	vector<string> returnPath(string start, string end, int parent[]);
	int primJarnikMST(string startingCity, vector<string> &mst);
private:
	void findClosest(vector<string> &T, int costs[], int parent[]);
	int distanceFromStart(string city, int costs[], int parent[]);
	int smallestEdgeMST(vector<string> &mst);
	int smallestEdge(int vertex);
	int distanceBetween(int v1, int v2);
	unsigned int verticesVisited();
	unsigned int edgesDiscovered(int currVertex);
	vector<Vertex> graph;
	int mstDistance;
};

Graph::Graph()
{
	mstDistance = 0;
}

Graph::~Graph()
{

}

bool Graph::empty()
{
	return graph.empty();
}

int Graph::size()
{
	return graph.size();
}

void Graph::initializeGraph()
{
	fstream fin; // File stream variable.

	// Opens the file.
	fin.open("Map.txt");

	// Reads in the contents of the file.
	while(!fin.eof())
	{
		string u; // Starting city.
		string v; // Ending city.
		int weight; // Distance between the cities.

		getline(fin, u, ',');
		getline(fin, v, ',');
		fin >> weight;
		fin.ignore(1000, '\n');

		// Inserts the edge to the graph.
		insertEdge(u, v, weight);
	}

	fin.close();
}

unsigned int Graph::findVertex(string city)
{
	unsigned int index = 0;
	bool found = false;

	// Searches for the city in the graph and returns the index of the graph it
	// was found, else returns the size of the graph.
	while(index < graph.size() && !found)
	{
		if(graph.at(index).city == city)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	return index;
}

void Graph::insertVertex(string city)
{
	// Adds the vertex to the graph if it does not yet exist.
	if(findVertex(city) == graph.size())
	{
		Vertex newVertex;

		newVertex.city = city;
		newVertex.visited = false;

		cout << newVertex.city << endl;

		graph.push_back(newVertex);
	}
}

void Graph::insertEdge(string u, string v, int weight)
{
	// Returns the index of the vertex.
	unsigned int index = findVertex(u);

	// Adds the vertex to the graph if it does not yet exist and performs a
	// recursive call, else adds the edge to the edgeList of the specified vertex.
	if(index == graph.size())
	{
		insertVertex(u);

		insertEdge(u, v, weight);
	}
	else
	{
		Edge newEdge;

		newEdge.u = u;
		newEdge.v = v;
		newEdge.weight = weight;

		graph.at(index).edgeList.push_back(newEdge);
	}
}

vector<string> Graph::vertices()
{
	vector<string> cityNames; // Vector of city names.

	// Adds the names of the cities in the graph to the vector.
	for(unsigned int i = 0; i < graph.size(); i++)
	{
		cityNames.push_back(graph[i].city);
	}

	return cityNames;
}

vector<string> Graph::edges()
{
	vector<string> edgeList; // Vector of edges.

	// Adds the edges in the graph to the vector if the node has edges.
	for(unsigned int i = 0; i < graph.size(); i++)
	{
		if(graph.at(i).edgeList.size() != 0)
		{
			// Pushes the edge pair onto the vector in (u, v) format.
			for(unsigned int j = 0; j < graph.at(i).edgeList.size(); j++)
			{
				edgeList.push_back("(" + graph.at(i).edgeList.at(j).u + ", "
									   + graph.at(i).edgeList.at(j).v + ")");
			}
		}
	}

	return edgeList;
}

unsigned int Graph::verticesVisited()
{
	int numVisited = 0; // Number of vertices visited.

	// Iterator to the first vertex in the graph.
	vector<Vertex>::iterator graphIt = graph.begin();

	// Counts the number of vertices in the graph that are marked as visited.
	while(graphIt != graph.end())
	{
		if(graphIt->visited)
		{
			numVisited++;
		}

		graphIt++;
	}

	return numVisited;
}

unsigned int Graph::edgesDiscovered(int currVertex)
{
	int numVisited = 0; // Number of edges discovered.

	// Counts the number of edges at the current vertex that have been discovered.
	for(unsigned int i = 0; i < graph.at(currVertex).edgeList.size(); i++)
	{
		if(graph.at(findVertex(graph.at(currVertex).edgeList.at(i).v)).visited)
		{
			numVisited++;
		}
	}

	return numVisited;
}

void Graph::shortestPathsDijkstra(string startingCity, vector<string> &T, int costs[], int parent[])
{
    // Reset the graph, this should be its own function
    if(verticesVisited() == graph.size())
    {
        for (int i=0; i<graph.size(); i++)
        {
            graph[i].visited = false;

            for (int j=0; j< graph.at(i).edgeList.size(); j++)
            {
                graph[i].edgeList[j].discoveryEdge = false;
            }
        }
    }

    // Returns the graph vertex of the starting city "s".
	int currVertex = findVertex(startingCity);

	// Adds "s" to T.
	T.push_back(graph[currVertex].city);

	// Sets the cost of "s" to 0 and its parent to -1.
	costs[currVertex] = 0;
	parent[currVertex] = -1;

	// Marks "s" as visited.
	graph[currVertex].visited = true;

	// Finds the next closest vertex to the vertices in the graph until all
	// vertices have been added to T.
	while(T.size() != size())
	{
		findClosest(T, costs, parent);
	}
}

vector<string> Graph::returnPath(string start, string end, int parent[])
{
	// Vector of the names of the cities in the path from start to end.
	vector<string> path;

	// Returns the graph index of end.
	int vertex = findVertex(end);

	// Pushes the parent of the current vertex onto the path vector until
	// "s" is reached.
	while(parent[vertex] != -1)
	{
		path.push_back(graph[vertex].city);

		vertex = parent[vertex];
	}

	// Adds "s" to the path vector.
	path.push_back(graph[vertex].city);

	// Reverese the path vector so that "s" is first and end is last.
	reverse(path.begin(), path.end());

	return path;
}

int Graph::primJarnikMST(string startingCity, vector<string> &mst)
{
    // Reset the graph, this should be its own function
    if(verticesVisited() == size())
    {
        for (int i=0; i<graph.size(); i++)
        {
            graph[i].visited = false;

            for (int j=0; j< graph.at(i).edgeList.size(); j++)
            {
                graph[i].edgeList[j].discoveryEdge = false;
            }
        }

        mstDistance = 0;
    }

	// Gets the graph index of the vertex being visited.
	int currVertex = findVertex(startingCity);

	// Visits the vertex.
	graph.at(currVertex).visited = true;

	// Adds the vertex to the MST vector.
	mst.push_back(startingCity);

	// Performs a recursive call on itself to visit all vertices in the graph.
	if(mst.size() != size())
	{
		// Gets the graph index of the next closest city in the graph.
		int nextVertex = smallestEdgeMST(mst);

		// Performs recursive call to visit the next closest city.
		primJarnikMST(graph.at(nextVertex).city, mst);
	}

	return mstDistance;
}

void Graph::findClosest(vector<string> &T, int costs[], int parent[])
{
	// Finds the closest city to the root if it is the only vertex in T, else
	// finds the edge with the smallest weight among the edges adjacent to T.
	if(T.size() == 1)
	{
		// Returns the graph index of "s".
		int frontVer = findVertex(T.front());

		// Returns the graph index of the closest vertex to "s".
		int nextVer = smallestEdge(frontVer);

		// Stores the cost and parent of the closest vertex.
		costs[nextVer] = distanceBetween(frontVer, nextVer);
		parent[nextVer] = frontVer;

		// Marks the closest vertex as visited.
		graph[nextVer].visited = true;

		// Adds the closest vertex to T.
		T.push_back(graph[nextVer].city);
	}
	else
	{
		// T index of the city with the smallest edge and the index of the
		// city it is being compared to.
		int smallId = 0;
		int compId = smallId + 1;

		// Smallest distance and comparison distance.
		int smallDist;
		int compDist;

		// Size of T.
		int size = T.size();

		// Compares the smallest edge of smallId to all other smallest edges of
		// the cities in T.
		while(compId < size)
		{
			// Graph indexes of the city in MST with the smallest edge and city
			// it is being compared to.
			int smallVer = findVertex(T[smallId]);
			int compVer = findVertex(T[compId]);

			// Increments smallId to the next city in T if all of the edges
			// of smallVer have already been visited, else checks if all the
			// edges of compVer have been visited.
			if(graph[smallVer].edgeList.size() == edgesDiscovered(smallVer))
			{
				smallId++;
			}
			else
			{
				// Compares the smallest edge of smallVer and compVer if compVer's
				// edges have not all been visited.
				if(graph[compVer].edgeList.size() != edgesDiscovered(compVer))
				{
					// Distance between smallVer and its smallest edge.
					smallDist = distanceBetween(smallVer, smallestEdge(smallVer))
								+ distanceFromStart(graph[smallVer].city, costs,
								  	  	  	  	    parent);

					// Distance between compVer and its smallest edge.
					compDist =  distanceBetween(compVer, smallestEdge(compVer))
								+ distanceFromStart(graph[compVer].city, costs,
										  	  	  	parent);

					// Assigns compId to smallId if compVer has a smaller
					// edge than the current smallest vertex.
					if(smallDist > compDist)
					{
						smallId = compId;

						smallDist = compDist;
					}
				}
			}

			// Increments compId so that it is always at least 1 index ahead of
			// smallId.
			compId++;
		}

		// Graph index of the city with the closest edge.
		int smallestVertex = smallestEdge(findVertex(T[smallId]));

		// Stores the cost and parent of the next closest vertex.
		costs[smallestVertex] = smallDist;
		parent[smallestVertex] = findVertex(T[smallId]);

		// Marks the next closest vertex as visited.
		graph[smallestVertex].visited = true;

		// Adds the next closest vertex to T.
		T.push_back(graph[smallestVertex].city);
	}

}

int Graph::distanceFromStart(string city, int costs[], int parent[])
{
	// Distance accumulator.
	int distance = 0;

	// Graph index of the city whose distance from "s" will be found.
	int vertex = findVertex(city);

	// While vertex is not "s", finds the distance between the current vertex
	// and  its parent.
	while(costs[vertex] != 0)
	{
		// Accumulates distance.
		distance += distanceBetween(vertex, parent[vertex]);

		// Assigns the value of the parent of the current vertex to vertex.
		vertex = parent[vertex];
	}

	return distance;
}

int Graph::smallestEdgeMST(vector<string> &mst)
{
	// Finds the closest city to the root if it is the only vertex in T, else
	// finds the edge with the smallest weight among the edges adjacent to T.
	if(mst.size() == 1)
	{
		// Graph vertex of the city closest to the root.
		int smallestVertex = smallestEdge(findVertex(mst.front()));

		// Accumulates total distance.
		mstDistance += distanceBetween(findVertex(mst.front()), smallestVertex);

		// Prints the edge.
		cout << "(" << mst.front() << ", " << graph[smallestVertex].city << ")\n";

		return smallestEdge(findVertex(mst.front()));
	}
	else
	{
		// MST index of the city with the smallest edge and the index of the
		// city it is being compared to.
		int smallId = 0;
		int compId = smallId + 1;

		// Size of T.
		int size = mst.size();

		// Compares the smallest edge of smallId to all other smallest edges of
		// the cities in T.
		while(compId < size)
		{
			// Graph indexes of the city in MST with the smallest edge and city
			// it is being compared to.
			int smallVer = findVertex(mst[smallId]);
			int compVer = findVertex(mst[compId]);

			// Increments smallId to the next city in MST if all of the edges
			// of smallVer have already been visited, else checks if all the
			// edges of compVer have been visited.
			if(graph[smallVer].edgeList.size() == edgesDiscovered(smallVer))
			{
				smallId++;
			}
			else
			{
				// Compares the smallest edge of smallVer and compVer if compVer's
				// edges have not all been visited.
				if(graph[compVer].edgeList.size() != edgesDiscovered(compVer))
				{
					// Distance between smallVer and its smallest edge.
					int smallDist = distanceBetween(smallVer, smallestEdge(smallVer));

					// Distance between compVer and its smallest edge.
					int compDist =  distanceBetween(compVer, smallestEdge(compVer));

					// Assigns compId to smallId if compVer has a smaller
					// edge than the current smallest vertex.
					if(smallDist > compDist)
					{
						smallId = compId;
					}
				}
			}

			// Increments compId so that it is always at least 1 index ahead of
			// smallId.
			compId++;
		}

		// Accumulates the total MST distance.
		mstDistance += distanceBetween(findVertex(mst[smallId]),
				   	   	   	   	   	   smallestEdge(findVertex(mst[smallId])));

		// Graph index of the city with the closest edge.
		int smallestVertex = findVertex(mst[smallId]);

		// Gets the name of the city that is the closest to the city with the
		// closest edge.
		string nextCity = graph.at(smallestEdge(smallestVertex)).city;

		// Prints the smallest edge (next edge to be visited).
		cout << "(" << mst[smallId] << ", " << nextCity << ")\n";

		// Finds the graph index of the closest city.
		smallId = findVertex(nextCity);

		return smallId;
	}
}

int Graph::smallestEdge(int vertex)
{
	// Edge list vertex of the closest city.
	int smallestIndex = 0;

	// Edge list vertex of the city whose distance is being compared to the
	// city at edgeList.at(smallestIndex).
	int compIndex = smallestIndex + 1;

	// Gets the size of the edgeList for the current vertex.
	int size = graph.at(vertex).edgeList.size();

	// Finds the next closest city that has not been visited yet.
	while(compIndex < size)
	{
		// Gets the graph index of the next closest city.
		int smallestVertex = findVertex(graph.at(vertex).edgeList.at(smallestIndex).v);

		// Gets the graph index of the city in the edge list being compared
		// to the city at edgeList.at(smallestIndex).
		int compVertex = findVertex(graph.at(vertex).edgeList.at(compIndex).v);

		// If the vertex at graph.at(smallestVertex) has already been visited,
		// increments smallest index and does nothing, else checks if the
		// vertex it is being compared to has been visited.
		if(graph.at(smallestVertex).visited)
		{
			smallestIndex++;
		}
		else
		{
			// If the vertex smallestVertex is being compared to has not been
			// visited, compares their weights, else does nothing.
			if(!(graph.at(compVertex).visited))
			{
				if(graph.at(vertex).edgeList.at(smallestIndex).weight >=
						graph.at(vertex).edgeList.at(compIndex).weight)
				{
					smallestIndex = compIndex;
				}
			}
		}

		// Increments compIndex so that it is always the after smallestIndex.
		compIndex++;
	}

	// Finds the graph index of the closest city.
	smallestIndex = findVertex(graph.at(vertex).edgeList.at(smallestIndex).v);

	return smallestIndex;
}

int Graph::distanceBetween(int v1, int v2)
{
	int i = 0;

	// Finds v2 in v1's edge list.
	while(graph[v1].edgeList[i].v != graph[v2].city)
	{
		i++;
	}

	return graph[v1].edgeList[i].weight;
}


#endif /* GRAPH_H_ */
