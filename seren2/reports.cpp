/*
@file reports.cpp
@class Menu

@author Jamie Tudor
*/
/*****************************************************
 *                 reports                           *
 *  Called by main()                                 *
 *  Allows the user to select a report               *
 *****************************************************/

#include "mainmenu.h"
#include <iostream>
#include <string>

using namespace std;

//Function prototypes for subfunctions called by reports()
void repListing(BookCollection *b);
void repWholesale(BookCollection *b);
void repRetail(BookCollection *b);
void repQty(BookCollection *b);
void repCost(BookCollection *b);
void repAge(BookCollection *b);

/*
	This function allows the user to print reports of the book inventory.
*/
void Menu::reports()
{
	int choice = 0;     // Stores user's report choice
	string input;		// For user input
	
	do
	{	// Display company name and screen title
		cout << "\n\n\n      Serendipity Booksellers\n";
		cout << "              Reports\n\n\n";
        
		// Display information items
		cout << "   1. Inventory Listing\n";
		cout << "   2. Inventory Wholesale Value\n";
		cout << "   3. Inventory Retail Value\n";
		cout << "   4. Listing by Quantity\n";
		cout << "   5. Listing by Cost\n";
		cout << "   6. Listing by Age\n";
		cout << "   7. Return to the Main Menu\n\n";
        
		// Display prompt and get user's choice
		cout << "   Enter Your Choice: ";
		cin  >> choice;
        
		// Validate user's entry
		while (choice < 1 || choice > 7)
		{
			cout << "\n   Please enter a number in the range 1 - 7. ";
			getline(cin, input);
			choice = atoi(input.c_str());
		} // end while
        
		// Choose a report
		switch (choice)
		{
			case 1: repListing(books);
                break;
			case 2:	repWholesale(books);
                break;
			case 3:	repRetail(books);
                break;
			case 4:	repQty(books);
                break;
			case 5:	repCost(books);
                break;
			case 6:	repAge(books);						
		} // end switch
	} while (choice != 7);  // end doWhile
} // end function reports


/********** Subfunctions called by reports ***********/
/*****************************************************/

/*****************************************************
 *                 repListing                        *
 *  Called by: reports()                             *
 *  Lists records of all books in the inventory      *
 *****************************************************/
void repListing(BookCollection *b)
{
	cout << "\nYou selected Inventory Listing.\n\n";
	b->repListing();
} // end function repListing

/*****************************************************
 *                 repWholesale                      *
 *  Called by: reports()                             *
 *  Reports inventory wholesale information          *
 *****************************************************/
void repWholesale(BookCollection *b)
{
	cout << "\nYou selected Inventory Wholesale Value.\n\n";
	b->repWholesale();
} // end function repWholeSale

/*****************************************************
 *                 repRetail                         *
 *  Called by: reports()                             *
 *  Reports inventory retail information             *
 *****************************************************/
void repRetail(BookCollection *b)
{
	cout << "\nYou selected Inventory Retail Value.\n\n";
	b->repRetail();
} // end function repRetail

/*****************************************************
 *                    repQty                         *
 *  Called by: reports()                             *
 *  Reports on inventory quantity on hand            *
 *****************************************************/
void repQty(BookCollection *b)
{
	cout << "\nYou selected Listing by Quantity.\n\n";
	b->repQty();
} // end function repQty

/*****************************************************
 *                    repCost                        *
 *  Called by: reports()                             *
 *  Reports wholesale cost information on books in   *
 *  inventory -- sorted by wholesale cost            *
 *****************************************************/
void repCost(BookCollection *b)
{
	cout << "\nYou selected Listing by Cost.\n\n";
	b->repCost();
} // end function repCost

/*****************************************************
 *                     repAge                        *
 *  Called by: reports()                             *
 *  Reports book information based on the date an    *
 *  item was added to the inventory                  *
 *****************************************************/
void repAge(BookCollection *b)
{
	cout << "\nYou selected Listing by Age.\n\n";
	b->repAge();
} // end function repAge

// The end is near
