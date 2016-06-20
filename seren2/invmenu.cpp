/*
@file invmenu.cpp
@class Menu

@author Jamie Tudor
*/
/*****************************************************
 *                     invMenu                       *
 *  Called by main()                                 *
 *  Allows the user to select an inventory operation *
 *****************************************************/
#include "mainmenu.h"
#include <iostream>
#include <string>
#include "BookData.h"


using namespace std;

//Function prototypes for subfunctions called by invMenu()
void addBook(BookCollection *b);
void deleteBook(BookCollection *b);
void editBook(BookCollection *b);
void lookUpBook(BookCollection *b);


/*
	This function of class Menu allows the user to edit the inventory of 
	the BookCollection.
*/
void Menu::invMenu()
{
	int choice = 0;      // Stores user's menu choice
	string input;		 // For user input

	do
	{	// Display company name and screen title
		cout << "\n\n\n            Serendipity Booksellers\n";
		cout << "              Inventory Database\n\n\n";
        
		// Display menu items
		cout << "         1. Look Up a Book\n";
		cout << "         2. Add a Book\n";
		cout << "         3. Edit a Book's Record\n";
		cout << "         4. Delete a Book\n";
		cout << "         5. Return to the Main Menu\n\n";
        
		// Display prompt and get user's choice
		cout << "         Enter Your Choice: ";
		getline(cin, input);
		choice = atoi(input.c_str());
        
		// Validate user's entry
		while (choice < 1 || choice > 5)
		{
			cout << "\n         Please enter a number in the range 1 - 5. ";
			getline(cin, input);
			choice = atoi(input.c_str());
		} // end while
		// Echo choice
		switch (choice)
		{
			case 1: lookUpBook(books);
                break;
			case 2:	addBook(books);
                break;
			case 3:	editBook(books);
                break;
			case 4:	deleteBook(books);
		} // end switch
	} while (choice != 5); // end do while

} // end function invMenu


/********** Subfunctions called by invMenu ***********/
/*****************************************************/

/*****************************************************
 *                 lookUpBook                        *
 *  Called by: invMenu()                             *
 *  Locates and displays a book record               *
 *****************************************************/
void lookUpBook(BookCollection *b)
{
	cout << "\nYou selected Look Up Book.\n\n";
	b->lookUpBook();
} // end function lookUpBook

/*****************************************************
 *                   addBook                         *
 *  Called by: invMenu()                             *
 *  Adds a book to the inventory                     *
 *****************************************************/
void addBook(BookCollection *b)
{
	cout << "\nYou selected Add Book.\n\n";

	try
	{
		b->addBook();
	} // end try
	catch (exception& e)
	{
		cout << e.what() << endl;;
	} // end catch

} // end function addBook

/*****************************************************
 *                   editBook                        *
 *  Called by: invMenu()                             *
 *  Modifies a book inventory record                 *
 *****************************************************/
void editBook(BookCollection *b)
{
	cout << "\nYou selected Edit Book.\n\n";
	b->editBook();
} // end function editBook

/*****************************************************
 *                  deleteBook                       *
 *  Called by: invMenu()                             *
 *  Deletes a book from the inventory                *
 *****************************************************/
void deleteBook(BookCollection *b)
{
	cout << "\nYou selected Delete Book.\n\n";
	b->deleteBook();
} // end function deleteBook


// end is near
