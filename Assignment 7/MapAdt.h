

#ifndef MAPADT_H_
#define MAPADT_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



struct location
{
	int key;
	string city;

};


typedef std::vector<location *, std::allocator<location *> >::iterator itterator;




template<typename Type>
class Map
{
private:
	vector<location*> position;
	location *hash;
	const int BUCKET_SIZE = 29;


public:
	Map();
	~Map();
	int size();
	bool empty();
	itterator find(const int key);
	void putDoubleHasing(location &place);
	void putQuadHashing(location &place);
	void erase(const int key);
	void erase(vector<location*> positon);
	bool keyExists(const int key);
	void printHashBucket();
//	void print();
};

template<typename Type>
Map<Type>::Map()
{
	hash = new location[BUCKET_SIZE]();


};
template<typename Type>
Map<Type>::~Map(){}

template<typename Type>
int Map<Type>::size()
{
	return position.size();
}

template<typename Type>
bool Map<Type>::empty()
{
	return position.empty();
}

template<typename Type>
itterator Map<Type>::find(const int key)
{


	std::vector<location *, std::allocator<location *> >::iterator it;
	for(it = position.begin(); it!= position.end(); it++)
	{
		if((*it)->key == key)
		{
			return it;
		}
	}

	return position.end();



}

template<typename Type>
bool Map<Type>::keyExists(const int key)
{
	//	cout << "\n the size of the vector is: " << position.size() << endl;
	//	cout << "\n keys inside the vector:  ";
	//	for( int index = 0; index < position.size(); index++)
	//	{
	//		cout << position.at(index)->key << " ";
	//	}

	//	cout << endl << endl;
	for(int index = 0; index < position.size(); index++)
	{
		//		cout << "key entered: " << key << " index key: " << position.at(index)->key << endl ;
		if(position.at(index)->key == key)
			return true;
	}

	return false;

}

template<typename Type>
void Map<Type>::putDoubleHasing(location &place)
{
	itterator it = find(place.key);


	if(it != position.end())
	{
		//cout << "(key: " << (*it)->key << ") values being changed from (" << (*it)->city << ") --> (" << place.city << ") " << endl;
		(*it)->city = place.city;
		return;
	}

	int hashOne = place.key % BUCKET_SIZE;

	if(hash[hashOne].key == 0)
	{
		hash[hashOne] = place;
		position.push_back(&hash[hashOne]);
	}
	else
	{

		int hashTwo = 11 - place.key % 11;
		int j = 0;

		int doubleHashed = (hashOne + j*(hashTwo)) % BUCKET_SIZE;
		//		cout << "\ndoubleHashed value: " << doubleHashed << endl << endl;


		while(hash[doubleHashed].key != 0)
		{
			j++;
			doubleHashed = (hashOne + j*(hashTwo)) % BUCKET_SIZE;
		}


		hash[doubleHashed] = place;
		position.push_back(&hash[doubleHashed]);
	}
	//cout << "(key: " << place.key << " & city: " << place.city << ") are being added\n";

}

template<typename Type>
void Map<Type>::putQuadHashing(location &place)
{
	itterator it = find(place.key);


	if(it != position.end())
	{
	//	cout << "(key: " << (*it)->key << ") values being changed from (" << (*it)->city << ") --> (" << place.city << ") " << endl;
		(*it)->city = place.city;
		return;
	}

	int hashOne = place.key % BUCKET_SIZE;

	if(hash[hashOne].key == 0)
	{
		hash[hashOne] = place;
		position.push_back(&hash[hashOne]);
	}
	else
	{

//		int hashTwo = 11 - place.key % 11;
		int j = 1;

		int doubleHashed = (hashOne + (j*j)) % BUCKET_SIZE;


		while(hash[doubleHashed].key != 0)
		{
			j++;
			doubleHashed = (hashOne + (j*j)) % BUCKET_SIZE;
		}


		hash[doubleHashed] = place;
		position.push_back(&hash[doubleHashed]);
	}
	//cout << "(key: " << place.key << " & city: " << place.city << ") are being added\n";
}


template<typename Type>
void Map<Type>::erase(const int key)
{
	for(itterator it = position.begin(); it!= position.end(); it++)
	{
		if((*it)->key == key)
		{
			//cout << "\nkey: " << (*it)->key << " is being deleted from the map\n";
			(*it)->key = 0;
			(*it)->city = " ";
			position.erase(it);
		}
	}

}


template<typename Type>
void Map<Type>::printHashBucket()
{
	//	cout << "\nhash bucket: \n";
	cout << "\tINDEX:\tKEY:\tVALUE:\n";
	for(int index = 0; index < 29; index++)
	{
		cout << "\t" << index << "\t" << hash[index].key << "\t" << hash[index].city << endl;
	}
}

//template<typename Type>
//void Map<Type>::print()
//{
//
//	cout << "\nMap: \n";
//	for(int index = 0; index < position.size(); index++)
//	{
//		cout <<"key: " << position.at(index)->key << " city: " << position.at(index)->city << endl;
//		//		<< "         address: " << position.at(index) << endl ;
//	}
//	cout << endl;
//}




#endif /* MAPADT_H_ */
