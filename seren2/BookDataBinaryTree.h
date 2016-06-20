/*
@file BookDataBinaryTree.h
@class BTREE
@class BNODE

@brief This is a binary search tree for BookData objects stored in a linked
list.  It will store pointers to the objects.

@note The idea is to sort the list.

@author Jamie Tudor
*/
#ifndef BOOKDATABINARYTREE_H
#define BOOKDATABINARYTREE_H

#include "BookData.h"
#include <list>

/*
	class BNODE  The node of the binary tree
*/
class BNODE
{
	friend class BTREE;

	private:
		std::list<BookData>::iterator iter;
		BNODE *left;
		BNODE *right;
	public:
		BNODE(std::list<BookData>::iterator iter, BNODE *left = NULL,
			BNODE *right = NULL)
		{
			this->iter = iter;
			this->left = left;
			this->right = right;
		}
}; // end class BNODE

/*
	class BTREE The binary tree
*/
class BTREE
{
	// for display
	static const int WIDTH = 16;

	BNODE *root;

	public:
		BTREE( ) { root = NULL; }
		void inorder( ) {inorder(root);}
		void insert(std::list<BookData>::iterator iter)
			{ root = insert(root, iter);}

	private:
		void inorder(BNODE *tree);
		BNODE *insert(BNODE *tree, std::list<BookData>::iterator iter);

}; // end class BTREE

#endif // endif BOOKDATABINARYTREE_H

// the end is near
