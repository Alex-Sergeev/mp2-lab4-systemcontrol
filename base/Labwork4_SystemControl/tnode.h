#ifndef _TNODE_H_
#define _TNODE_H_


class TNode
{
	int ProcessorAmount;
	int Priority;
	TNode *pNext;
public:
	TNode(int var)
	{
		ProcessorAmount=var;
		Priority=0;
		pNext= nullptr;
	}
};

#endif