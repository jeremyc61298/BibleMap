#include "Map.hpp"
#include <iostream>

using util::Map;
using std::cout;
using std::endl;

void main()
{
	Map<int, float> myNums;

	// adding key/value pairs
	myNums[1] = 1.1;
	myNums[5] = 5.5;

	// retrieving values
	cout << myNums[1] << " was added into the map. " << endl;
	cout << myNums[5] << " was added into the map." << endl;

	// updating values
	cout << myNums[5] << " was changed to ";
	myNums[5] = 55.5;
	cout << myNums[5] << endl;
 
	// exceptions are thrown when no value is matched to the key
	try
	{
		float f = myNums[4];
	}
	catch (std::range_error e)
	{
		cout << e.what() << endl;
	}

	try
	{
		float * pf = &myNums[4];
	}
	catch (std::range_error e)
	{
		cout << e.what() << endl;
	}

}