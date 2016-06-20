/**
@file BookData.cpp
@class BookData

@brief The main data structure of the bookseller POS,
	representing a single book publication and the
	quantity in stock.

@note This is the source file.

@author Jamie Tudor
 */
#include "BookData.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

		//indent two tab spaces for members
		/*
		 * The default no-args constructor.  So the sorters don't do strange
		   things, set all the fields to 0 or blank.
		 */
		BookData::BookData()
		{
			// Make everything blank or zero
			setTitle(" ");
			setIsbn(" ");
			setAuthor(" ");
			setPublisher(" ");
			setDateAdded("01-01-1900");
			setQuantity(0);
			setWholesaleCost(0);
			setRetailPrice(0);

		} // end constructer

		/*
		 * This function should accept a string object
		 */
		void BookData::setTitle( std::string title )
		{
			m_bookTitle = title;
		} // end function setTitle

		/*
		 * This function should accept a string object
		 */
		void BookData::setIsbn( std::string isbn )
		{
			m_isbn = isbn;
		} // end function setIsbn

		/*
		 * This function should accept a string object.
		 */
		void BookData::setAuthor( std::string author )
		{
			m_author = author;
		} // end function setAuthor

		/*
		 * This function should accept a string object.
		 */
		void BookData::setPublisher( std::string publisher)
		{
			m_publisher = publisher;
		} // end function setPublisher

		/*
		 * This function should accept a string object.
		 * Should validate.
		 * Stored in the form MM-DD-YYYY
		 */
		void BookData::setDateAdded( std::string date )
		{
			// It was worth the wait.
			// If the string matches this regex expression
			std::regex e ("^(0[1-9]|1[0-2])-([0-3])[\\d]-(19|20)[\\d]{2}$");
			if (std::regex_match(date, e))
			{
				// Copy date to m_dateAdded
				m_dateAdded = date;
			} // end if
			
		} // end function setDateAdded

		/*
		 * This function should accept an int.
		 * This should probably not be a negative number.
		 */
		void BookData::setQuantity( int qty )
		{
			// If qty is not a negative number
			if (qty >= 0)
			{
				// Copy to m_qtyOnHand
				m_qtyOnHand = qty;
			} // end if
			
		} // end function setQuantity

		/*
		 * This function should accept a double.
		 * This should probably not be a negative number.
		 */
		void BookData::setWholesaleCost( double cost )
		{
			// If qty is not a negative number
			if(cost >= 0.0)
			{
				// Copy to m_wholesaleCost
				m_wholesaleCost = cost;
			} // end if
			
		} // end function setWholesaleCost

		/*
		 * This function should accept a double.
		 * This should probably not be a negative number.
		 */
		void BookData::setRetailPrice( double price )
		{
			// If price is not a negative number
			if (price >= 0.0)
			{
				// Copy to m_retailPrice
				m_retailPrice = price;
			} // end if
			
		} // end function setRetailPrice


		// add line break between sets and gets
		/*
		 * This function returns the book title.
		 */
		std::string BookData::getTitle()
		{
			return m_bookTitle;
		} // end function getTitle

		/*
		 * This function returns the ISBN.
		 */
		std::string BookData::getIsbn()
		{
			return m_isbn;
		} // end function getIsbn

		/*
		 * This function returns the author.
		 */
		std::string BookData::getAuthor()
		{
			return m_author;
		} // end function getAuthor

		/*
		 * This function returns the publisher.
		 */
		std::string BookData::getPublisher()
		{
			return m_publisher;
		} // end function getPublisher

		/*
		 * This function returns the date added.
		 */
		std::string BookData::getDateAdded()
		{
			return m_dateAdded;
		} // end function getDateAdded

		/*
		 * This function returns the quantity.
		 */
		int BookData::getQuantity()
		{
			return m_qtyOnHand;
		} // end function getQuantity

		/*
		 * This function returns the whole sale cost.
		 */
		double BookData::getWholesaleCost()
		{
			return m_wholesaleCost;
		} // end function getWholesaleCost

		/*
		 * This function returns the retail price.
		 */
		double BookData::getRetailPrice()
		{
			return m_retailPrice;
		} // end function function getRetailPrice




		/*
		  This function displays information for a BookData object inside
		  the BookCollection array.
		*/
		void BookData::bookInfo()
		{
			std::cout << std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Title:" 
				<< getTitle() << std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Isbn:" << getIsbn() 
				<< std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Author:" 
				<< getAuthor() << std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Publisher:" 
				<< getPublisher() << std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Date Added:" 
				<< getDateAdded() << std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Quantity:" 
				<< getQuantity() << std::endl;
			std::cout << std::fixed << std::showpoint << std::setprecision(2);
			std::cout << std::left << std::setw(WIDTH) << "Wholesale Cost:" 
				<< "$" << getWholesaleCost() << std::endl;
			std::cout << std::left << std::setw(WIDTH) << "Retail Price:" 
				<< "$" << getRetailPrice() << std::endl;
			std::cout << std::endl;

			// Use for not windows
			std::cout << "Press ENTER twice to continue" << std::flush;
			std::cin.get();
			std::cin.clear();
			std::cin.ignore(80, '\n');

			//// use for windows
			//system("PAUSE");

		} // end function bookInfo

// The end is near.
