#include "StdAfx.h"
#include "eStack.h"

eStack* eStack::localSt = NULL;

eStack::eStack(void)
{
	head = NULL;
	curr = NULL;
	stackCt = 0;
}

eStack* eStack::initStack()
{
	eStack::localSt = new eStack();
	return localSt;
}

void eStack::push(string data2push)
{
	myLL* node2Add = new myLL;
	node2Add->data = data2push;
	node2Add->next = head;

	head = node2Add;
	stackCt++;
}

string eStack::pop()
{
	string data2pop;
	myLL* temp;

	//get the top element of the list...
	data2pop = head->data;
	
	//now remove the head and have the next in line as head.
	temp = head;
	head = head->next;

	delete temp;
	stackCt--;

	return data2pop;
}

void eStack::reverseStack()
{
	myLL* curr1 = head;
	myLL* newNext = NULL;
	myLL* prev = NULL;
	
	while (curr1 != NULL)
	{
		newNext = curr1->next;
		curr1->next = prev;
		prev = curr1;
		curr1 = newNext;
	}

	head = prev;
}

int eStack::getStackCt()
{
	return stackCt;
}

string eStack::getTopElem()
{
	return (head->data);
}

void eStack::removeDups()
{

}

bool eStack::sortStack()
{
	myLL* curr = head;
	int currLoc = 0;

	while (curr != NULL)
	{
		//for node at currLoc, find lowest elem for all elements from currLoc to end.
		//swap currLoc element with the lowest element.
		//curr = curr->next
		//currLoc++
	}

	return true;
}

eStack::myLL* eStack::getLowest(myLL* start)
{
	myLL* lowestNode = start;

	while (start != NULL)
	{
		if (start->data < lowestNode->data)
			lowestNode = start;
		start = start->next;
	}

	return lowestNode;
}

void eStack::swapNodes(myLL* &node1,myLL* &node2)
{
	myLL* tempNode = node1;
	node1 = node2;
	node2 = tempNode;
}

void eStack::cleanUpStack()
{
	myLL* temp = head;

	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		delete temp;
	}

	printf("Done cleaning up stack");
}

bool eStack::findElem(const string &elem2find)
{
	myLL* curr = head;

	while (curr != NULL)
	{
		if (curr->data == elem2find)
			return true;
		else
			curr = curr->next;
	}

	return false;
}

bool eStack::keepAndDeleteNodes(int numNodes2keep,int numNodes2del)
{
	bool ret = false;
	static myLL* curr1 = head;
	myLL* prev = new myLL;
	static int ct = 0;
	static bool keepNodes = true;

	while (curr1 != NULL)
	{
		if (keepNodes)
		{
			if (ct < numNodes2keep)
				ct++;
			else if (ct == numNodes2keep)
			{
				ct = 0;
				keepNodes = false;
				prev = curr1;
			}
			curr1 = curr1->next;
		}
		else
		{
			if (ct < numNodes2del)
			{
				myLL* temp = curr1;
				ct++;
				
				if (ct == numNodes2del)
				{
					prev->next = curr1->next;
					ct = 0;
					keepNodes = true;
				}
				
				if (curr1->next != NULL)
				{
					curr1 = curr1->next;
					if (!keepNodes)
						this->keepAndDeleteNodes(numNodes2keep,numNodes2del);
				}
				delete temp;
				
			}
		}

		
	}
	
	return ret;
}

bool eStack::deleteNodes(int delStart,int delEnd)
{
	myLL* curr1 = head;
	int ct = 0;
	myLL* prev = NULL;
	myLL* temp = NULL;

	if (ct == delStart-1)
			prev = curr1;

	while (curr1 != NULL)
	{
		ct++;
		if (ct == delStart-1)
			prev = curr1;

		if ((delStart <= ct) && (ct <= delEnd))
		{
			temp = curr1;
			curr1 = curr1->next;
			delete temp;

			if (ct == delEnd)
				prev->next = curr1;
		}
		else
			curr1 = curr1->next;
	}

	return true;

}

bool eStack::deleteElem(const string &elem2del)
{
	myLL* curr = head;
	myLL* temp = head;

	while (curr != NULL)
	{
		if (curr->next != NULL)
		{
			if (curr->next->data == elem2del)
			{
				temp = curr->next;
				curr->next = curr->next->next;
				delete temp;
				return true;
			}
			else
				curr = curr->next;
		}
	}
	return false;
}

eStack::~eStack(void)
{
	cleanUpStack();
}
