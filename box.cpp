// Program Box writes a box using periods#
#include <iostream>
#include <iomanip>
using namespace std;

void writeFullLine(int length)	//Writes a line of characters 'length' characters long to the screen
{
	for (int i = 0; i < length; i++)
	{
		cout << "#";
	}
	cout << endl;
}

void writeHollowLine(int length)	//Writes a #, and then another # at position 'length', followed by a blank line
{
	cout << "#" << setw(length - 1) << "#" << endl << endl;
}


void writeBox(int numSigns)              // Name of the action
// Post: A box (20 x 4) is printed using periods# 
{
	//The top of the box
	writeFullLine(numSigns);

	//The height of the inside of the square
	int insideHeight = (numSigns / 2) - 2;

	//If numSigns is odd, ovveride insideHeight using the other formula
	if (numSigns % 2 == 1)	insideHeight = (numSigns + 1) / 2 - 2;
	

	//The interior of the box
	cout << endl;
	for (int i = 0; i < insideHeight; i++)
	{
		writeHollowLine(numSigns);
	}

	//The bottom of the box
	writeFullLine(numSigns);
}

int main()
{
	cout << "Please enter the size of the box you would like to be drawn:";
	int numSigns;
	cin >> numSigns;
	writeBox(numSigns);
	cin.get(); cin.get();	//Hold the window open
	return 0;
}