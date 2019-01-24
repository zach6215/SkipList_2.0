/*This program will take in words and put them into a Skip List.
It will then output a visual representation of the list. */


#include <iostream>
#include <cstdlib>
#include <ctime>


#include "SkipList.h"

using namespace std;

void welcomeMessage();
int promptAndGetUserChoice();


int main()
{
	//Seed random number generator
	srand(time(0));

	//Locals
	int choice;
	string userWord;
	string again = "y";
	SkipList test;

	welcomeMessage();

	do
	{
		choice = promptAndGetUserChoice();

		switch (choice)
		{
			//Insert word
		case 1:
		{
			do
			{
				cout << "\nPlease enter word to add: ";
				cin >> userWord;

				test.insert(userWord);

				cout << "Add another word (y/n)? ";
				cin >> again;

			} while (again == "Y" || again == "y");
			again = "y";
			break;
		}
			//Output list
		case 2:
		{
			cout << "\n Outputing list...\n\n";
			cout << test;
			break;
		}
		{

		}
			//Exit
		default:
		{
			again = 'n';
		}

		}
	} while (again == "Y" || again == "y");


	return 0;
}

void welcomeMessage()
{
	cout << " This program is an example of a Skip List.\n";
	cout << "============================================\n";

}

int promptAndGetUserChoice()
{
	int userChoice;
	string runAgain;

	do 
	{
		cout << "\n| 1: Insert word | ";
		cout << "2: Output Skip List | ";
		cout << "3: Exit\n";

		cout << "Please choose what you want your Skip List to do: ";
		cin >> userChoice;

		if (userChoice < 1 || userChoice > 4)
		{
			cout << "\nInvalid input! Must be choice 1 - 3! \n";
			cout << "Do you want to try again? (y/n):";

			cin >> runAgain;
		}
		else
		{
			runAgain = 'n';
		}

	} while (runAgain == "y" || runAgain == "Y");

	return userChoice;
}

