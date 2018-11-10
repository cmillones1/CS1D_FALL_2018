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

	// Index: 0 -> Atlanta
	//cout << "\nStarting at -> 0";
	obj.insertedge(0,1,661); // to MIA  (start,end,distance)
	obj.insertedge(0,2,810); // to Houston
	obj.insertedge(0,3,781); // to dallas
	obj.insertedge(0,4,864); // to KC
	obj.insertedge(0,10,888); // to NY

	// Index: 1 -> Miami
	//cout << "\nStarting at -> 1";
	obj.insertedge(1,2,1187); // to Houston
	obj.insertedge(1,0,661); // to Atl

	//Index: 2 -> Houston
	//cout << "\nStarting at -> 2";
	obj.insertedge(2,3,239);
	obj.insertedge(2,0,810);
	obj.insertedge(2,1,1187);

	//Index 3 -> Dallas
	//cout << "\nStarting at -> 3";
	obj.insertedge(3,2,239);
	obj.insertedge(3,0,781);
	obj.insertedge(3,4,496);
	obj.insertedge(3,5,1435);

	// Index 4 -> KC
	//cout << "\nStarting at -> 4";
	obj.insertedge(4,3,496);
	obj.insertedge(4,0,864);
	obj.insertedge(4,10,1260);
	obj.insertedge(4,8,533);
	obj.insertedge(4,11,599);
	obj.insertedge(4,5,1663);

	// Index 5 -> LA
	//cout << "\nStarting at -> 5";
	obj.insertedge(5,3,1435);
	obj.insertedge(5,4,1663);
	obj.insertedge(5,11,1015);
	obj.insertedge(5,6,381);

	// Index 6 -> SF
	//cout << "\nStarting at -> 6";
	obj.insertedge(6,7,807);
	obj.insertedge(6,11,1267);
	obj.insertedge(6,5,381);

	//Index 7 -> Seattle
	//cout << "\nStarting at -> 7";
	obj.insertedge(7,6,807);
	obj.insertedge(7,11,1331);
	obj.insertedge(7,8,2097);

	//Index 8 -> Chicago
	//cout << "\nStarting at -> 8";
	obj.insertedge(8,7,2097);
	obj.insertedge(8,11,1003);
	obj.insertedge(8,4,533);
	obj.insertedge(8,10,787);
	obj.insertedge(8,9,983);

	//Index 9 -> Boston
	//cout << "\nStarting at -> 9";
	obj.insertedge(9,8,983);
	obj.insertedge(9,10,214);

	//Index 10 -> NY
	//cout << "\nStarting at -> 10";
	obj.insertedge(10,9,214);
	obj.insertedge(10,8,787);
	obj.insertedge(10,4,1260);
	obj.insertedge(10,0,888);

	//Index 11 -> Denver
	//cout << "\nStarting at -> 11";
	obj.insertedge(11,7,1331);
	obj.insertedge(11,8,1003);
	obj.insertedge(11,4,599);
	obj.insertedge(11,5,1015);
	obj.insertedge(11,6,1267);


	obj.displayEdges();



	return 0;
}


