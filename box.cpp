// Program Box writes a box using periods#
#include <iostream>
#include <iomanip>
using namespace std;

void writeFullLine(int length, char symbol)	//Writes a line of characters 'length' characters long to the screen
{
	for (int i = 0; i < length; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

void writeHollowLine(int length, char symbol)	//Writes a #, and then another # at position 'length', followed by a blank line
{
	cout << symbol << setw(length - 1) << symbol << endl << endl;
}


void writeBox(int numSigns, char symbol)              // Name of the action
// Post: A box (20 x 4) is printed using periods# 
{
	//The top of the box
	writeFullLine(numSigns, symbol);

	//The height of the inside of the square
	int insideHeight = (numSigns / 2) - 2;

	//If numSigns is odd, ovveride insideHeight using the other formula
	if (numSigns % 2 == 1)	insideHeight = (numSigns + 1) / 2 - 2;

	//The interior of the box
	cout << endl;
	for (int i = 0; i < insideHeight; i++)
	{
		writeHollowLine(numSigns, symbol);
	}

	//The bottom of the box
	writeFullLine(numSigns, symbol);
}

int main()
{
	cout << "Please enter the size of the box you would like to be drawn:";
	int numSigns;
	cin >> numSigns;
	char symbol;
	cout << "Please enter the symbol you would like to use:";
	cin >> symbol;
	writeBox(numSigns, symbol);
	cin.get(); cin.get();	//Hold the window open
	return 0;
}