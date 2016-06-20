/*
@file BookCollection.cpp
@class Book Collection

@brief The main data structure of the bookseller POS,   
	representing an array of BookData objects

@author Jamie Tudor
*/

#include "BookCollection.h"
#include "BookData.h"
#include "BookDataBinaryTree.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <exception>


/*
	This is the no args default constructor for BookCollection.  It attempts
	to read BookData objects from a binary file and creates one if it does not
	exist.
*/
BookCollection::BookCollection()
{
	// create a file object
	std::fstream binFile;

	// filename is always Serendipity
	std::string fileName = "Serendipity.data";

	// Open the file for binary input
	binFile.open(fileName, std::ios::binary | std::ios::in);
	
	if (!binFile)
	{
		std::cout << "File does not exist. Creating new." << std::endl;

	} // end if
	else
	{
		load(binFile);
	} // end else

	// don't forget to close your file
	binFile.close();

} // end constructor

/*
	This is the destructor for BookCollection.  It outputs the current array
	of BookData objects to a binary file.
*/
BookCollection::~BookCollection()
{
	// create a file object
	std::fstream binFile;

	// filename is always Serendipity
	std::string fileName = "Serendipity.data";

	// Open or create the file for binary outtput
	binFile.open(fileName, std::ios::binary | std::ios::out);

	// Store the BookData info
	store(binFile);

	// don't forget to close your file
	binFile.close();

} // end destructor

		/*
		  This function searches the array, attempting to locate a book whose
		  title or ISBN number match the string passes in.  If it finds a match,
		  the array subscript if that book object is returned.  If it does not,
		  -1 is returned.

		  Checked it.  Looks good.
		*/
		std::list<BookData>::iterator BookCollection::findBook(std::string input)
		{
			// create iterator
			std::list<BookData>::iterator iter = bookList.begin();
			bool found = false;		// Flag to indicate if found
			unsigned int index = 0;

			// search through array
			while (!found && index < bookList.size())
			{
				// stop if found
				if (iter->getTitle() == input || iter->getIsbn() == input)
				{
					found = true;
					return iter;
				} // end if

				// increment iterator
				iter++;
				index++;
			} // end while

			return iter = bookList.end();

		} // end function findBook

		/*
		  First this function should search through the BookData class array for
		  an empty object.  Use the isEmpty member to loacate an empty object.
		  If the no empty object is found, it means the array is full.  In that
		  case, the function should dispay a message indicating that no more 
		  books may be added to the inventory.  The should then return.

		  Checked it.  Looks good.
		*/
		void BookCollection::addBook()
		{
			///*
			//	Exception class for addBook.  Extends exception
			//*/
			//class TooManyBooks: public std::exception
			//{
			//	virtual const char* what() const throw()
			//	{
			//		return "No space available.";
			//	} // end function
			//}; // end class TooManyBooks

			std::string input;		// To hold user string input.
			int iinput;			// To hold user int input
			double dinput;		// To hold user double input
			BookData book;		// To hold a book that will be put into the list

			// Get the titles from the user and add it to the book object.
			std::cout << "Enter the name of the book: ";
			std::getline(std::cin, input);
			book.setTitle(input);
			std::cout << std::endl;

			// Get the isbns from the user and add them to the book object
			std::cout << "Enter the isbn of the book: ";
			std::getline(std::cin, input);
			book.setIsbn(input);
			std::cout << std::endl;

			// Get the authors of the books and add them to the book object
			std::cout << "Enter the author of the book: ";
			std::getline(std::cin, input);
			book.setAuthor(input);
			std::cout << std::endl;

			// Get the publishers of the book
			std::cout << "Enter the publisher of the book: ";
			std::getline(std::cin, input);
			book.setPublisher(input);
			std::cout << std::endl;

			// Get the date added of the book
			std::cout << "Enter the date added of the book: ";
			std::getline(std::cin, input);
			book.setDateAdded(input);
			std::cout << std::endl;

			// Get the quantity of the book
			std::cout << "Enter the quantity of the book: ";
			std::getline(std::cin, input);
			iinput = atoi(input.c_str());
			book.setQuantity(iinput);
			std::cout << std::endl;

			// Get the wholesale cost of the book
			std::cout << "Enter the wholesale cost of the book: ";
			std::getline(std::cin, input);
			dinput = atof(input.c_str());
			book.setWholesaleCost(dinput);
			std::cout << std::endl;

			// Get the retail price of the book
			std::cout << "Enter the retail price of the book: ";
			std::getline(std::cin, input);
			dinput = atof(input.c_str());
			book.setRetailPrice(dinput);
			std::cout << std::endl;

			// Insert the BookData object into the list
			bookList.push_back(book);

			//} // end if
			//else
			//{
			//	throw TooManyBooks();
			//} // end else

		} // end function addBook

		/*
		  This function deletes a book from the array by setting setting the 
		  m_empty member to true.

		  Checked it.  Looks good.
		*/
		void BookCollection::deleteBook()
		{
			std::string input;		// To hold user string input.
			char choice;			// To hold the user's choice
			std::list<BookData>::iterator pos;	// iterator

			// Ask the user for the title or ISBN of the book
			std::cout << "Please enter the title or ISBN of the "
				<< "book." << std::endl;
			std::getline(std::cin, input);

			// pass the user input to the findBook function
			pos = findBook(input);

			// If the book wasn't found
			if (pos == bookList.end())
			{
				std::cout << "The book was not found" << std::endl;
			} // end if
			// Otherwise
			else
			{
				// display the book's info
				pos->bookInfo();

				// Confirm
				std::cout << "Are you sure you want to delete this book?  "
					<< " Press y to confirm or any other key to quit."
					<< std::endl;
				std::getline(std::cin, input);
				choice = input.at(0);

				if (choice == 'y')
				{
					pos = bookList.erase(pos);
				} // end if
				
			} // end else

		} // end function deleteBook

		/*
		  This function edits a BookData object
		  Checked it.  Looks good.
		*/
		void BookCollection::editBook()
		{
			std::string input;		// To hold user string input.
			int iinput;		// To hold user int input
			double dinput;		// To hold user double input
			std::list<BookData>::iterator pos;	// To hold the postion of the book
			int choice = 0;			// Stores user's menu choice

			// Ask the user for the title or ISBN of the book
			std::cout << "Please enter the title or ISBN of the "
				<< "book." << std::endl;
			std::getline(std::cin, input);

			// pass the user input to the findBook function
			pos = findBook(input);

			// If the returned position is -1 then the book wasn't found
			if (pos == bookList.end())
			{
				std::cout << "The book was not found" << std::endl;
			} // end if
			// Otherwise
			else
			{
				// display the book's information
				pos->bookInfo();

				do
				{
					// Find out which field the user wants to edit.
					std::cout << "Select the field to edit or press exit menu."
						<< std::endl;
					std::cout << "   1. Book title\n";
					std::cout << "   2. ISBN number\n";
					std::cout << "   3. Author's name\n";
					std::cout << "   4. Publisher's name\n";
					std::cout << "   5. The date the book was added to inventory\n";
					std::cout << "   6. The quantity of this book\n";
					std::cout << "   7. The wholesale cost of the book\n";
					std::cout << "   8. The retail price of the book\n";
					std::cout << "   9. Exit\n\n";

					// Display prompt and get user's choice
					std::cout << "   Enter your choice: ";
					std::getline(std::cin, input);
					choice = atoi(input.c_str());
        
					// Validate user's entry
					while (choice < 1 || choice > 9)
					{
						std::cout << "\n   Please enter a number in the "
							<< "range 1 - 9. ";
						std::getline(std::cin, input);
						choice = atoi(input.c_str());
					} // end while
		
					switch (choice)
					{
						case 1: 
							// Get the title from the user
							std::cout << "Enter the name of the book: ";
							std::getline(std::cin, input);
							pos->setTitle(input);
							std::cout << std::endl;
							break;
						case 2:	
							// Get the isbn from the user
							std::cout << "Enter the isbn of the book: ";
							std::getline(std::cin, input);
							pos->setIsbn(input);
							std::cout << std::endl;
						break;
						case 3:	
							// Get the author of the books 
							std::cout << "Enter the author of the book: ";
							std::getline(std::cin, input);
							pos->setAuthor(input);
							std::cout << std::endl;
							break;
						case 4:
							// Get the publisher of the book
							std::cout << "Enter the publisher of the book: ";
							std::getline(std::cin, input);
							pos->setPublisher(input);
							std::cout << std::endl;
							break;
						case 5:
							// Get the date added of the book
							std::cout << "Enter the date added of the book: ";
							std::getline(std::cin, input);
							pos->setDateAdded(input);
							std::cout << std::endl;
							break;
						case 6:
							// Get the quantity of the book
							std::cout << "Enter the quantity of the book: ";
							std::getline(std::cin, input);
							iinput = atoi(input.c_str());
							pos->setQuantity(iinput);
							std::cout << std::endl;
							break;
						case 7:
							// Get the wholesale cost of the book
							std::cout << "Enter the wholesale cost of " 
								<< "the book: ";
							std::getline(std::cin, input);
							dinput = atof(input.c_str());
							pos->setWholesaleCost(dinput);
							std::cout << std::endl;
							break;
						case 8:
							// Get the retail price of the book
							std::cout << "Enter the retail price of the book: ";
							std::getline(std::cin, input);
							dinput = atof(input.c_str());
							pos->setRetailPrice(dinput);
							std::cout << std::endl;
							break;

					} // end switch
				} while (choice != 9); // end do while

			} // end else

		} // end function editBook

		/*
			This functions finds a BookData object
			Checked it.  Looks good.
		*/
		void BookCollection::lookUpBook()
		{
			// To hold the indices of found books
			std::vector<std::list<BookData>::iterator> found;
			std::vector<std::list<BookData>::iterator> partialfound;
			std::string input;		// To hold user string input.

			// Ask the user for the title or ISBN of the book
			std::cout << "Please enter the title of the "
				<< "book." << std::endl;
			std::getline(std::cin, input);
			std::cout << std::endl;

			// pass the user input to the match and partial match function
			match(input, found);
			partialMatch(input, partialfound);

			if (found.empty())
			{
				// go through the partialfound vector
				for (unsigned int index = 0; index < partialfound.size(); index++)
				{
					// add the position of the book to found
					found.push_back(partialfound[index]);
				} // end for
			} // end if
			else
			{
				// go through the partialfound vector
				for (unsigned int index = 0; index < partialfound.size(); index++)
				{
					// go through the found vector
					for (unsigned int count = 0; count < found.size(); count++)
					{
						// initialze flag
						bool flag = false;

						// if the elements are equal
						if (found[index] == partialfound[count])
						{
							// set flag to true
							flag = true;
						} // end if

						// if it wasn't found in found
						if (!flag)
						{
							// add the position of the book to found
							found.push_back(partialfound[count]);
						} // end if
					} // end for
				} // end for
			} // end else

			// If nothing was found
			if (found.empty() && partialfound.empty())
			{
				std::cout << "Your query did not match any titles." 
					<< std::endl;
			} // end if
			// Otherwise
			else
			{
				// display the matches and patial matches
				std::cout << "Found: "  << std::endl;
				displayBooks(found);
				//displayBooks(partialfound);
			}

		} // end function lookUpBook

		/*
		  This function returns the position in the array of the BookData
		  object that matches the passed string.
		  Checked it. Looks good.
		  Be careful with that end ptr
		*/
		std::list<BookData>::iterator 
			BookCollection::lookupIsbn(std::string isbn)
		{
			unsigned int index = 0;		// The starting position of the search
			bool found = false;		// Flag to indicate if found

			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// search through list
			while (index < bookList.size() && !found)
			{
				// stop if found
				if (pos->getIsbn() == isbn)
				{
					found = true;
					return pos;
				} // end if

				// increment index
				pos++;
				index++;

			} // end while

			// return the array position
			return pos = bookList.end();
		} // end function lookUpIsbn

		/*
		  I'm not sure what is the point of this function.
		  Checked
		*/
		std::list<BookData>::iterator BookCollection::displayIsbn(std::list<BookData>::iterator iter,
			int num)
		{
			char rightBook = 'Y';  // Is this the right book
			std::string input;		// to hold user input

			/// a book?
			if (iter == bookList.end())
			{
				std::cout << "   Not a valid ISBN number." << std::endl;
			} // end if
			else
			{
				iter->bookInfo();

				std::cout << "   Is this the right book? (y/n)" << std::endl;
				std::getline(std::cin, input);
				rightBook = input.at(0);

				// if it is the add the book to the users total
				if (rightBook == 'Y' || rightBook == 'y')
				{
					if (booksAvailable(iter, num))
					{
						return iter;
					} // end if
					else
					{
						std::cout << "Not enough books available."  << std::endl;
						return bookList.end();
					} // end if
					//// check to see if there are books available
					//if (books->operator[](pos).getQuantity() > numBooks)
					//{
					//	std::cout << "   Adding book" << endl;
					//	// Add the book to the vector
					//	buyMe.push_back(books->operator[](pos));
					//	numB.push_back(numBooks);

					//	int newQ = books->operator[](pos).getQuantity()
					//		- numBooks;
					//	books->operator[](pos).setQuantity(newQ);
					//} // end if
					//else
					//{
					//	std::cout << "Not enough books available."  << std::endl;
					//} // end else
					
				} // end if

			} // end else

			
			//// To hold the position of the found book
			//std::list<BookData>::iterator pos = bookList.begin();

			//for (unsigned int index = 0; index < bookList.size(); index++)
			//{
			//	std::cout << std::left << std::setw(WIDTH) << "Title: " 
			//		<< pos->getTitle() << std::endl;
			//	std::cout << std::left << std::setw(WIDTH) << "ISBN: " 
			//		<< pos->getIsbn() << std::endl;
			//	std::cout << std::endl;

			//	pos++;

			//} // end for
			return bookList.end();
			std::cout << std::endl;

		} // end function displayIsbn

		/*
		  The booksAvailable() function determines whether there are any books
		  in the collection.

		  Checked it.  Looks good.
		*/
		bool BookCollection::booksAvailable(std::list<BookData>::iterator iter,
			int num)
		{
			
			//int available = 0;
			//// To hold the position of the found book
			//std::list<BookData>::iterator pos = bookList.begin();

			//for (unsigned int index = 0; index < bookList.size(); index++)
			//{
			//	// total up the quantity
			//	available += pos->getQuantity();
			//	pos++;
			//} // end for

			if (iter != bookList.end())
			{
				if (iter->getQuantity() - num < 0 && iter != bookList.end())
				{
					return false;
				} // end if
				else
				{
				return true;
				} // else
			} // end if
			else
			{
				return false;
			} // end else
		} // end function BooksAvailable
		
		/*
		  The repListing function should display a report listing all the books 
		  in the inventory.  The following information should be included in 
		  the report: title, ISBN number, author, publisher, date added to 
		  inventory, quantity on hand, wholesale cost, and retail price. The 
		  report should display an appropriate title. The function should fill
		  the screen with information and then ask the user to press a key to 
		  continue to the next screen.

		  Checked it.
		*/
		void BookCollection::repListing()
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// display title
			std::cout << std::endl;
			std::cout << "\tInventory Report" << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;


			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				std::cout << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Title:" 
					<< pos->getTitle() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Isbn:" << pos->getIsbn() 
					<< std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Author:" 
					<< pos->getAuthor() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Publisher:" 
					<< pos->getPublisher() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Date Added:" 
					<< pos->getDateAdded() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Quantity:" 
					<< pos->getQuantity() << std::endl;
				std::cout << std::fixed << std::showpoint << std::setprecision(2);
				std::cout << std::left << std::setw(WIDTH) << "Wholesale Cost:" 
					<< "$" << pos->getWholesaleCost() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Retail Price:" 
					<< "$" << pos->getRetailPrice() << std::endl;
				std::cout << std::endl;
				//pos->bookInfo();
				pos++;
				std::cout << std::endl;

				// Use for not windows
				std::cout << "Press ENTER twice to continue";
				std::cout << std::flush;
				std::cin.get();
				std::cin.clear();
				std::cin.ignore(80, '\n');

			} // end for

			std::cout << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

		} // end function repListing

		/*
		  The repWholesale function should display a report that lists the 
		  following information on all books in the inventory: title, ISBN 
		  number, quantity on hand, and wholesale cost. The report should 
		  display an appropriate title. The function should fill the screen 
		  with information and then ask the user to press a key to continue 
		  to the next screen. The last line of the report should give the total
		  wholesale value of the inventory (the sum of each book’s wholesale 
		  cost multiplied by the quantity on hand.)

		  Checked it. 
		*/
		void BookCollection::repWholesale()
		{
			double totalWholeSale = 0;

			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// display title
			std::cout << std::endl;
			std::cout << "\tWholeSale Report" << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

			//// new BNODE
			//BTREE treeWS;

			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				// add elements to it
				//treeWS.insert(pos);

				std::cout << std::left << std::setw(WIDTH) << "Title: " 
					<< pos->getTitle() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Isbn: " 
					<< pos->getIsbn() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Quantity: " 
					<< pos->getQuantity() << std::endl;
				std::cout << std::fixed << std::showpoint 
					<< std::setprecision(2);
				std::cout << std::left << std::setw(WIDTH) 
					<< "Wholesale Cost: " << "$"
					<< pos->getWholesaleCost() << std::endl;
				totalWholeSale += pos->getWholesaleCost() * 
					pos->getQuantity();
				std::cout << std::endl;

				pos++;

				// Use for not windows
				std::cout << "Press ENTER twice to continue";
				std::cout << std::flush;
				std::cin.get();
				std::cin.clear();
				std::cin.ignore(80, '\n');

				//// use for windows
				//system("PAUSE");

			} // end for

			 //display the tree
			//treeWS.inorder();

			std::cout << std::endl;
			std::cout << "\tTotal Wholesale Inventory Value: " 
				<< totalWholeSale << std::endl;
			std::cout << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout <<std::endl;
		} // end function repWholeSale

		/*
		  The repRetail function should display a report that lists the 
		  following information on all books in the inventory: title, ISBN 
		  number, quantity on hand, and retail price.  The report should 
		  display an appropriate title. The function should fill the screen
		  with information and then ask the user to press a key to continue to 
		  the next screen.  The last line of the report should give the total 
		  retail value of the inventory (the sum of each book’s retail price
		  multiplied by the quantity on hand.)

		  Checked it.
		*/
		void BookCollection::repRetail()
		{
			double totalRetail = 0;

			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			//// Sort the array
			//sortByRetail();

			// display title
			std::cout << std::endl;
			std::cout << "\tRetail Report" << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				std::cout << std::left << std::setw(WIDTH) << "Title: " 
					<< pos->getTitle() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Isbn: " 
					<< pos->getIsbn() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Quantity: " 
					<< pos->getQuantity() << std::endl;
				std::cout << std::fixed << std::showpoint 
					<< std::setprecision(2);
				std::cout << std::left << std::setw(WIDTH) 
					<< "Retail Price: " << "$" 
					<< pos->getRetailPrice() << std::endl;
				totalRetail += pos->getRetailPrice() * 
					pos->getQuantity();
				std::cout << std::endl;

				pos++;

				// Use for not windows
				std::cout << "Press ENTER twice to continue";
				std::cout << std::flush;
				std::cin.get();
				std::cin.clear();
				std::cin.ignore(80, '\n');

				//// use for windows
				//system("PAUSE");
			} // end for

			std::cout << std::endl;
			std::cout << "\tTotal Retail Price Inventory Value: " 
				<< totalRetail << std::endl;
			std::cout << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

		} // end function repRetail

		/*
		  The repQty function should display a report that lists the following 
		  information on all books in the inventory: title, ISBN number, and 
		  quantity on hand. The list should be sorted by quantity on hand in 
		  descending order (the books of the greatest quantity listed first). 
		  The report should display an appropriate title. The function should 
		  fill the screen with information and then ask the user to press a 
		  key to continue to the next screen.

		  checked.
		*/
		void BookCollection::repQty()
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// display title
			std::cout << std::endl;
			std::cout << "\tQuantity Report" << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

			//// Sort the books first
			//sortByQty();

			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				std::cout << std::left << std::setw(WIDTH) << "Title: " 
					<< pos->getTitle() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Isbn: " 
					<< pos->getIsbn() << std::endl;
				std::cout << std::left << std::setw(WIDTH) << "Quantity: " 
					<< pos->getQuantity() << std::endl;
				std::cout << std::endl;

				pos++;

				// Use for not windows
				std::cout << "Press ENTER twice to continue";
				std::cout << std::flush;
				std::cin.get();
				std::cin.clear();
				std::cin.ignore(80, '\n');

				//// use for windows
				//system("PAUSE");
			} // end for

			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;
		} // end function repQty

		/*
		  The repCost function should display a report that lists the following 
		  information on all books in the inventory: title, ISBN number, 
		  quantity on hand, and wholesale cost.  The list should be sorted by 
		  wholesale cost in descending order (the books of the greatest unit 
		  cost listed first). The report should display an appropriate title. 
		  The function should fill the screen with information and then ask 
		  the user to press a key to continue to the next screen.

		  checked
		*/
		void BookCollection::repCost()
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// display title
			std::cout << std::endl;
			std::cout << "\tWholeSale Cost Report" << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

			//// Sort the array
			//sortByWholeSale();

			// create a new tree
			BTREE treeWS;


			for (unsigned int index = 0; index <  bookList.size(); index++)
			{
			//	std::cout << std::left << std::setw(WIDTH) << "Title: " 
			//		<< pos->getTitle() << std::endl;
			//	std::cout << std::left << std::setw(WIDTH) << "Isbn: " 
			//		<< pos->getIsbn() << std::endl;
			//	std::cout << std::left << std::setw(WIDTH) << "Quantity: "
			//		<< pos->getQuantity() << std::endl;
			//	std::cout << std::fixed << std::showpoint 
			//		<< std::setprecision(2);
			//	std::cout << std::left << std::setw(WIDTH) 
			//		<< "Wholesale Cost: " << "$" 
			//		<< pos->getWholesaleCost() << std::endl;
			//	std::cout << std::endl;

				// add elements to it
				treeWS.insert(pos);

				pos++;

			//	// Use for not windows
			//	std::cout << "Press ENTER twice to continue";
			//	std::cout << std::flush;
			//	std::cin.get();
			//	std::cin.clear();
			//	std::cin.ignore(80, '\n');

			//		//// use for windows
			//		//system("PAUSE");
			} // end for

			// display the tree
			treeWS.inorder();

			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

		} // end function repCost

		/*
		  The repAge function should display a report that lists the following 
		  information on all books in the inventory: title, ISBN number, 
		  quantity on hand, and date added to the inventory. The list should 
		  be sorted by date added, in descending order (the books that have 
		  been in inventory longest will be listed first). The report should 
		  display an appropriate title. The function should fill the screen 
		  with information and then ask the user to press a key to continue to 
		  the next screen.

		  Checked.
		*/
		void BookCollection::repAge()
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// display title
			std::cout << std::endl;
			std::cout << "\tAge Report" << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;

			//// Sort by date added
			//sortByAge();

			for (unsigned int index = 0; index < bookList.size(); index++)
			{

					std::cout << std::left << std::setw(WIDTH) << "Title: " 
						<< pos->getTitle() << std::endl;
					std::cout << std::left << std::setw(WIDTH) << "Isbn: " 
						<< pos->getIsbn() << std::endl;
					std::cout << std::left << std::setw(WIDTH) << "Quantity: " 
						<< pos->getQuantity() << std::endl;
					std::cout << std::left << std::setw(WIDTH) << 
						"Date Added: " << pos->getDateAdded() << std::endl;
					std::cout << std::endl;

					pos++;

					// Use for not windows
					std::cout << "Press ENTER twice to continue";
					std::cout << std::flush;
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(80, '\n');

					//// use for windows
					//system("PAUSE");
			} // end for

			std::cout << "----------------------------------" << std::endl;
			std::cout << std::endl;
		} // end function repAge
		

		/*
		  This function sorts by wholesale.
		  This sort will demostrate a recursive quicksort.
		  Checked
		*/
		//void BookCollection::sortByWholeSale()
		//{
		//	// To hold the position of the found book
		//	std::list<BookData>::iterator start = bookList.begin();
		//	std::list<BookData>::iterator end = bookList.end();
		//	unsigned int startI = 0;
		//	unsigned int endI = bookList.size();
		//} // end function sortByWholeSale

		///*
		//	This is the private part of the recursive quicksort
		//	This function sorts by wholesale
		//*/
		//void BookCollection::sortByWholeSale(
		//	std::list<BookData>::iterator start, std::list<BookData>::iterator end,
		//	unsigned int startI, unsigned int endI)
		//{
		//	if (startI < endI)
		//	{
		//		// partition the array and get the pivot point.
		//		std::list<BookData>::iterator p = partition(start, end);

		//		// Sort the portion before the pivot point.
		//		sortByWholeSale(start, p-- , startI);

		//		// Sort the portion after the pivot point
		//		sortByWholeSale(p++ , end, endI);
		//	} // end if

		//} // end function sortByWholeSale

		///*
		//  This is for partitioning for the sortByWholeSale
		//  Checked
		//*/
		//std::list<BookData>::iterator BookCollection::partition(
		//	std::list<BookData>::iterator start, std::list<BookData>::iterator end,
		//	unsigned int unInt)
		//{
		//	// initialize pivotPosition
		//	std::list<BookData>::iterator pivotPosition = start;

		//	// The pivot element is taken to be the element at the start of the 
		//	// subrange to be partitioned.
		//	double pivotValue = start->getWholesaleCost();

		//	// Rearrange the rest of the array elements to partition the subrange
		//	// start to end.
		//	for (std::list<BookData>::iterator pos = start++; pos != bookList.end; pos++)
		//	{
		//		if (pos->getWholesaleCost() > pivotValue)
		//		{
		//			std::list<BookData>::iterator pivPosPlus;
		//			pivPosPlus = pos;
		//			pivotPosition++;

		//			// bk[pos] is the "current" item.
		//			// Swap the current item with item to the right of the pivot 
		//			// element
		//			std::swap(pivPosPlus, pos);

		//			// Swap the current item with the pivot element
		//			std::swap(pivotPosition, pivPosPlus);
		//			// Adjust the pivot position so it stays with the pivot element
		//			pivotPosition++;
		//		} // end if
		//	} // end for

		//	return pivotPosition;

		//} // end function partition

		/*
		  This function sorts by retail.
		  Try the insertion sort this time.
		  Checked
		*/
		//void BookCollection::sortByRetail()
		//{
		//	BookData *unsortedBook;	// The unsorted book
		//	BookData *scanSOBook;	// The unsorted book
		//	double unsortedValue;	// The first unsorted value

		//	std::list<BookData>::iterator scan;
		//	// To hold the position of the found book
		//	std::list<BookData>::iterator scanSO;
		//	// To hold the position of the found book
		//	std::list<BookData>::iterator pos = bookList.begin();

		//	pos++;

		//	// The outer loop steps the index variable through each subscript 
		//	// in the array, starting at 1.  The portion of the array 
		//	// consisting of element 0 by itself is already sorted
		//	for (unsigned int index = 1; index < bookList.size(); index++)
		//	{
		//		// The first element outside the sorted portion is 
		//		// array[index].  Store the value of this element in 
		//		// unsortedValue.
		//		unsortedValue = pos->getRetailPrice();
		//		unsortedBook = &*pos;

		//		// Start scan at the subscript of the first element in the 
		//		// still unsorted part.
		//		scan = pos;
		//		scanSO = pos;
		//		scanSO--;

		//		// Move the first element in the still unsorted part into 
		//		// its proper position within the sorted part.
		//		while (scan != bookList.end() && scanSO->getRetailPrice() < unsortedValue)
		//		{
		//			scanSOBook = &*scanSO;
		//			bookList.insert(scanSO, *scanSOBook);
		//			scan--;
		//		} // end while

		//		// Insert the unsorted book in its proper position within 
		//		// the sorted part
		//		

		//		pos++;

		//	} // end for
		//} // end function sortByRetail

		///*
		//  This function will sort the array by quantity.  This one will 
		//  demostrate a recursive insertion sort.
		//  Checked
		//*/
		//void BookCollection::sortByQty()
		//{
		//	sortByQty(0);
		//} // end method testerSortByQty

		///*
		//  The recursive function
		//  Checked
		//*/
		//void BookCollection::sortByQty(int start)
		//{
		//	static BookData unsortedBook;	// The unsorted book
		//	static double unsortedValue;	// The first unsorted value
		//	static int scan;				// Used to scan the array

		//	if ((start + 1) < MAX_BOOKS)
		//	{
		//		// The first element outside the sorted portion is 
		//		// array[index].  Store the value of this element 
		//		// in unsortedValue.
		//		unsortedValue = book[start + 1].getQuantity();
		//		unsortedBook = book[start + 1];

		//		// Start scan at the subscript of the first element 
		//		// in the still unsorted part.
		//		scan = start + 1;

		//		// Move the first element in the still unsorted part 
		//		// into its proper position within the sorted part.
		//		while (scan > 0 &&
		//			book[scan - 1].getQuantity() < unsortedValue)
		//		{
		//			book[scan] = book[scan - 1];
		//			scan--;
		//		} // end while

		//		book[scan] = unsortedBook;

		//		sortByQty(start + 1);

		//	} // end if

		//} // end method testerSortByQty

		///*
		//  Use the insertion sort to sort the books by date added
		//  Checked
		//*/
		//void BookCollection::sortByAge()
		//{
		//	BookData unsortedBook;				// The unsorted book
		//	std::string unsortedValue;			// The first unsorted value
		//	int scan;							// Used to scan the array
		//	std::string rearangeUnsortedValue;	// The first unsorted value

		//	std::list<BookData>::iterator pos = bookList.begin();

		//	// The outer loop steps the index variable through each subscript 
		//	// in the array, starting at 1.  The portion of the array 
		//	// consisting of element 0 by itself is already sorted
		//	for (int index = 1; index < bookList.size(); index++)
		//	{
		//		// The first element outside the sorted portion is 
		//		// array[index].  Store the value of this element in 
		//		// unsortedValue.
		//		unsortedValue = pos->getDateAdded();
		//		rearangeUnsortedValue = unsortedValue.substr(6,4) +
		//		unsortedValue.substr(0,2) + unsortedValue.substr(3,2);
		//		unsortedBook = bookList;

		//		// Start scan at the subscript of the first element in 
		//		// the still unsorted part.
		//		scan = index;

		//		// Move the first element in the still unsorted part into 
		//		// its proper position within the sorted part.
		//		while (scan > 0 && 
		//		(book[scan - 1].getDateAdded().substr(6,4) + 
		//		book[scan - 1].getDateAdded().substr(0,2) +
		//		book[scan - 1].getDateAdded().substr(3,2))
		//		< rearangeUnsortedValue)
		//		{
		//			book[scan] = book[scan - 1];
		//			scan--;
		//		} // end while

		//		// Insert the unsorted book in its proper position 
		//		// within the sorted part
		//		book[scan] = unsortedBook;

		//		pos++;

		//	} // end for
		//} // end function sortByAge

		/*
		  Looks for a exact match
		  Checked
		*/
		void BookCollection::match(std::string title, 
			std::vector<std::list<BookData>::iterator>&found)
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// look through the array of books
			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				// if the title matched the string
				if (title == pos->getTitle())
				{
					// add the index to the array
					found.push_back(pos);
				} // end if
				pos++;
			} // end for

		} // end function match

		/*
		  Looks for a partial match
		  Checked
		*/
		void BookCollection::partialMatch(std::string title, 
			std::vector<std::list<BookData>::iterator>&found)
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// creates a regular expression using the string that is passed 
			// and flags the expression to be case insensitive
			std::regex e(title, std::regex_constants::ECMAScript 
				| std::regex_constants::icase);

			// look through the array of books
			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				// if string matches a subtring of the title
				if (regex_search(pos->getTitle(), e))
				{
					// add the index to the array
					found.push_back(pos);
				} // end if
				pos++;
			} // end for
		} // end function partialMatch

		/*
		  This function can be used to display information of all books whose 
		  indices in the book array are stored in the vector
		  Checked
		*/
		void BookCollection::displayBooks(std::vector<std::list<BookData>::iterator>&found)
		{
			// look through the vector
			for(unsigned int index = 0; index < found.size(); index++)
			{
				// display the titles of the books
				std::cout << found[index]->getTitle() << std::endl;
			} // end for
		} // end method displayBooks

		/*
		  This function loads information from a binary file named
		  Serendipity.data
		  Checked
		*/
		void BookCollection::load(std::fstream &binFile)
		{
			// used to read 
			const int BUFFER_SIZE = 256;
			static char buffer[256];

			// create a book to hold the incoming info
			BookData tempB;

			// This is a marker so if the file is empty binFile.eof will return true
			char a;
			binFile.read(reinterpret_cast<char *>(&a), sizeof(a));

			while (!binFile.eof())
			{
				// get length and data for title
				int titleLength;
				binFile.read(reinterpret_cast<char *>(&titleLength), sizeof(int));
				// Read the data for the title into a local buffer
				binFile.read(buffer, titleLength);
				// Null terminate the buffer
				buffer[titleLength] = '\0';
				// get the title
				tempB.setTitle(buffer);

				// get length and data for the Isbn
				int isbnLength;
				binFile.read(reinterpret_cast<char *>(&isbnLength), sizeof(int));
				binFile.read(buffer, isbnLength);
				buffer[isbnLength] = '\0';
				tempB.setIsbn(buffer);

				// get length and data for the author
				int authorLength;
				binFile.read(reinterpret_cast<char *>(&authorLength), sizeof(int));
				binFile.read(buffer, authorLength);
				buffer[authorLength] = '\0';
				tempB.setAuthor(buffer);

				// get length and data for the publisher
				int pubLength;
				binFile.read(reinterpret_cast<char *>(&pubLength), sizeof(int));
				binFile.read(buffer, pubLength);
				buffer[pubLength] = '\0';
				tempB.setPublisher(buffer);

				// get length and data for the date added
				int daLength;
				binFile.read(reinterpret_cast<char *>(&daLength), sizeof(int));
				binFile.read(buffer, daLength);
				buffer[daLength] = '\0';
				tempB.setDateAdded(buffer);

				// get length and data for the quantity
				int quantIn;
				binFile.read(reinterpret_cast<char *>(&quantIn), sizeof(quantIn));
				tempB.setQuantity(quantIn);

				// get length and data for the wholesale
				double wsIn;
				binFile.read(reinterpret_cast<char *>(&wsIn), sizeof(wsIn));
				tempB.setWholesaleCost(wsIn);

				// get length and data for the retail price
				double rpIn;
				binFile.read(reinterpret_cast<char *>(&rpIn), sizeof(rpIn));
				tempB.setRetailPrice(rpIn);

				// get m_empty
				//bool e;
				//binFile.read(reinterpret_cast<char *>(&e), sizeof(e));
				//if (e)
				//{
				//	book[index].isEmpty();
				//} // end if
				//else
				//{
				//	book[index].insertBook();
			
				//} // end while
				if (!binFile.eof())
				{
					bookList.push_back(tempB);
				} // end if

			} // end for
		} // end function load

		/*
		  This function stores information in a binary file named
		  Serendinpity.data
		  Checked
		*/
		void BookCollection::store(std::fstream &binFile)
		{
			// To hold the position of the found book
			std::list<BookData>::iterator pos = bookList.begin();

			// a zero
			char a = 'a';
			binFile.write(reinterpret_cast<char *>(&a), sizeof(a));

			for (unsigned int index = 0; index < bookList.size(); index++)
			{
				// Write the data
				// title
				int wtitleLength = pos->getTitle().length();
				binFile.write(reinterpret_cast<char *>(&wtitleLength), sizeof(int));
				binFile.write(pos->getTitle().data(), wtitleLength);
				// isbn
				int wisbnLength = pos->getIsbn().length();
				binFile.write(reinterpret_cast<char *>(&wisbnLength), sizeof(int));
				binFile.write(pos->getIsbn().data(), wisbnLength);
				// author
				int wauLength = pos->getAuthor().length();
				binFile.write(reinterpret_cast<char *>(&wauLength), sizeof(int));
				binFile.write(pos->getAuthor().data(), wauLength);
				// publisher
				int wpubLength = pos->getPublisher().length();
				binFile.write(reinterpret_cast<char *>(&wpubLength), sizeof(int));
				binFile.write(pos->getPublisher().data(), wpubLength);
				// date added
				int wdaLength = pos->getDateAdded().length();
				binFile.write(reinterpret_cast<char *>(&wdaLength), sizeof(int));
				binFile.write(pos->getDateAdded().data(), wdaLength);
				// quantity
				int quant = pos->getQuantity();
				binFile.write(reinterpret_cast<char *>(&quant), sizeof(quant));
				// getWholesalePrice
				double ws = pos->getWholesaleCost();
				binFile.write(reinterpret_cast<char *>(&ws), sizeof(ws));
				// retail price
				double rp = pos->getRetailPrice();
				binFile.write(reinterpret_cast<char *>(&rp), sizeof(rp));

				pos++;
	} // end for
		} // end function store


// the end is near
