#ifndef _SYSTEMCONTROL_H_
#define _SYSTEMCONTROL_H_

#include "TQueue.h"

class SystemControl
{
	int FreeProcessors;
	int WorkTime;
	int ObjectiveCompleted;
	int ObjectiveSkipped;
	int AmountOfIdleTacts;
	double AddThreshold;
	int AmountOfObjectives;
	int TimeOfObjectiveWork[64];
	int CurrentTimeOfObjectiveWork[64];
	int ProccessorAmount[64];
	TQueue Queue;

public:

	SystemControl(double addThreshold, int Time)
	{
		FreeProcessors = 64;
		WorkTime = Time;
		ObjectiveCompleted = 0;
		ObjectiveSkipped = 0;
		AmountOfIdleTacts = 0;
		AmountOfObjectives = 0;
		AddThreshold = addThreshold;
	}

	void SystemAddObjective(int ObjTime, int ObjProc);
	void ObjectiveToPerformance();
	void FinishingObjective();
	void ShowResults();
	void ControlSystemSimulation();
};

#endif