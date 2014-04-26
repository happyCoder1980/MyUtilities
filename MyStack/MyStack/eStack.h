#pragma once
#include <string>

using namespace std;

class eStack
{
private:
	typedef struct myLL {
		string data;
		myLL* next;
	} stackLL;
	myLL* head;
	myLL* curr;
	int stackCt;
	static eStack* localSt;
	bool myKeepAndDelete(myLL* head,int nodes2keep,int nodes2del);

public:
	eStack(void);
	static eStack* initStack();
	void push(string data2push);//use this to add to stack.
	string pop();//use this to remove top element from stack.
	void reverseStack();
	string getTopElem();
	int getStackCt();
	void cleanUpStack();
	bool findElem(const string &elem2find);
	bool deleteElem(const string &elem2del);
	bool sortStack();
	myLL* getLowest(myLL* start);
	void swapNodes(myLL* &node1,myLL* &node2);
	bool keepAndDeleteNodes(int numNodes2keep,int numNodes2del);
	bool deleteNodes(int delStart,int delEnd);
	void removeDups();
	~eStack(void);
};

