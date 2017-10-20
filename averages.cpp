// Program Averages averages the values on file dataFile.
#include <iostream>
#include <fstream>
using namespace std;

void readAndSum(ifstream& file, int& numElements, float& average) // Reads data from 'file', stores the number of elements in 'countLoc', and stores the average in 'averageLoc'
{
	//Initialize values
	int sum = 0;
	numElements = 0;


	//Make sure the file is open, and throw this exception if not (It's never handled)
	if (file.fail()) throw "File not found!";

	while (true)
	{
		//Read data from the file into 'data'
		int data;
		file >> data;

		if (file.eof()) break;	//If we've read everything from the file, stop exit the loop (AKA stop reading from the file)

		//If we haven't reached the end of the file, then data is valid.
		//Store the data
		numElements++;
		sum += data;
	}

	//sum is implicitly converted to a double so that decimal places are not lost when the average is calculated
	average = (double)sum / numElements;
}

int main()
{
	ifstream  dataFile;
	int  numberOfValues;
	float  average;
	cout << fixed << showpoint;
	dataFile.open("../../averages.dat");		//I have averages stored in a slightly different location from the solution, the ../../ is so that it is opened properly

	readAndSum(dataFile, numberOfValues, average);

	cout << "The average of " << numberOfValues
		<< " values is " << average << endl;

	cin.get(); cin.get();

	return 0;
}