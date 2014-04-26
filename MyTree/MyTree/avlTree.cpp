#include "StdAfx.h"
#include "avlTree.h"


avlTree::avlTree(void)
{
	m_head = NULL;
	m_curr = NULL;
	m_leftHt = 0;
	m_rightHt = 0;
}

int avlTree::getHeight(bool leftOrRight)
{
	if (leftOrRight == RIGHT)
		return m_rightHt;
	else
		return m_leftHt;
}

int avlTree::addElement(int value)
{
	return (addElem2AVL(m_head,value,false));
}

int avlTree::addElem2AVL(avlStruct* node,int data2add,bool isleftOfHead)
{
	avlStruct* node2add = new avlStruct;
	node2add->data = data2add;
	node2add->left = NULL;
	node2add->right = NULL;
	node2add->parent = NULL;

	if (node == NULL)
	{
		//empty tree...
		node = node2add;
		m_head = node;
	}
	else
	{
		if (node2add->data <= node->data)
		{
			if (node == m_head)
				isleftOfHead = true;

			if (node->left == NULL)
			{//this is where to add the node.
				node2add->parent = node;
				node->left = node2add;
				if (isleftOfHead)
					m_leftHt++;
				else
					m_rightHt++;
				if (balanceTree(m_head))
				{
					if (isleftOfHead)
						m_leftHt--;
					else
						m_rightHt--;
				}
			}
			else
			{
				this->addElem2AVL(node->left,node2add->data,isleftOfHead);
			}
		}
		else 
		{
			if (node == m_head)
				isleftOfHead = false;

			if (node->right == NULL)
			{
				//add somewhere in right subtree.
				node2add->parent = node;
				node->right = node2add;
				if (isleftOfHead)
					m_leftHt++;
				else
					m_rightHt++;
				if (balanceTree(m_head))
				{
					if (isleftOfHead)
						m_leftHt--;
					else
						m_rightHt--;
				}

			}
			else
			{
				this->addElem2AVL(node->right,node2add->data,isleftOfHead);
			}
		}
	}

	delete node2add;
	return 1;
}

bool avlTree::balanceTree(avlStruct* &node)
{
	_int8 balanceState = isBalanced();
	if (balanceState == BALANCED)
		return false;
	else
	{
		//not balanced..so need to balance.
		if (balanceState == RIGHT_UNBALANCED)
			rotateLeft(node);
		else
			rotateRight(node);
		return true;
	}
}

_int8 avlTree::isBalanced()
{
	if ((m_rightHt - m_leftHt) > 1)
		return RIGHT_UNBALANCED;
	else if ((m_leftHt - m_rightHt) > 1)
		return LEFT_UNBALANCED;
	else
		return BALANCED;
}

bool avlTree::rotateLeft(avlStruct* &node)
{
	avlStruct* node2swap = node->right;
	node->right = node2swap->left;
	node2swap->left = node;
	node = node2swap;
	return true;
}

bool avlTree::rotateRight(avlStruct* &node)
{
	avlStruct* node2swap = node->left;
	node->left = node2swap->right;
	node2swap->right = node;
	node = node2swap;
	return true;
}

avlTree::~avlTree(void)
{
}
