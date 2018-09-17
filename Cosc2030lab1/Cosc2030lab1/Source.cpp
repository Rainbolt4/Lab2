//Lab 1
//Dominic Rainbolt
// COSC 2030 fall 2018
// 9/17/2018
// lab to practice opening a file, reading inputs, and reporting the number of inputs.



#include<fstream>
#include<iostream>
#include<string>
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
	string inBuf;
	ifstream inFile;
	int count = 0;
	int firstNum = -9999;
	int secondNum = -9999;
	int secondToLastNum = -9999;
	int lastNum = -9999;
	int temp = -9999;
	bool done = false;
	int numInt = 0;
	while (!done) // loop for getting the valid files
	{
		cout << "please enter the name of your input file: ";
		getline(cin, inBuf);
		inFile.open(inBuf);

		if (inFile.is_open()) {
			done = true;
		}
		else {
			cerr << "Could not open: " << inBuf << endl;
			done = false;
		}

	}

	while (inFile >> temp) { // loop to get the the number of elements and store the first two.
		numInt++;
		if (numInt == 1) {
			firstNum = temp;
		}
		if (numInt == 2) {
			secondNum = temp;
		}
	}
	inFile.close();
	inFile.open(inBuf);
	while (inFile >> temp) { // second loop to get the second to last and last numbers.
		count = count + 1;
		if (count == (numInt - 1)) {
			secondToLastNum = temp;
		}
		if (count == (numInt)) {
			lastNum = temp;
		}
	}
	inFile.close();
	cout << "number of integers is : " << count << endl;
	cout << "The first Number is : " << firstNum << endl;
	cout << "The second number is : " << secondNum << endl;
	cout << "The second to last number is : " << secondToLastNum << endl;
	cout << "the last number is : " << lastNum << endl;

	system("pause");
}

