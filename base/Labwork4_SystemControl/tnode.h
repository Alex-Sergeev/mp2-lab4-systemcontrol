#ifndef _TNODE_H_
#define _TNODE_H_


class TNode
{
	int ProcessorAmount;
	int TactTime;
	TNode *pNext;
public:
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