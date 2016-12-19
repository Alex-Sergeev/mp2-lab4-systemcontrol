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

	bool operator==(const TNode &tmp) const
	{
		if ((TactTime == tmp.TactTime)&&(Priority==tmp.Priority)&&(ProcessorAmount==tmp.ProcessorAmount))
			return 1;
		return 0;
	}

	bool operator!=(const TNode &tmp) const
	{
		return !(*this == tmp);
	}
};

#endif