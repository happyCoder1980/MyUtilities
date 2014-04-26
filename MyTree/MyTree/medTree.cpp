#include "StdAfx.h"
#include "medTree.h"


medTree::medTree(void)
{
	m_currMedian = NULL;
	m_leftCt = 0;
	m_rightCt = 0;
	m_leftOfHead = false;
	head = NULL;
	curr = NULL;
}

bool medTree::updateCurrMedian()
{
	int diff = 0;
	_int8 balState = getBalancedState(diff);
	if (balState == BALANCED)
	{
		printf("ALready balanced..no need to update \n");
		return false;
	}
	else if (balState == RIGHT_UNBALANCED)
	{
		//advance currMedian by 
	}
}

int medTree::getCurrMedian()
{
	if ((m_leftCt + m_rightCt) % 2 == 0) // total no of elements is odd here...so return head value.
		return (head->value);
	else if (m_rightCt > m_leftCt) //more on the right
		return ((head->value + head->right->value)/2);
	else //more on left
		return ((head->value + head->left->value)/2);
}

_int8 medTree::getBalancedState(int &htDiff)
{
	if ((m_rightCt - m_leftCt) > 1)
	{
		htDiff = m_rightCt - m_leftCt;
		return RIGHT_UNBALANCED;
	}
	else if ((m_leftCt - m_rightCt) > 1)
	{
		htDiff = m_leftCt - m_rightCt;
		return LEFT_UNBALANCED;
	}
	else
		return BALANCED;
}

bool medTree::rotateLeft(myLL* &node)
{
	myLL* node2swap = node->right;
	node->right = node2swap->left;
	node2swap->left = node;
	node = node2swap;
	return true;
}

bool medTree::rotateRight(myLL* &node)
{
	myLL* node2swap = node->left;
	node->left = node2swap->right;
	node2swap->right = node;
	node = node2swap;
	return true;
}

bool medTree::balanceTree(myLL* &node)
{
	int diff;
	_int8 balanceState = getBalancedState(diff);
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

bool medTree::find(int num)
{
	return (lookupElem(head,num));
}

bool medTree::lookupElem(myLL* node,int data2find)
{
	if (node == NULL)
		return false;
	else if (node->value == data2find)
		return true;
	else if (node->value > data2find)
		return (lookupElem(node->left,data2find)); //num to search is less than root..so check left sub-tree.
	else if (node->value < data2find)
		return (lookupElem(node->right,data2find));//num to search is more than root..so check right sub tree.
}

bool medTree::deleteElem(int num)
{
	return (deleteElement(head,num));
}

bool medTree::deleteElement(myLL* node,int num2del)
{
	if (node == NULL)
	{
		printf("Element not found \n");
		return false;
	}
	else if (node->value == num2del)
	{
		printf("Node with num 2 be deleted found \n");
		deleteNode(node);
		return true;
	}
	else if (node->value > num2del)
		return (deleteElement(node->left,num2del)); //num to search is less than root..so check left sub-tree.
	else if (node->value < num2del)
		return (deleteElement(node->right,num2del));//num to search is more than root..so check right sub tree.
}

bool medTree::deleteNode(myLL* &node2del)
{
	return true;
}

void medTree::addElem(int num2add)
{
	bool leftOfHd = false;
	
	if (head == NULL)
	{
		head = new myLL;
		head->value = num2add;
		head->left = NULL;
		head->right = NULL;
		head->parent = NULL;
	}
	else
		addElement(head,num2add,leftOfHd);
}

void medTree::addElement(myLL* &node,int num,bool &leftOfHead)
{
	myLL* node2add = new myLL;
	node2add->value = num;
	node2add->left = NULL;
	node2add->right = NULL;
	node2add->parent = NULL;
	
	if (node != NULL) 
	{
		if (node2add->value <= node->value)
		{
			if (node == head)
				leftOfHead = true;

			if (node->left == NULL)
			{
				node2add->parent = node;
				node->left = new myLL;
				node->left->value = num;
				node->left->left = NULL;
				node->left->parent = node;
				node->left->right = NULL;

				if (leftOfHead)
					m_leftCt++;
				else
					m_rightCt++;

				if (balanceTree(head))
				{
					if (leftOfHead)
					{
						m_rightCt++;
						m_leftCt--;
					}
					else
					{
						m_leftCt++;
						m_rightCt--;
					}
				}
			}
			else
			{
				addElement(node->left,node2add->value,leftOfHead);
			}
		}
		else 
		{
			if (node == head)
				leftOfHead = false;

			if (node->right == NULL)
			{
				node2add->parent = node;
				node->right = new myLL;
				node->right->value = num;
				node->right->left = NULL;
				node->right->parent = node;
				node->right->right = NULL;

				if (leftOfHead)
					m_leftCt++;
				else
					m_rightCt++;

				if (balanceTree(head))
				{
					if (leftOfHead)
					{
						m_rightCt++;
						m_leftCt--;
					}
					else
					{
						m_leftCt++;
						m_rightCt--;
					}
				}
			}
			else
			{
				addElement(node->right,node2add->value,leftOfHead);
			}
		}
	}

	delete node2add;
}


medTree::~medTree(void)
{
}
