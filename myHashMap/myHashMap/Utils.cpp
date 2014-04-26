#include "stdAfx.h"
#include "Utils.h"


const int LOWER_CASE = 1;
const int UPPER_CASE = 2;
const int NOT_ALPHA = 0;

Utils::Utils(void)
{
}

bool Utils::estrcpy(const char* src,char* dst)
{
	const char* mySrc = src;
	char* myDst = dst;

	int i = 0;

	while (mySrc[i] != '\0') 
	{
		myDst[i] = mySrc[i];
		i++;
	}
	return true;
}


/*Utils Utils::operator+(Utils* &input2add)
{
	Utils retU;
	retU.input = strcat(this->input,input2add->input);
	return retU;
}*/

bool Utils::insertionSort(int* input,int inArrayLen)
{
	for (int i=1;i<=inArrayLen-1;i++)
	{
		int k = i;
		while ((k > 0) && (input[k] < input[k-1]))
		{
			swap(input[k],input[k-1]);
			k--;
		}
	}
	return true;
}

bool Utils::selectionSort(int* input,int inArrayLen)
{
	int noOfLoops = 0;
	int endOfLoop = inArrayLen-1;

	while (noOfLoops < inArrayLen)
	{
		int highestIndex = 0;
		for (int i=0;i<=endOfLoop;i++)
		{
			if (input[i] > input[highestIndex])
				highestIndex = i;
		}
		swap(input[highestIndex],input[endOfLoop]);
		endOfLoop--;
		noOfLoops++;
	}
	return true;
}

bool Utils::quickSort(int* input,int inArrayLen)
{
	return (myQSort(input,0,inArrayLen-1));
}

bool Utils::myQSort(int* &input,int start,int end)
{
	bool ret = true;

	if (start >=  end)
		ret = true;
	else
	{
		//choose pivot
		int pivot = getPivot(input,start);
		int rightArrSt = 0;
		bool isRight = true;
		//loop thru input array and partition array - first comes the elements less than pivot and then elements greater than pivot
		ret = partitionArray(input,start,end,input[pivot],rightArrSt,isRight);
		//do myQSort on left pivoted array (less than pivot) and right pivoted array.
		if (isRight)
			ret = myQSort(input,start,rightArrSt-2);
		ret = myQSort(input,rightArrSt,end);
	}
	return ret;
}

void Utils::swap(int &e1,int &e2)
{
	int temp = e1;
	e1 = e2;
	e2 = temp;
}

Utils Utils::operator+(const Utils &other)
{
	Utils retUtil;
	retUtil.a = a + other.a;
	retUtil.b = b + other.b;
	return retUtil;
}

bool Utils::partitionArray(int* in,int start,int end,int myPivot,int &newStart,bool &isRight)
{
	int i = start+1;
	int j = start+1;
	isRight = false;
	
	for (int k=start+1;k<=end;k++)
	{
		if (in[k] > myPivot)
		{
			if (!isRight)
				isRight = true;
			j = k;
		}
		else if (in[k] <= myPivot)
		{
			swap(in[k],in[i]);
			i = i+1;
			j = j+1;
		}
	}

	if (isRight)
		swap(in[start],in[i-1]);
	else
		swap(in[start],in[end]);

	newStart = i;
	//loop thru array from start+1 to end.
	return true; 
}

int Utils::getPivot(int* inArray,int start)
{
	return start;
}

/*int Utils::getPivotElem(int* in)
{
	return (in[getPivot(in),]);
}*/

void Utils::breakArray(int* input,int* &left, int* &right,int leftSize,int rightSize)
{
	int i = 0;
	for (i = 0;i<=(leftSize-1);i++)
		left[i] = input[i];
	int inSize = i;
	int j = 0;

	while (j <= (rightSize-1))
	{
		right[j] = input[inSize];
		j++;
		inSize++;
	}
}

void Utils::breakArrayStr(char* input,char* &left, char* &right,int leftSize,int rightSize)
{
	int i = 0;
	for (i = 0;i<=(leftSize-1);i++)
		left[i] = input[i];
	int inSize = i;
	int j = 0;

	while (j <= (rightSize-1))
	{
		right[j] = input[inSize];
		j++;
		inSize++;
	}
}

void Utils::getLeftRightArraySizes(int inputArrSize,int &leftSize,int &rightSize)
{
	if (inputArrSize % 2 == 0)
		leftSize = rightSize = inputArrSize/2;
	else
	{
		leftSize = (inputArrSize-1)/2;
		rightSize = inputArrSize - leftSize;
	}
}

void Utils::displayOct(int input)
{
	//divide the number by 2^3
	int quotient,reminder;
	int octa = 0;
	int myPow = 0;
//	int octa[2];
	int k = 1;
	
	while (input != 0)
	{
		divideNo(input,3,quotient,reminder);

	//	octa[k] = reminder;
		k--;

		//octa = octa + reminder*(Epow(8,myPow));
		myPow++;
		input = quotient;
	}

}

