/*
@file mainmenu.h
@class Menu

@brief  This class enables the program to reference a static instance of
	the BookCollection class

@author Jamie Tudor

*/
#ifndef MAINMENU_H
#define MAINMENU_H

#include "BookCollection.h"

/*
	The class main.  Contains the functions cashier, invMenu, and reports.
*/
class Menu
{
	public:
		// static functions
		static void cashier();
		static void invMenu();
		static void reports();

		// This function will be called to initialize the Menu after the book
		// collection object has been created.
		static void initialize(BookCollection *b) {books = b; };

	private:
		// static member
		static BookCollection *books;


}; // end Menu class




#endif //endif MENU_H

// end is near
