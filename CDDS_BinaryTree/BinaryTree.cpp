#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int value)
{
	//If the tree is empty, set the root to be a new node with the given value.
	if (isEmpty()) 
	{
		m_root = new TreeNode(value);
	}

	//Create a TreeNode pointer that will act as an iterator pointing to the current node and set it to the root.
	TreeNode* currentNode = m_root;
	//Create a TreeNode pointer that will act as an iterator pointing to the parent 
	//of the current node and set it to the root.
	TreeNode* parentNode = m_root;

	//Loop until the the current node iterator reaches a nullptr.
	while (currentNode != nullptr) 
	{
		//Check if the value we want to add to the tree is less than the value at the current node.
		if (value < currentNode->getData()) 
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentNode = currentNode;
			//Change the current node to be the child to its left and continue.
			currentNode = currentNode->getLeft();
		}
		//Check if the value we want to add to the tree is greater than the value at the current node.
		else if (value > currentNode->getData()) 
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentNode = currentNode;
			//Change the current node to be the child to its right and continue.
			currentNode = currentNode->getRight();
		}
		//If the value is the same as a value already in the list return
		else 
		{
			return;
		}
	}
	//end loop

	//If the value we want to add is less than the value of the parent node, insert the value to the left.

	//Otherwise, insert the value to the right.

}

void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove
	//and another to hold a reference to its parent.
	TreeNode* toBeRemoved = new TreeNode(value);
	TreeNode* parentOfRemoved;

	//Try to find the node that matches the value given and its parent in the tree.
	//If the node cannot be found return.
	if (!find(value)) 
	{
		return;
	}


	//Check to see if the node has a right
	if (toBeRemoved->getRight() != nullptr) 
	{
		//Initialize two iterators to find the node whose data will be copied and its parent.
		TreeNode* toBeCopied;
		TreeNode* parentOfCopied;

		//Set the first iterator to point to the right child of the node we want to remove.
		toBeCopied = toBeRemoved->getRight();

		//Loop while the first iterator has a value to its left
		while (toBeCopied->getLeft() != nullptr) 
		{
			//Set the second iterator to be the value of the first iterator.
			parentOfCopied = toBeCopied;
			//Set the first iterator to be the value to the left of it
			toBeCopied = toBeCopied->getLeft();
		}
		//end loop

		//Once the smallest value has been found, copy the data in first iterator to the node we want to remove.


		//Check if the second iterator has a left child.
			//Check if the left child stores the same data as the node we wanted to remove.
				//Set the second iterators left child to be the first iterators right child.

		//Check if the second iterator has a right child.
			//Check if the right child contains the same data as the node we want to remove.
				//Set the right child of the second iterator to be the right child of the first iterator.

		//Delete the first iterator
	}
	//Otherwise, if the node doesn't have a right child
	else 
	{
		//check if the parent of the node to remove has a left child.
			//Check if the data that the left child holds is the same as the data the node to remove holds.
				//Set the left child of the parent node to be the left child of the node to remove.

		//Check if the parent of the node to remove has a right child.
			//Check if the data the right child holds is the same as the data the node to remove holds.
				//Set the right child of the parent node to be the left child of the node to remove.

		//Check if the node we want to remove is the root.
			//Set the root to be its left child.

		//Delete the pointer that points to the node to remove.
	}
}

TreeNode* BinaryTree::find(int value)
{
	//Initialize an iterator starting at the root.
	TreeNode* iterator = m_root;

	//Loop through the tree while the iterator isn't nullptr.
	while (iterator != nullptr) 
	{
		//Check if the node has the data we want
		if (iterator->getData() == value) 
		{
			//Return the iterator
			return iterator;
		}
		//If the node doesn't have the data we want, check to see if it's higher in value.
		else if (iterator->getData() > value) 
		{
			//Set the iterator to be its current right child.
			iterator = iterator->getRight();
		}
		//If the node doesn't have the data we want, check to see if it's lower in value.
		else if (iterator->getData() < value) 
		{
			//Set the iterator to be its current left child.
			iterator = iterator->getLeft();
		}
	}
	//end loop

	//Return nullptr
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	//and the other to hold a reference to the parent.
	TreeNode* currentNode = m_root;
	TreeNode* parentNode = nodeParent;

	//Loop while the current node iterator isn't nullptr/
	while (currentNode != nullptr) 
	{
		//Check if the search value is the same as the current nodes data.
		if (currentNode->getData() == searchValue) 
		{
			//Set the node found argument to be the current node and the parent node to be the parent node iterator.
			nodeFound = currentNode;
			nodeParent = parentNode;
			//Return true.
			return true;
		}
		//Check if the search value is greater than the value at the current node.
		else if (currentNode->getData() > searchValue) 
		{
			//Set the parent node to be the current node.
			parentNode = currentNode;
			//Set the current node to be the child to the right of the current node.
			currentNode = currentNode->getRight();
		}
		//Check if the search value is less than the value at the current node.
		else if (currentNode->getData() < searchValue) 
		{
			//Set the parent node to be the current node.
			parentNode = currentNode;
			//Set the current node to be its left child.
			currentNode = currentNode->getLeft();
		}
	}
	//end loop

	//Return false.
	return false;
}

void BinaryTree::draw(TreeNode* currentNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
}
