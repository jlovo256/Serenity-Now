/**
@file BookCollection.h
@class BookBookCollection

@brief The main data structure of the bookseller POS,   
	representing an array of BookData objects

@note An instance of this class is initialized in Menu

@author Jamie Tudor

 **/

#ifndef BOOKCOLLECTION_H
#define BOOKCOLLECTION_H

#include <list>
#include <string>
#include <vector>
#include <fstream>
#include "BookData.h"
// don't use namespace std in your headers, use std:: like below

/*
	This is the BookCollection class.
*/
class BookCollection
{   
	// static members and list of books
	static const int WIDTH = 16;
	std::list<BookData> bookList;
	std::list<BookData>::iterator findBook(std::string);

	public:
		// constructor
		BookCollection();
		// destructor
		~BookCollection();

		// functions for editting BookData objects within array
		void addBook();
		void deleteBook();
		void editBook();
		void lookUpBook();

		// some mysterious functions
		std::list<BookData>::iterator lookupIsbn(std::string);
		// now more useful
		std::list<BookData>::iterator displayIsbn(std::list<BookData>::iterator, int num);
		bool booksAvailable(std::list<BookData>::iterator, int num);

		// an override so the functions of the BookData objects can be accessed
		//BookData & operator[](int i) {return bookList; }

		// Reporting functions from chapter 10
		void repListing();
		void repWholesale();
		void repRetail();
		void repQty();
		void repCost();
		void repAge();

	private:
		// Auxillary functions for sorting
		//void sortByWholeSale();
		//void sortByWholeSale(
		//	std::list<BookData>::iterator, std::list<BookData>::iterator,
		//	unsigned int);
		//std::list<BookData>::iterator partition(
		//	std::list<BookData>::iterator, std::list<BookData>::iterator,
		//	unsigned int );
		//void sortByRetail();
		//void sortByQty();
		//void sortByQty(int);
		//void sortByAge();

		// Auxillary functions for matching
		void match(std::string title, std::vector<std::list<BookData>::iterator>&found);
		void partialMatch(std::string title, std::vector<std::list<BookData>::iterator>&found);
		void displayBooks(std::vector<std::list<BookData>::iterator>&);

		// Auxillary functions for loading and storing
		void load(std::fstream &);
		void store(std::fstream &);


}; //end BookCollection class
//add "end" and class name for quick reference

#endif //endif BOOKCOLLECTION_H
//add endif file name in comment, for quick reference