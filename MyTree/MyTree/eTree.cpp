#include "StdAfx.h"
#include "eTree.h"


eTree::eTree(void)
{
	head = NULL;
	curr = NULL;
	mySt = new eStack();
	mapCt = 0;
}

void eTree::add(int key,int value)
{
	this->addELem(head,key,value);
}

void eTree::inTrav(myLL* node)
{
	if (node->left != NULL)
		inTrav(node->left);
	printf("Key: %d, Value: %d \n",node->key,node->value);
	if (node->right != NULL)
		inTrav(node->right);
}

void eTree::inTravRec(myLL* node)
{
	myLL* curr = node;

	while (curr != NULL)
	{
		char* tmp;
		mySt->push(itoa(curr->key,tmp,10));

		if (curr->left != NULL)
			curr = curr->left;
		else
		{
			printf("%s \n",mySt->pop());
			
			while (curr->right != NULL)
			{
				printf("%s \n",curr->right);
				//mySt->push(itoa(curr->key,tmp,10));
				curr = curr->right;
			}
			
		}
	}
			
}

void eTree::inOrder()
{
	if (head != NULL)
		this->inTrav(head);
}

void eTree::printHi2Low()
{
	if (head != NULL)
		this->revInTrav(head);
}

void eTree::revInTrav(myLL* node)
{
	if (node->right != NULL)
		this->revInTrav(node->right);
	printf("Key: %d , Value: %d \n",node->key,node->value);
	if (node->left != NULL)
		this->revInTrav(node->left);
}

bool eTree::del(int key,int value)
{
	return (this->delElem(head,key,value));
}

bool eTree::delElem(myLL* node,int key2del, int val2del)
{
	bool delRet = true;
	myLL* delNode = new myLL;
	bool delLeft = false;
	bool delRight = false;
	bool delHead = false;
	
	if (node == NULL)
	{
		printf("Null element..key we are searching not found \n");
		return false;
	}
	
	if (node == head)
	{
		if (head->key == key2del)
		{
			delHead = true;
			delNode = head;
			if ((head->left == NULL) && (head->right == NULL))
				delete head;
			else if ((head->left == NULL) && (head->right != NULL))
			{
				head = head->right;
				delete delNode;
			}
			else if ((head->left != NULL) && (head->right == NULL))
			{
				head = head->left;
				delete delNode;
			}
			else
			{
				myLL* rightTree = head->right;
				head = head->left;
				node = head;
				delete delNode;
				this->traverseAndAdd2Tree(rightTree,head);
			}
		}
		else if (key2del < head->key)
			delElem(head->left,key2del,val2del);
		else if (key2del > head->key)
			delElem(head->right,key2del,val2del);
	}
	else if (node->left->key == key2del)
	{
		delNode = node->left;
		delLeft = true;
	}
	else if (node->right->key == key2del)
	{
		delNode = node->right;
		delRight = true;
	}
	else if (key2del < node->left->key)
	{
		delRet = this->delElem(node->left->left,key2del,val2del);
	}
	else if (key2del > node->left->key)
	{
		delRet = this->delElem(node->left->right,key2del,val2del);
	}
	else if (key2del < node->right->key)
		delRet = this->delElem(node->right->left,key2del,val2del);
	else if (key2del > node->right->key)
		delRet = this->delElem(node->right->right,key2del,val2del);
	
	if ((key2del == node->left->key) && (val2del == node->left->value))
	{
		printf("Found the element to delete \n");

		if ((node->left->left == NULL) && (node->left->right == NULL))
		{
			myLL* tmp = node->left;
			node->left = NULL;
			delete tmp;
		}
		else
		{

		}
		return true;
	}
	
	return delRet;
}

void eTree::traverseAndAdd2Tree(myLL* node2traverse,myLL* dstNode)
{
	if (node2traverse != NULL)
		this->addELem(dstNode,node2traverse->key,node2traverse->value);
	
	if (node2traverse->left != NULL)
		this->traverseAndAdd2Tree(node2traverse->left,dstNode);

	if (node2traverse->right != NULL)
		this->traverseAndAdd2Tree(node2traverse->right,dstNode);
}

void eTree::addELem(myLL* node,int key2add, int val2add)
{
	myLL* node2add = new myLL;
	node2add->key = key2add;
	node2add->value = val2add;
	node2add->left = NULL;
	node2add->right = NULL;

	if (node == NULL)
	{
		//empty tree...
		node = node2add;
		curr = head;
		head = node;
	}
	else
	{
		if (node2add->key <= node->key)
		{
			if (node->left == NULL)
				node->left = node2add;
			else
			{
				this->addELem(node->left,node2add->key,node2add->value);
			}
		}
		else 
		{
			if (node->right == NULL)
				node->right = node2add;
			else
			{
				this->addELem(node->right,node2add->key,node2add->value);
			}
		}
	}

	delete node2add;
}

eTree::~eTree(void)
{
}
