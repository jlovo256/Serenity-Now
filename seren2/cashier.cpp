/*
@file cashier.cpp
@class Menu

@author Jamie Tudor
*/
/*****************************************************
 *                   cashier                         *

 *  Called by: main()                                *
 *  Handles a book sale                              *
 *****************************************************/

#include "mainmenu.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "BookCollection.h"
#include "BookData.h"

using namespace std;


void Menu::cashier()
{
	string date;			 // User entered date in mm/dd/yy form
    string ISBNnumber;       // ISBN number of ordered book
	string input;			 // User input
	char   rightBook = 'Y';  // Is this the right book
	char   moreBook = 'Y';	 // Ask the user if he wants to add another book
	int    numBooks;		 // Quantity of this title ordered
    double subTotal = 0;     // Price before adding tax
    double taxRate = .06;    // Sales tax rate
    double taxAmt;           // Sales tax amount on this purchase
    double totalPrice;       // Total price of books plus tax
	char   doAgain;			 // 'y' or 'n' user reply to loop again question
	list<BookData> buyMe;	 // To hold the books the user will buy
	vector<int> numB;		 // To hold the quant of books
	list<BookData>::iterator position;


	do
	{	// Display company name and screen title
		cout << "\n\n\n   Serendipity Booksellers\n"
        << "   Cashier Module\n\n";
		cout << endl;

		// Prompt user to input book information
		cout << "   Date: ";

        // (the menu choice if we just entered this
        // function or a 'y' or 'Y' if we just looped).
		getline(cin, date);
        
		// do while the user wants to add more books
		do
		{
			// get quant of books
			cout << "   Quantity of Book: ";
			getline(cin, input);
			numBooks = atoi(input.c_str());

			// if the user enters a dumb number
			while (numBooks <= 0)
			{
				cout << "   Enter a positive number: ";
							getline(cin, input);
				numBooks = atoi(input.c_str());
			} // end while
        
			// get the ISBN
			cout << "   ISBN: ";
			getline(cin, ISBNnumber);

			list<BookData>::iterator pos = books->lookupIsbn(ISBNnumber);

			position = books->displayIsbn(pos, numBooks);

			if (books->booksAvailable(pos, numBooks))
			{
				//position = books->displayIsbn(pos, numBooks);
				
				BookData tempB;

				tempB.setTitle(position->getTitle());
				tempB.setAuthor(position->getAuthor());
				tempB.setIsbn(position->getIsbn());
				tempB.setPublisher(position->getPublisher());
				tempB.setDateAdded(position->getDateAdded());
				tempB.setQuantity(position->getQuantity());
				tempB.setWholesaleCost(position->getWholesaleCost());
				tempB.setRetailPrice(position->getRetailPrice());

				// add to the list
				buyMe.push_back(tempB);
				numB.push_back(numBooks);

				int newQ = position->getQuantity() - numBooks;
				position->setQuantity(newQ);


			} // end if

			//// if the ISBN wasnt valid
			//if (pos)
			//{
			//	cout << "   Not a valid ISBN number." << std::endl;
			//} // end if
			//else
			//{
				//// display book info
				//books->operator[](pos).bookInfo();

			//	// ask if its the right book
			//	cout << "   Is this the right book? (y/n)" << endl;
			//	getline(cin, input);
			//	rightBook = input.at(0);

			//	// if it is the add the book to the users total
			//	if (rightBook == 'Y' || rightBook == 'y')
			//	{
			//		// check to see if there are books available
			//		if (books->operator[](pos).getQuantity() > numBooks)
			//		{
			//			cout << "   Adding book" << endl;
			//			// Add the book to the vector
			//			buyMe.push_back(books->operator[](pos));
			//			numB.push_back(numBooks);

			//			int newQ = books->operator[](pos).getQuantity()
			//				- numBooks;
			//			books->operator[](pos).setQuantity(newQ);
			//		} // end if
			//		else
			//		{
			//			cout << "Not enough books available."  << endl;
			//		} // end else
			//		
			//	} // end if

			//} // end else

			// ask the user if he would like to enter another book
			cout << "   Would you like to add another book? (y/n)" << endl;
			getline(cin, input);
			moreBook = input.at(0);

		} while (moreBook == 'y' || moreBook == 'Y'); // do end while
        
		list<BookData>::iterator iter = buyMe.begin();

		// Perform calculations
		for (unsigned int index = 0; index < buyMe.size(); index++)
		{
			subTotal += iter->getRetailPrice() * numB[index];
			iter++;
		} // end for

		// Calculate tax and total
		taxAmt = subTotal * taxRate;
		totalPrice = subTotal + taxAmt;
        
		// Display company name
		cout << "\n\n\n\n   Serendipity Booksellers\n\n";
        
		// Display date
		cout << "   Date: " << date << "\n\n";
        
		// Display headings
		cout << "   Qty ISBN           Title                       Price      Total\n";
		cout << "   _______________________________________________________________\n\n";
        
		iter = buyMe.begin();

		// Display order information
		for (unsigned int k = 0; k < buyMe.size(); k++)
		{
			cout << fixed  << showpoint << setprecision(2);
			cout << setw(5)  << numB[k]  << "  " << left
				<< setw(15) << iter->getIsbn()
			<< setw(24) << iter->getTitle() << " $ " << right
			<< setw(6)  << iter->getRetailPrice() << "   $ "
			<< setw(6)  << iter->getRetailPrice() * numB[k]  
			<< endl << endl << endl;
			iter++;
		} // end for
        
		// Display footer information
		cout << "                      Subtotal                 $ "
        << setw(6) << subTotal << endl;
		cout << "                      Tax                      $ "
        << setw(6) << taxAmt << endl;
		cout << "                      Total                    $ "
        << setw(6) << totalPrice << endl << endl << endl;
        
		// clear the vectors and tax and total
		buyMe.clear();
		numB.clear();
		subTotal = 0;
		taxAmt = 0;
		totalPrice = 0;
		// Ask user if the module should be repeated
		cout << "   Do you wish to process another transaction? (y/n) ";
		getline(cin, input);
		doAgain = input.at(0);

		// Consume line
		cout << endl;

	} while (doAgain == 'y' || doAgain == 'Y');  // end do while
    
	cout << endl;

	cout << "\n\n   Thank You For Shopping at Serendipity!\n\n";

} // end function cashier

// the end is near
