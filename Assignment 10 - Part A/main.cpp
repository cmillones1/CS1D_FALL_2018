/*
 * main.cpp
 *
 *  Created on: Nov 8, 2018
 *      Author: Chris
 */

#include <iostream>
#include <iomanip>
#include "graph.h"
using namespace std;

int main()
{

	graph obj;

	obj.insertVertex("Atlanta"); // index: 0
	obj.insertVertex("Miami"); // index: 1
	obj.insertVertex("Houston"); // index: 2
	obj.insertVertex("Dallas"); // index: 3
	obj.insertVertex("Kansas City"); // index: 4
	obj.insertVertex("Los Angeles"); // index: 5
	obj.insertVertex("San Francisco"); // index: 6
	obj.insertVertex("Seattle"); // index: 7
	obj.insertVertex("Chicago"); // index: 8
	obj.insertVertex("Boston"); // index: 9
	obj.insertVertex("New York"); // index: 10
	obj.insertVertex("Denver"); // index: 11

	obj.displayVertex();

//	// Index: 0 -> Atlanta
	obj.insertedge(0,1,661); // to MIA
	//obj.insertedge(0,2,810);  // to Houst
	obj.displayEdges(0);
//	obj.insertedge(0,3,781); // to Dallas
//	obj.insertedge(0,4,864); // to KC
//	obj.insertedge(0,10,888); // to NY

	return 0;
}


