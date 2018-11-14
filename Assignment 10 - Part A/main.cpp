
#include "graph.h"



int main() {

	Graph myGraph; // Graph object.

	/*
	 *The following block of "insertion" will handle the structure of the graph.
	 *With every insertion on an edge we are adding a vertex and edge that is connecting
	 *the vertex with other vertex's
	 */

	// ATLANTA
	myGraph.insertEdge("Atlanta", "Miami", 661);
	myGraph.insertEdge("Atlanta", "Houston", 810);
	myGraph.insertEdge("Atlanta", "Dallas", 781);
	myGraph.insertEdge("Atlanta", "Kansas City", 864);
	myGraph.insertEdge("Atlanta", "New York", 888);

	// MIAMI
	myGraph.insertEdge("Miami", "Houston", 1187);
	myGraph.insertEdge("Miami", "Atlanta", 661);

	// HOUSTON
	myGraph.insertEdge("Houston", "Dallas", 239);
	myGraph.insertEdge("Houston", "Atlanta", 810);
	myGraph.insertEdge("Houston", "Miami", 1187);

	// DALLAS
	myGraph.insertEdge("Dallas", "Los Angeles", 1435);
	myGraph.insertEdge("Dallas", "Kansas City", 496);
	myGraph.insertEdge("Dallas", "Atlanta", 781);
	myGraph.insertEdge("Dallas", "Houston", 239);


	// KANSAS CITY
	myGraph.insertEdge("Kansas City", "Chicago", 533);
	myGraph.insertEdge("Kansas City", "Denver", 599);
	myGraph.insertEdge("Kansas City", "Los Angeles", 1663);
	myGraph.insertEdge("Kansas City", "Dallas", 496);
	myGraph.insertEdge("Kansas City", "Atlanta", 864);
	myGraph.insertEdge("Kansas City", "New York", 1260);

	// CHICAGO
	myGraph.insertEdge("Chicago", "Boston", 983);
	myGraph.insertEdge("Chicago", "New York", 787);
	myGraph.insertEdge("Chicago", "Kansas City", 533);
	myGraph.insertEdge("Chicago", "Denver", 1003);
	myGraph.insertEdge("Chicago", "Seattle", 2097);

	// NEW YORK
	myGraph.insertEdge("New York", "Atlanta", 888);
	myGraph.insertEdge("New York", "Kansas City", 1260);
	myGraph.insertEdge("New York", "Chicago", 787);
	myGraph.insertEdge("New York", "Boston", 214);

	// BOSTON
	myGraph.insertEdge("Boston", "New York", 214);
	myGraph.insertEdge("Boston", "Chicago", 983);

		// DENVER
	myGraph.insertEdge("Denver", "Seattle", 1331);
	myGraph.insertEdge("Denver", "San Francisco", 1267);
	myGraph.insertEdge("Denver", "Los Angeles", 1015);
	myGraph.insertEdge("Denver", "Kansas City", 599);
	myGraph.insertEdge("Denver", "Chicago", 1003);

	// LOS ANGELES
	myGraph.insertEdge("Los Angeles", "San Francisco", 381);
	myGraph.insertEdge("Los Angeles", "Denver", 1015);
	myGraph.insertEdge("Los Angeles", "Kansas City", 1663);
	myGraph.insertEdge("Los Angeles", "Dallas", 1435);

	// SAN FRANCISCO
	myGraph.insertEdge("San Francisco", "Seattle", 807);
	myGraph.insertEdge("San Francisco", "Denver", 1267);
	myGraph.insertEdge("San Francisco", "Los Angeles", 381);

	// SEATTLE
	myGraph.insertEdge("Seattle", "San Francisco", 807);
	myGraph.insertEdge("Seattle", "Denver", 1331);
	myGraph.insertEdge("Seattle", "Chicago", 2097);

	//*************************************************************************** End of block






	vector<string> dfsVertexList;

	cout << endl;
	cout << "DFS - STARTING AT ATLANTA";
	cout << endl;
	cout << "****************************" << endl;

	// DFS search + calculate total distance traveled (discovery edges)
	int totalDistance = myGraph.DFS("Atlanta", dfsVertexList);

	for(unsigned int i = 0; i < dfsVertexList.size(); i++)
	{
		cout << dfsVertexList.at(i) << endl;
	}

	cout << endl;

	// discovery edges
	vector<string> discEdge = myGraph.getDiscoveryEdges(dfsVertexList);

	cout << endl;
	cout << "DFS DISCOVERY EDGES";
	cout << endl;
	cout << "****************************" << endl;
	for(unsigned int i = 0; i < discEdge.size(); i++)
	{
		cout << discEdge.at(i) << endl;
	}

	// back edges
	vector<string> backEdge = myGraph.getBackEdges(dfsVertexList);

	cout << endl;
	cout << "DFS BACK EDGES";
	cout << endl;
	cout << "****************************" << endl;
	for(unsigned int i = 0; i < backEdge.size(); i++)
	{
		cout << backEdge.at(i) << endl;
	}

	// total distance from discovery edges
	cout << endl;
	cout << "Total Distance Traveled by Discovery Edges: " << totalDistance << endl;


	return 0;
}

