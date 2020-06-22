#pragma once
#include <string>
#include "DFA_INT.h"
#include "DFA_CHAR.h"


void FileStuff()
{
	//string for whether the user wants to save his DFA to a file:
	string file_or_not;

	//Check whether the user wants his DFA to be saved in a file
should_or_shouldnt_save:


	cout << "Do you want the DFA you're going to create to be saved as a file? 'Yes'/'No' " << endl;
	cin >> file_or_not;
	cout << endl;


	if (file_or_not == "Yes" || file_or_not == "yes")
	{
		should_save_to_file = 1;
		cout << "Please enter a name for the file which will hold the DFA" << endl << "(should end with '.txt'): ";
		cin >> file_name;
		output_to_file.open(file_name);
	}
	else if (file_or_not == "No" || file_or_not == "no")
	{
		should_save_to_file = 0;
	}
	else
	{
		cout << "Incorrect input. Please retry!" << endl;
		goto should_or_shouldnt_save;
	}
}


//NO POINT IN CREATING A TEMPLATE FUNCTION AS WE HAVE TO DEFINE THE TWO ANYWAY!

//Int DFA Functions:
void CreateIntAlphabet(DFA_INT& test, int& size)
{
	//Initialize the int alphabet array:
	test.InitAlphabet(size);

	//Fill alphabet array with user input:
	cout << "Please enter the elements in the alphabet with spaces: ";
	test.InputAlphabet(size);

	//Print alphabet array:
	test.PrintAlphabet(size);
}

void CreateIntStates(DFA_INT& test, int& num)
{
	//Initialize array:
	test.InitStateArr(num);

	//Fill array:
	cout << "Please enter the states' names:" << endl;
	test.FillStateArr(num);
	cout << endl;
	//Print array:
	test.setStatesConditions(num);
	cout << endl << endl;
}

void CreateIntTransitionTable(DFA_INT& test, int& num)
{
	
	test.transition_table.InitTransitionTable(test.size, num);

	test.transition_table.FillTransitionTableInt(test.size, num, test.num_arry, test.states);

	cout << endl;
	test.transition_table.PrintTransitionTable(test.size, num);
}


//Char DFA Functions:
void CreateCharAlphabet(DFA_CHAR& test, int& size)
{
	//Initialize the int alphabet array:
	test.InitAlphabet(size);

	//Fill alphabet array with user input:
	cout << "Please enter the elements in the alphabet with spaces: ";
	test.InputAlphabet(size);

	//Print alphabet array:
	test.PrintAlphabet(size);
}

void CreateCharStates(DFA_CHAR& test, int& num)
{
	//Initialize array:
	test.InitStateArr(num);

	//Fill array:
	cout << "Please enter the states' names:" << endl;
	test.FillStateArr(num);
	cout << endl;
	//Print array:
	test.setStatesConditions(num);
	cout << endl << endl;
}

void CreateCharTransitionTable(DFA_CHAR& test, int& num)
{
	test.transition_table.InitTransitionTable(test.size, num);

	test.transition_table.FillTransitionTableChar(test.size, num, test.char_arry, test.states);

	cout << endl;
	test.transition_table.PrintTransitionTable(test.size, num);
}

