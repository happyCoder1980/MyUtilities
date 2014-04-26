#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

typedef struct myInt{
  int num;
  bool isVisited;
  myInt()
    {
    isVisited = false;
  }
} m_myInt;

using namespace std;

typedef struct minDiffNums {
	int n1;
	int n2;
} myNums;

typedef struct minDiff {
	int min;
	vector <minDiffNums> allNums;
} myMinDiff;

class Utils
{
private:
	
	bool searchDelimiter4Char(char char2search,char* delims);
	bool compareChars(char c1,char c2,bool considerCase);
	int getCase(char c);
	void breakArray(int* input,int*&left, int* &right,int leftSize,int rightSize);
	void breakArrayStr(char* input,char* &left, char* &right,int leftSize,int rightSize);
	void getLeftRightArraySizes(int inputArrSize,int &leftSize,int &rightSize);
	void mergeLeftRightSortedArrs(int* leftSorted, int* rightSorted, int leftSortedSize, int rightSortedSize, int* &mergeSorted);
	void mergeLeftRightSortedArrsStr(char* leftSorted, char* rightSorted, int leftSortedSize, int rightSortedSize, char* &mergeSorted);
	bool myQSort(int* &input,int start,int end);
	int getPivot(int* inArray,int start);
	int getPivotElem(int* in);
	bool partitionArray(int* in,int start,int end,int myPivot,int &newStart,bool &isRight);
	void swap(int &e1,int &e2);
	int getMidpoint(int left,int right);
	
public:
	int a,b;
	char* input;
	Utils(void);
	bool binSort(int* sortedArr,int input,int arrLen);
	bool mergeSort(int* input,int inArrayLen, int* &sortedArray);
	bool mergeSortStr(char* input,int inArrayLen,char* &sortedArray);
	bool quickSort(int* input,int inArrayLen);
	bool insertionSort(int* input,int inArrayLen);
	bool selectionSort(int* input,int inArrayLen);
	bool heapSort(int* input,int inArrayLen);
	bool estrcpy(const char* src,char* dst);
	int Eatoi(const char* inStr);
	int Epow(int base,int exp);
	char* Estrtok(char* input,const char* delimiters,char* &context);
	bool Estrcmp(const char* s1,const char* s2,bool considerCase = false);
	char change2Lower(char cUpper);
	char change2Upper(char cLower);
	int* findNoMostOccur(int* inputArr);
	void displayOct(int input);
	void divideNo(int input,int pow,int &quotient,int &reminder);
	bool binSearch(char* sortedArray[],int left,int right,char* key,int &index);
	bool getMinDiff(int* arr,int arrSize,minDiff &resultNums);
	Utils operator+(const Utils &other);
	//void operator new(const Utils &other);
	~Utils(void);
};