void Utils::divideNo(int input,int pow,int &quotient,int &reminder)
{
	quotient = input >> pow;
	reminder = input & pow;
}

bool Utils::mergeSort(int* input,int inArrayLen, int* &sortedArray)
{
	int leftArrSize, rightArrSize;
	getLeftRightArraySizes(inArrayLen, leftArrSize,rightArrSize);
	int* left = new int(leftArrSize);
	int* right = new int(rightArrSize);
	breakArray(input, left,right,leftArrSize,rightArrSize);
	int* leftSorted = new int(leftArrSize);
	int* rightSorted = new int(rightArrSize);

	if (leftArrSize > 1)
		mergeSort(left,leftArrSize,leftSorted);
	else
		leftSorted = left;
	if (rightArrSize > 1)
		mergeSort(right,rightArrSize,rightSorted);
	else
		rightSorted = right;

	mergeLeftRightSortedArrs(leftSorted,rightSorted,leftArrSize,rightArrSize,sortedArray);
	return true;
}

bool Utils::mergeSortStr(char* input,int inArrayLen,char* &sortedArray)
{
	int leftArrSize, rightArrSize;
	getLeftRightArraySizes(inArrayLen, leftArrSize,rightArrSize);
	char* left = new char(leftArrSize);
	char* right = new char(rightArrSize);
	breakArrayStr(input, left,right,leftArrSize,rightArrSize);
	char* leftSorted = new char(leftArrSize);
	char* rightSorted = new char(rightArrSize);

	if (leftArrSize > 1)
		mergeSortStr(left,leftArrSize,leftSorted);
	else
		leftSorted = left;
	if (rightArrSize > 1)
		mergeSortStr(right,rightArrSize,rightSorted);
	else
		rightSorted = right;

	mergeLeftRightSortedArrsStr(leftSorted,rightSorted,leftArrSize,rightArrSize,sortedArray);
	return true;
}

void Utils::mergeLeftRightSortedArrs(int* leftSorted, int* rightSorted, int leftSortedSize, int rightSortedSize, int* &mergeSorted)
{
	mergeSorted = new int(leftSortedSize + rightSortedSize);
	int leftCt = 0;
	int rightCt = 0;

	for (int i = 0;i<=(leftSortedSize + rightSortedSize - 1);i++)
	{
		if (leftSorted[leftCt] <= rightSorted[rightCt])
		{
			if (leftCt <= leftSortedSize-1)
			{
				mergeSorted[i] = leftSorted[leftCt];
				leftCt++;
			}
			else
			{
				mergeSorted[i] = rightSorted[rightCt];
				rightCt++;
			}
		}
		else if (leftSorted[leftCt] >= rightSorted[rightCt])
		{
			if (rightCt <= rightSortedSize-1)
			{
				mergeSorted[i] = rightSorted[rightCt];
				rightCt++;
			}
			else
			{
				mergeSorted[i] = leftSorted[leftCt];
				leftCt++;
			}
		}
	}
}

void Utils::mergeLeftRightSortedArrsStr(char* leftSorted, char* rightSorted, int leftSortedSize, int rightSortedSize, char* &mergeSorted)
{
	mergeSorted = new char(leftSortedSize + rightSortedSize);
	int leftCt = 0;
	int rightCt = 0;

	for (int i = 0;i<=(leftSortedSize + rightSortedSize - 1);i++)
	{
		if (leftSorted[leftCt] <= rightSorted[rightCt])
		{
			if (leftCt <= leftSortedSize-1)
			{
				mergeSorted[i] = leftSorted[leftCt];
				leftCt++;
			}
			else
			{
				mergeSorted[i] = rightSorted[rightCt];
				rightCt++;
			}
		}
		else if (leftSorted[leftCt] >= rightSorted[rightCt])
		{
			if (rightCt <= rightSortedSize-1)
			{
				mergeSorted[i] = rightSorted[rightCt];
				rightCt++;
			}
			else
			{
				mergeSorted[i] = leftSorted[leftCt];
				leftCt++;
			}
		}
	}
}


char* Utils::Estrtok(char* input,const char* delimiters,char* &context)
{
	//loop thru input...store each char in a char array output.
	int i = 0;
	char* out = new char;
	bool isDelimFound = false;
	int contextCt = 0;

	if (input == NULL)
		input = context;

	while (input[i] != '\0')
	{
		if (isDelimFound)
		{
			context[contextCt] = input[i];
			contextCt++;
		}
		else
		{
			if (!searchDelimiter4Char(input[i],(char*) delimiters))
				out[i] = input[i];
			else
			{
				out[i] = '\0';
				isDelimFound = true;
			}
		}

		i++;
	}

	if (isDelimFound == false)
		out[i] = '\0';
	else
	{
		context[contextCt] = '\0';
		isDelimFound = false;
		return out;
	}

	return NULL;
	//check if each char is present in delimiters
	//if found return all chars before this...
	//continue to loop thru the input char* and store rest of chars in a diff char array.
}

