#include "Bible.h"
#include "VerseKey.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::exception;

void main()
{
	Bible bible;
	VerseKey requestedVK;
	Verse requestedVerse;

	cout << "What verse would you like? ";
	cin >> requestedVK;

	while(requestedVK.book != "Quit")
	{
		try
		{
			requestedVerse = bible[requestedVK];
			requestedVerse.printVerse();
		}
		catch (exception e)
		{
			cerr << "Verse not found." << endl;
		}

		cout << "What verse would you like? ";
		cin >> requestedVK;
	} 

}