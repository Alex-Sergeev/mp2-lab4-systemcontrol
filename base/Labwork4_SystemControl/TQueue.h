#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include "TNode.h"

const int Max_Size = 20;

class TQueue
{
	int CurrentSize;
	TNode* pFirst;

public:

	TQueue()
	{
		pFirst = nullptr;
		CurrentSize = 0;
	}

	int getCurrentSize()
	{
		return CurrentSize;
	}

	void AddObjective(int ProcAmount, int Time)
	{
		TNode* tmp;
		tmp = new TNode(ProcAmount, Time);
		if (CurrentSize == 0)
		{
			pFirst = tmp;
			CurrentSize++;
			return;
		}
		if (CurrentSize == Max_Size)
			throw "Queue is Full";
		TNode *tmpSearch = pFirst;
		for (int i = 0; i < CurrentSize - 1; i++)
			tmpSearch = tmpSearch->pNext;
		tmpSearch->pNext = tmp;
		CurrentSize++;
	}

	TNode GetObjective(int Position)
	{
		TNode* tmp =pFirst;
		for (int i = 0; i < Position; i++)
			tmp = tmp->pNext;
		TNode tmp2( tmp->ProcessorAmount,tmp->TactTime);
		tmp2.Priority = tmp->Priority;
		return tmp2;
	}

	void IncreasePriority()
	{
		TNode *tmp = pFirst;
		for (int i = 0; i < CurrentSize; i++)
		{
			tmp->Priority++;
			tmp = tmp->pNext;
		}
	}

	void DeleteObjective(int Position)
	{	
		TNode *tmp = pFirst;
		int i;
			if (Position == 0)
		{
			if (CurrentSize == 1)
			{
				delete tmp;
				pFirst = nullptr;
				CurrentSize--;
				return;
			}
			pFirst = pFirst->pNext;
			delete tmp;
			CurrentSize--;
			return;
		}
		if (Position == CurrentSize-1)
		{
			for (i = 0; i < CurrentSize - 1; i++)
				tmp = tmp->pNext;
			TNode *tmp2 = tmp->pNext;
			delete tmp2;
			tmp->pNext = nullptr;
			CurrentSize--;
			return;
		}
		for (i = 0; i < Position - 1; i++)
			tmp = tmp->pNext;
		TNode *tmp2 = tmp->pNext;
		tmp->pNext = tmp2->pNext;
		delete tmp2;
		CurrentSize--;
		return;
	}

	~TQueue()
	{
		TNode *tmp = pFirst;
		TNode *tmp2;
		for (int i = 0; i < CurrentSize; i++)
		{
			tmp2 = tmp;
			tmp = tmp->pNext;
			delete tmp2;
		}
		delete tmp;
	}
};

#endif