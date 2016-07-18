#pragma once
#include <stdlib.h>
template<class TYPE>
struct NODE
{
	TYPE  data;
};

template<class TYPE>
class Lane
{
private:

	NODE<TYPE>  *stackAry;
	int	         count;
	int          stackMax;
	int          top;

public:
	Lane(int size = 100);
	~Lane(void);
	bool  pushStack(TYPE  dataIn);
	bool  popStack(TYPE& dataOut);
	bool  stackTop(TYPE& dataOut);
	bool  emptyStack(void);
	bool  fullStack(void);
	int   stackCount(void);
	bool  laneSearch(TYPE dataIn);
};
template<class TYPE>
Lane<TYPE> ::Lane(int size)
{
	stackMax = size;
	stackAry = new NODE<TYPE>[stackMax];
	if (!stackAry)
	{
		cout << "\a\aMemory Overflow in Create Stack\n";
		return;
	}
	count = 0;
	top = -1;
}
template<class TYPE>
bool Lane<TYPE> ::pushStack(TYPE dataIn)
{
	if (count >= stackMax)
		return false;

	count++;
	top++;
	stackAry[top].data = dataIn;
	stackAry[top].data.moves++;
	return true;
}
template<class TYPE>
bool Lane<TYPE> ::popStack(TYPE& dataOut)
{

	bool success;

	if (count == 0)
		success = false;
	else
	{
		stackAry[top].data.moves++;
		dataOut = stackAry[top].data;
		top--;
		count--;
		success = true;
	}

	return success;
}
template<class TYPE>
bool Lane<TYPE> ::stackTop(TYPE& dataOut)

{
	bool success;

	if (count == 0)
		success = false;
	else
	{
		dataOut = stackAry[top].data;
		success = true;
	}
	return success;
}
template<class TYPE>
bool Lane<TYPE> ::emptyStack(void)
{
	return (count == 0);
}

template<class TYPE>
bool Lane <TYPE> ::fullStack(void)
{
	return (count == stackMax);
}

template<class TYPE>
int Lane <TYPE> ::stackCount(void)
{
	return count;
}

template<class TYPE>
bool Lane<TYPE> ::laneSearch(TYPE dataIn)
{
	bool success;
	if (count == 0)
		success = false;
	else
	{
		for (int i = 0; i<stackMax; i++)
		{
			if (dataIn.licensePlate == stackAry[i].data.licensePlate)
			{
				success = true;
				break;
			}
			else
			{
				success = false;
			}
		}
	}
	return success;

}

template<class TYPE>
Lane<TYPE> :: ~Lane(void)
{
	delete[] stackAry;
	stackAry = NULL;
	count = 0;
	stackMax = 0;
	top = -1;
}