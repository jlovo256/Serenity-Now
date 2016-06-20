/*
@file mainmenu.cpp

@brief This file contains the main.  Allows the user to access a series of 
	menus which provide functions for processing trancations, inventory
	maitanance, and inventory reporting.

*/

/*****************************************************
 *  Project adapted from Starting out with C++, 
 *  Early Objects, 7th Edition, by Tony Gaddis, et al. 
 *  
 *  Initial code provided: example solution of Ch. 6
 *  project component, broken into .h and .cpp files.
 *  Code included a working menu system calling
 *  mostly stub functions. No file I/O, arrays or
 *  classes were provided. -RO
 *
 *  Developer name: Jamie Tudor
 *
 *****************************************************/


/*****************************************************
 *  Serendipity Booksellers -- Main Menu             *
*****************************************************/

#include "mainmenu.h"
#include "BookData.h"
#include "BookCollection.h"

#include <iostream>
#include <string>

using namespace std;

BookCollection* Menu::books;	// Initialize pointer
BookCollection bks;				// Create BookCollection

/*
  The main function.
*/
int main()
{
	string input;				// To hold user string input.
	int choice = 0;				// Stores user's menu choice
	Menu::initialize(&bks);		//  initialize menu


	do
	{  // Display company name and screen title
        cout << "\n\n\n      Serendipity Booksellers\n";
        cout << "             Main Menu\n\n\n";
        
		// Display menu items
		cout << "   1. Cashier Module\n";
		cout << "   2. Inventory Database Module\n";
		cout << "   3. Report Module\n";
		cout << "   4. Exit\n\n";
        
		// Display prompt and get user's choice
		cout << "   Enter your choice: ";
		getline(cin, input);
		choice = atoi(input.c_str());
        
		// Validate user's entry
		while (choice < 1 || choice > 4)
		{
			cout << "\n   Please enter a number in the range 1 - 4. ";
			getline(cin, input);
			choice = atoi(input.c_str());
		} // end while
		
		// choose which menu
		switch (choice)
		{
			case 1: cout << "You choose 1" << endl; 
				Menu::cashier();
                break;
			case 2:	cout << "You choose 2" << endl; 
				Menu::invMenu();
                break;
			case 3:	cout << "You choose 3" << endl; 
				Menu::reports();
		}
	} while (choice != 4); // end do while


    
	return 0;
} // end main

// the end is near