int Utils::getMidpoint(int left,int right)
{
	 
	
	return (left+right)/2;
}

bool Utils::binSearch(char* sortedArray[],int left,int right,char* key,int &index)
{
	int midpt = 0;
	while (left <= right)
	{
		//get midpoint
		midpt = getMidpoint(left,right);
		//compare key with midpoint
		if (strcmp(key,sortedArray[midpt]) > 0)
		{
			//key > mid-point value.
			//if midpoint value < key: consider input as right side of array and repeat above steps.
			left = midpt+1;
		}
		else if (strcmp(key,sortedArray[midpt]) < 0)
		{
			//key < mid-point value.
			//if midpoint value > key: consider input as left side of array and  repeat above steps.
			
			right = midpt-1;
		}
		else if (strcmp(key,sortedArray[midpt]) == 0)
		{
			//key=mid point value
			//if midpoint value = key: return true and store the index where found.
			index = midpt;
			return true;
		}
	}
	return false;
}

bool Utils::searchDelimiter4Char(char char2search,char* delims)
{
	int i = 0;
	while (delims[i] != '\0')
	{
		if (delims[i] == char2search)
			return true;
		i++;
	}
	return false;
}

int Utils::Eatoi(const char* inStr)
{
	int finalNum = 0;
	int noDigits = 0;
	int i = 0;

	while (inStr[noDigits] != '\0')
	{
		if ((inStr[noDigits] >= '0') && (inStr[noDigits] <= '9'))
		{
			noDigits++;
		}
		else
		{
			break;
		}
	}

	noDigits--;

	while (noDigits >= 0)
	{
		finalNum = finalNum + ((inStr[i]-'0')*(Epow(10,noDigits)));
		i++;
		noDigits--;
	}
	
	return finalNum;
}

int* Utils::findNoMostOccur(int* inputArr)
{
	int* output = new int[4];
	return output;
}

bool Utils::compareChars(char c1,char c2,bool considerCase)
{
	if (c1 == c2)
		return true;
	else if (considerCase)
	{
		if((getCase(c1) != NOT_ALPHA) && (getCase(c2) != NOT_ALPHA))
		{
			if ((((int) c1) - ((int) c2)) == 0x20)
				return true;
			else if ((((int) c2) - ((int) c1)) == 0x20)
				return true;
		}
	}
	return false;
}

char Utils::change2Lower(char cUpper)
{
	if (getCase(cUpper) == UPPER_CASE)
		return (((int) cUpper) + 0x20);
	else
		return cUpper;
}

char Utils::change2Upper(char cLower)
{
	if (getCase(cLower) == LOWER_CASE)
		return (((int) cLower) - 0x20);
	else
		return cLower;
}

int Utils::getCase(char c)
{
	int num = c;
	if ((num >= 0x41) && (num <= 0x5A))
		return UPPER_CASE;
	else if ((num >= 0x61) && (num <= 0x7A))
		return LOWER_CASE;
	else
		return NOT_ALPHA;
}

bool Utils::Estrcmp(const char* s1,const char* s2,bool considerCase)
{
	while ((*s1 != '\0') && (*s2 != '\0'))
	{
		if (!compareChars(*s1,*s2,considerCase))
			return false; 
		s1++;
		s2++;
	}
	return true;
}

int Utils::Epow(int base,int exp)
{
	int lbase;
	int j = 0;
	
	while (j<=exp)
	{
		if (j == 0)
			lbase = 1;
		else
		{
			lbase = base*lbase;
		}

		j++;
	}

	return lbase;
}

bool Utils::getMinDiff(int* arr,int arrSize,minDiff &resultNums)
{
	//sort the array
	if (!quickSort(arr,arrSize))
		return false;

	if (arrSize < 2)
		return false;

	resultNums.min = abs(arr[1] - arr[0]);
	minDiffNums nums;
	nums.n1 = arr[0];
	nums.n2 = arr[1];

	resultNums.allNums.push_back(nums);

	//loop thru array 
	for (int i = 2;i <= (arrSize-1);i++)
	{
		//compare with prev one and see if the diff is less than the smallest diff...if so..this is the new diff
		if (abs(arr[i] - arr[i-1]) == resultNums.min)
		{
			//this diff already is there...so add to the list.
			nums.n1 = arr[i];
			nums.n2 = arr[i-1];
			resultNums.allNums.push_back(nums);
		}
		else if (abs(arr[i] - arr[i-1]) < resultNums.min)
		{
			resultNums.min = abs(arr[i] - arr[i-1]);
			resultNums.allNums.clear();
			nums.n1 = arr[i];
			nums.n2 = arr[i-1];
			resultNums.allNums.push_back(nums);
			
		}
	}
	return true;
}



Utils::~Utils(void)
{
}
