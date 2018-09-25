/* This program requires the student to write 3 functions described in
 * Program project 4 (Page 535) and Program Project 6 (Page 536).
 * The student also need to add a print function to print out an array.
 *
 * Author: Nicholas Heyd
 * Version: 1.0   8/30/2018
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse (char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{
	//-----------Reverse-----------------
    // write code to test reverse function.
	char input[40];
	char *front, *rear;

	cout << "Enter a sentence to be reversed: " <<endl;
	cin.getline(input, 40);
	cout << "You entered: " << input << endl;

	//first element in the char array
	front = input;
	//last element in char array
	rear = input + strlen(input)-1;
	reverse(front, rear);

	cout << "The sentence reversed is: " << input  << endl;
    

	//------------Entry--------------
	// write code to test add entry and delete entry function

	//Create an initialize the list
	int size = 5;
	string *strNames = new string[size];
	string newEntry = "";
	string deleteName = "";

	strNames[0] = "Nicholas Heyd";
	strNames[1] = "Brandon Duplantis";
	strNames[2] = "Elena Cass";
	strNames[3] = "Claire Maria";
	strNames[4] = "Ivo Robotnik";

	cout << "Current list: " << endl;
	print (strNames, size);


	//now add new names the user wants
	cout << "Please add a name to list: " << endl;
	getline(cin, newEntry);
	strNames = addEntry(strNames, size, newEntry);

	//call print function to show the ADDED name
	print (strNames, size);


	//--------------DELETE-----------------------

	cout << "What name would you like to delete from the list " << endl;
	getline(cin, deleteName);
	strNames = deleteEntry(strNames, size, deleteName);


	//call print function to show the DELETED name
	cout << "The new list is: " << endl;
	print (strNames, size);
    
	return 0;
}

void reverse (char* front, char* rear)
{
	//Declare a temporary char variable to assist in swap
	char temp;

	while(front < rear)
	{
		temp = *front;
		*front = *rear;
		*rear = temp;
		front++;
		rear--;
	}


}


string* addEntry(string* dynamicArray, int& size, string newEntry)
{

	string *newArray = new string[size +1];

	for (int i = 0; i < size; i++) 
	{
		newArray[i] = dynamicArray[i];
	}

	//add the new entry to the array and then increase its size
	newArray[size] = newEntry;
	size++;

	delete[] dynamicArray;

	return newArray;

}


string* deleteEntry(string* dynamicArray, int &size, string entryToDelete)
{

	//Create new dynamic array
	string *newArray;
	newArray = new string[size];

	//cycle through the array until the 'target' is found
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] == entryToDelete)
			string *newArray = new string[size - 1];

		for (int j = 0; j < size; j++) {
			if (dynamicArray[j] != entryToDelete)
				newArray[j] = dynamicArray[j];
		}

	}

	//delete old and return new
	delete[] dynamicArray;
	return newArray;
}





void print(const string* dynamicArray, int size)
{
	//cycle through each element in the dynamic array
	for (int i = 0; i < size; i++) 
	{
		cout << dynamicArray[i] << endl;
	}
}



/*--------------------------------------------OUTPUT-----------------------------------------------------

Enter a sentence to be reversed:
Hello, World!
You entered: Hello, World!
The sentence reversed is: !dlroW ,olleH
Current list:
Nicholas Heyd
Brandon Duplantis
Elena Cass
Claire Maria
Ivo Robotnik
Please add a name to list:
Johnathan Crane
Nicholas Heyd
Brandon Duplantis
Elena Cass
Claire Maria
Ivo Robotnik
Johnathan Crane
What name would you like to delete from the list
Claire Maria
The new list is:
Nicholas Heyd
Brandon Duplantis
Elena Cass

Ivo Robotnik
Johnathan Crane
Press any key to continue . . .


*/
