#pragma once
#include "eStack.h"
#include <vector>

using namespace std;

class eTree
{
private:
	typedef struct myLL {
		int key;
		int value;
		myLL* left;
		myLL* right;
	} treeLL;
	myLL* head;
	myLL* curr;
	int mapCt;
	eStack* mySt;
	void addELem(myLL* node,int key2add, int val2add);
	bool delElem(myLL* node,int key2del, int val2del);
	void inTrav(myLL* node);
	void revInTrav(myLL* node);
	void inTravRec(myLL* node);
	void preTrav(myLL* node);
	void traverseAndAdd2Tree(myLL* node2traverse,myLL* dstNode);
public:
	eTree(void);
	void add(int key,int value);
	bool del(int key,int value);
	void inOrder();
	void preOrder();
	void printHi2Low();
	~eTree(void);
};

