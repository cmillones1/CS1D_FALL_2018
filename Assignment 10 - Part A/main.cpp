/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * Assignment 10 - DFS.
 * _______________________________________________________________________
 *"Part A Develop software to perform a DFS starting at Atlanta\n"
 "(always choose the edge with the smallest mileage).\n"
 " Identify the discovery edges and the back edges.\n"
 " What is the total distance travelled on the discovery edges?\n"
 " Use an Adjacency List structure.\n
 *
 *
 ************************************************************************/

#include "iostream"
#include "iomanip"
using namespace std;

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: "
			<< "      Christopher Millones & Jose Cardenas\n";
	cout << setw(10) << "ASSIGNMENT #:  10\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: "
			<< "      Mondays & Wednesday: 5:00 - 6\7:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      11-14-2018\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Part A Develop software to perform a DFS starting at Atlanta\n"
			"(always choose the edge with the smallest mileage).\n"
			" Identify the discovery edges and the back edges.\n"
			" What is the total distance travelled on the discovery edges?\n"
			" Use an Adjacency List structure.\n";
}
#include "graph.h"

int main() {

	/*
	 * Display The author information
	 */
	PRINTAUTHOR();
	INSTRUCTIONS();

	/*
	 *The following block of "insertion" will handle the structure of the graph.
	 *With every insertion on an edge we are adding a vertex and edge that is connecting
	 *the vertex with other vertex's
	 */

	Graph myGraph; // Graph object.
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

	vector<string> dfsVertexList; // Will hold the vertecies in the correct order of a DFS


	// Will perform the DFS and store the vertecies in the correct manner while
	// also calculating the total distance
	int totalDistance = myGraph.DFS("Atlanta", dfsVertexList);

	/*
	 * Will loop around the dfsvertexlist vector and display the elements
	 * in the correct order of the dfs
	 */
	cout << "\n\tDFS Traversal Starting at City: ALANTA!\n";
	cout << "\t***************************************\n";
	for (int i = 0; i < dfsVertexList.size(); i++) {
		cout << "\t\t\t" << "(" << i + 1 << "):" << dfsVertexList.at(i)
				<< endl;
	}
	cout << "The Total distance traveled by on a discovery edge only : "
			<< totalDistance;

	cout << endl;

	// Will perform the same idea as the vertecies list and display the vertex edge's that
	// are discovery edges.
	vector<string> discoveryEdges = myGraph.getDiscoveryEdges(dfsVertexList);

	cout << "\nDiscover Edeges for the DFS Traversal starting at Alanta\n";
	cout << "*********************************************************\n";
	for (int i = 0; i < discoveryEdges.size(); i++) {
		cout << discoveryEdges.at(i) << endl;
	}

	// back edges
	vector < string > backEdge = myGraph.getBackEdges(dfsVertexList);

	cout << "\nBackEdeges Edeges for the DFS Traversal starting at Alanta\n";
	cout << "***********************************************************\n";
	for (int i = 0; i < backEdge.size(); i++) {
		cout << backEdge.at(i) << endl;
	}

	

	return 0;
}

