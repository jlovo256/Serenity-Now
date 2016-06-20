/**
@file BookData.h
@class BookData

@brief The main data structure of the bookseller POS,
	representing a single book publication and the
	quantity in stock.

@note This class declaration is adapted from the one
	given in Part 7 of the Serendipity Booksellers
	project. The coding style and some names have
	been changed.

 */

/* Note that all other comments below are regular comments,
and won't show up in the documentation. */
#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <string>
// don't use namespace std in your headers, use std:: like below


class BookData //capitalize all words in class name
{   //put class curly braces on new lines
	//indent one tab space (4 chars) for access specifiers
	//put public implementation first for better abstraction
	static const int WIDTH = 16;

	public:
		//indent two tab spaces for members
		BookData();

		//add line break after constructors/destructors
		void setTitle( std::string title ); //use variable names
		void setIsbn( std::string isbn );
		void setAuthor( std::string author );
		void setPublisher( std::string publisher);
		void setDateAdded( std::string date );
		void setQuantity( int qty );
		void setWholesaleCost( double cost );
		void setRetailPrice( double price );

		// add line break between sets and gets
		std::string getTitle();
		std::string getIsbn();
		std::string getAuthor();
		std::string getPublisher();
		std::string getDateAdded();
		int getQuantity();
		double getWholesaleCost();
		double getRetailPrice();

		void bookInfo();

	private:
		std::string m_bookTitle; //use m_ prefix for member variables,
		std::string m_isbn; //and m_pName for any pointer members
		std::string m_author;
		std::string m_publisher;
		std::string m_dateAdded;
		int m_qtyOnHand;
		double m_wholesaleCost;
		double m_retailPrice;

}; //end BookData class
//add "end" and class name for quick reference

#endif //endif BOOKDATA_H
//add endif file name in comment, for quick reference
