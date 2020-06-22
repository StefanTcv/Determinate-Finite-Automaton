#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "DFA.h"
#include "DFA_INT.h"
#include "DFA_CHAR.h"
#include "States.h"
#include "globals.h"
#include "Functions.h"

using namespace std;


//GLOBAL VARIABLES  ( DECLARATION IN "globals.h" )
string file_name;
ofstream output_to_file;
ifstream input_from_file;

bool should_save_to_file;
bool should_read_from_file;
bool should_be_char;

int main()
{
	//size for the alphabet array:
	int arr_size = 0;

	//number of states (for the states array):
	int number_of_states = 0;

	//variable for breaking the menus:
	int menu = 1;
	int menu_for_file_input = 1;
	int create_or_open = 1;

	//object for int alphabet:
	DFA_INT	int_automaton;
	//object for char alphabet:
	DFA_CHAR char_automaton;

	
	//A while cycle for the first menu:
	while (create_or_open)
	{
		cout << "1.Create a new DFA" << endl << "2.Open a DFA from a text file" << endl << "0.Quit" << endl;
		cin >> create_or_open;

		//Clears the console:
		system("cls");

		switch (create_or_open)
		{

		case 1:  //Creates an entirely new DFA:
			FileStuff();

			//Clears the console:
			system("cls");


			//Menu for creating a DFA:
			menu = 1;
			while (menu)
			{
				//UI
				cout << "1.Int alphabet" << endl << "2.Char alphabet" << endl << "0.Return" << endl;
				cin >> menu;


				switch (menu)
				{
					//INTEGER ALPHABET:
				case 1:
					//Clears the console:
					system("cls");


					//Take size from user:
					cout << "Please enter the number of elements in the alphabet: ";
					cin >> arr_size;
					if (should_save_to_file)
					{
						output_to_file << arr_size << endl;
					}

					CreateIntAlphabet(int_automaton, arr_size);


					//STATES:
					//Take the number of states from user:
					cout << "Please enter the number of states the DFA is going to contain: ";
					cin >> number_of_states;
					if (should_save_to_file)
					{
						output_to_file << number_of_states << endl;
					}

					CreateIntStates(int_automaton, number_of_states);

					//TRANSITION TABLE:
					CreateIntTransitionTable(int_automaton, number_of_states);

					//Word recognition:
					int_automaton.recognizeWord(number_of_states);


					//Setting the checker to it's initial state:
					should_save_to_file = 0;
					//Closing the file if it's open:
					if (output_to_file.is_open())
					{
						output_to_file.close();
					}
					break;



					//CHARACTER ALPHABET:
				case 2:
					//Clears the console:
					system("cls");

					//Take size from user:
					cout << "Please enter the number of elements in the alphabet: ";
					cin >> arr_size;
					if (should_save_to_file)
					{
						output_to_file << arr_size << endl;
					}
					
					CreateCharAlphabet(char_automaton, arr_size);

					//STATES:
					//Take the number of states from user:
					cout << "Please enter the number of states the DFA is going to contain: ";
					cin >> number_of_states;
					if (should_save_to_file)
					{
						output_to_file << number_of_states << endl;
					}
					
					CreateCharStates(char_automaton, number_of_states);					
					
					CreateCharTransitionTable(char_automaton, number_of_states);
					
					//Word recognition:
					char_automaton.recognizeWord(number_of_states);


					//Setting the checker to it's initial state:
					should_save_to_file = 0;
					//Closing the file if it's open:
					if (output_to_file.is_open())
					{
						output_to_file.close();
					}
					break;

				case 0:
					//Clears the console:
					system("cls");

					break;
				}
				//Break the small menu so it doesn't continue to case 2:
				break;


		case 2:
			//Clears the console:
			system("cls");

			//UI
			cout << "1.Int alphabet" << endl << "2.Char alphabet" << endl << "0.Return" << endl;
			cin >> menu_for_file_input;
			switch (menu_for_file_input)
			{
			case 1:
			no_such_file_int:

				should_read_from_file = 1;
				cout << "Please enter a name for the file which will create the DFA: ";
				cin >> file_name;
				input_from_file.open(file_name);


				if (input_from_file.is_open())
				{

					//Take size from the file:
					cout << "Please enter the number of elements in the alphabet: ";
					input_from_file >> arr_size;
					cout << arr_size << endl;
									
					CreateIntAlphabet(int_automaton, arr_size);
					
					//STATES:
					//Take the number of states from file:
					cout << "Please enter the number of states the DFA is going to contain: ";
					input_from_file >> number_of_states;
					cout << number_of_states << endl;
										
					CreateIntStates(int_automaton, number_of_states);
										
					CreateIntTransitionTable(int_automaton, number_of_states);
		

					//Word recognition:
					int_automaton.recognizeWord(number_of_states);


					//Setting the checker to it's initial state
					should_read_from_file = 0;
					input_from_file.close();

					break;
				}
				else
				{
					cout << "There is no such file!" << endl;
					goto no_such_file_int;
				}
				break;

			case 2:
			no_such_file_char:

				should_read_from_file = 1;
				cout << "Please enter a name for the file which will create the DFA: ";
				cin >> file_name;
				input_from_file.open(file_name);


				if (input_from_file.is_open())
				{

					//Take size from the file:
					cout << "Please enter the number of elements in the alphabet: ";

					input_from_file >> arr_size;
					cout << arr_size << endl;
									
					CreateCharAlphabet(char_automaton, arr_size);
					

					//STATES:
					//Take the number of states from file:
					cout << "Please enter the number of states the DFA is going to contain: ";
					input_from_file >> number_of_states;
					cout << number_of_states << endl;
										
					CreateCharStates(char_automaton, number_of_states);
									
					CreateCharTransitionTable(char_automaton, number_of_states);


					//Word recognition:
					char_automaton.recognizeWord(number_of_states);


					//Setting the checker to it's initial state
					should_read_from_file = 0;
					input_from_file.close();

					break;
				}
				else
				{
					cout << "There is no such file!" << endl;
					goto no_such_file_char;
				}
				break;
			case 0:
				//Clears the console:
				system("cls");

				break;
			}
			}
		}
	}
}
