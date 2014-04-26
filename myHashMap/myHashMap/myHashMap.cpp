// myHashMap.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Utils.h"
#include "eHash.h"
#include <string>

using namespace std;

void getCombosForNum(int num,eHash &myHMap,int &totalValidCombos)
{
	int rem = 0;
	int quo = 0;
	int div = 10;

	//int powOfTen = 1;
	while (rem != num)
	{
		rem = num % div;

		if (rem == 0)
			return;
		quo = num / div;

		string remStr,quoStr;
		itoa(rem,(char*) remStr.c_str(),10);
		itoa(quo,(char*) quoStr.c_str(),10);

		string recStr;
		strcat((char*) recStr.c_str(),remStr.c_str());
		strcat((char*) recStr.c_str(),quoStr.c_str());
		
		//recStr = remStr + quoStr;
		//this is the recycled version of the number using the above reminder and quotient
		int recNum = atoi(recStr.c_str());

		//see if this recycled num is present in the hash table.
		int numKey;
	
		if (myHMap.lookupNum(recNum,numKey))
		{
			if (!myHMap.getVisitedFlag(numKey))
				myHMap.updateNum(recNum,true);
			totalValidCombos++;
		}

		div = div*10;
		//powOfTen++;
		
	}
}

int getRecycledPairs(int myStart,int myEnd)
{
	eHash gcjMap(myStart,myEnd);

	for (int i=myStart;i<=myEnd;i++)
		gcjMap.addElem(i);
	
	//get combos for each number.
	int totalCombos = 0;

	for (int j=myStart;j<=myEnd;j++)
	{
		getCombosForNum(j,gcjMap,totalCombos);
	}
	return totalCombos;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char* myStr = new char[5];
	char* context1 = new char;
	Utils* ut = new Utils();

	
	char* sorted = new char(5);
	ut->mergeSortStr("anand",5,sorted);
	
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	int totalPairs = getRecycledPairs(100,500);

//	int octa = ut->displayOct(26);

	istream* inStr;
	inStr = &cin;
	//char line[256];
	string line;
	int arrSize;
	int* inArr;
	bool isLineGood = true;
	while (std::cin.good())
	{
		while (isLineGood)
		{
			if (getline(cin,line))
			{
				if (line.size() == 0)
					isLineGood = false;
				char* lineStr = strtok((char*) line.c_str()," ");
				arrSize = atoi((const char*) lineStr);
				inArr = new int[arrSize];
				int i = 0;

				while (lineStr != NULL)
				{
					lineStr = strtok(NULL," ");
					if (lineStr != NULL)
					{
						inArr[i] = atoi((const char*) lineStr);
						i++;
					}
				}
			}
		}
	}
	

	int in[11];
	
	in[0] = 1;
	in[1] = 5;
	in[2] = 2;
	in[3] = 23;
	in[4] = 7;
	in[5] = 122;
	in[6] = 0;
	in[7] = 18;
	in[8] = 6;
	in[9] = 12;
	in[10] = 7;

	minDiff res;

	ut->getMinDiff(inArr,arrSize,res);

	char* names[13];

	names[0] = "anand";
	names[1] = "ananya";
	names[2] = "anuya";
	names[3] = "apar";
	names[4] = "archana";
	names[5] = "arun";
	names[6] = "besharam";
	names[7] = "bharat";
	names[8] = "bharti";
	names[9] = "bhasker";
	names[10] = "bindu";
	names[11] = "george";
	names[12] = "prashanth";
	
	

	int ind = -1;
	if (ut->binSearch(names,0,12,"Anand",ind))
		printf("Element found: index no: %d ",ind);

	int* sortedIn = new int(11);

	//ut->insertionSort(in,11);
	ut->selectionSort(in,11);
	ut->quickSort(in,11);


	ut->mergeSort(in,11,sortedIn);
	
	char* lim = ut->Estrtok("this,test;test1",",",context1);
	char* lim1 = ut->Estrtok(NULL,",",context1);

	char c2 = ut->change2Lower('a');

	if (ut->Estrcmp("thi@s is a test string for this program assignment","Thi@s is a test string for this progrAm assignment"))
		printf("Strings are equal \n");

	//u = ut + *u1;

	int num = ut->Eatoi("123a12");

	ut->estrcpy("test message",myStr);
	
	return 0;
}

