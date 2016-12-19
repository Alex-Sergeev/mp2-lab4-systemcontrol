#ifndef _TNODE_H_
#define _TNODE_H_


struct TNode
{
	int ProcessorAmount;
	int TactTime;
	TNode *pNext;
	int Priority;

	TNode(int ProcAmount,int Time)
	{
		ProcessorAmount=ProcAmount;
		TactTime = Time;
		Priority=0;
		pNext= nullptr;
	}
};

#endif