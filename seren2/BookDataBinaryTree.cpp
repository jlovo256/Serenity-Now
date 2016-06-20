/*
@file BookDataBinaryTree.cpp
@class BTREE
@class BNODE

@brief  Makes functions for BTREE

@author Jamie Tudor
*/

#include "BookDataBinaryTree.h"
#include "BookData.h"
#include <iostream>
#include <regex>
#include <iomanip>
#include <list>
#include <string>

/*
	This function will display the bookdata objects in order
*/
void BTREE::inorder(BNODE *tree)
{

	if (tree)
	{
		inorder(tree->left);

		// Make a lovely report
		std::cout << "Title: " << tree->iter->getTitle() << std::endl;
		std::cout << "Isbn: " << tree->iter->getIsbn() << std::endl;
		std::cout << "Quantity: " << tree->iter->getQuantity() << std::endl;
		std::cout << "Wholesale Cost: " << "$"<< tree->iter->getWholesaleCost() 
			<< std::endl;
		std::cout << std::endl;

		// move to the right
		inorder(tree->right);

	} // end if

		// pause

		// Use for not windows
		//std::cout << "Press ENTER twice to continue";
		//std::cout << std::flush;
		//std::cin.get();
		//std::cin.clear();
		//std::cin.ignore(80, '\n');

} // end function inorder

/*
	Recursive
	This function will insert a BookData object into the tree after finding the
	proper place for it.
*/
BNODE *BTREE::insert(BNODE *tree, std::list<BookData>::iterator iter)
{
	// if the tree is empty
	if (!tree)
	{
		BNODE *tree = new BNODE(iter);
		return tree;
	} // end if
	// don't add a duplicate book
	//else if (tree->iter->getIsbn() == iter->getIsbn())
	//{
	//	return tree;
	//} // end else if
	// if the new book's wholesale is less than
	else if (iter->getWholesaleCost() > tree->iter->getWholesaleCost())
	{
		// insert it on the left
		tree->left = insert(tree->left, iter);
	} // else
	else
	{
		// otherwise insert it on the right
		tree->right = insert(tree->right, iter);
	} // end else

	return tree;
} // end function insert

// the end is near
