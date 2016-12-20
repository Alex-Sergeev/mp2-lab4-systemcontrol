#include "TQueue.h"
#include "SystemControl.h"
#include "TNode.h"
#include <iostream>

using namespace std;

void SystemControl::SystemAddObjective(int ObjTime, int ObjProc)
{
	try 
	{
		Queue.AddObjective(ObjProc, ObjTime);
	}
	catch (...)
	{
		ObjectiveSkipped++;
	}
}

void SystemControl::ObjectiveToPerformance()
{
	if (FreeProcessors == 0)
		return;
	for (int i = 0; i < Queue.getCurrentSize(); i++)
	{
		if (Queue.GetObjective(i).Priority > 8)
		{
			if (Queue.GetObjective(i).ProcessorAmount <= FreeProcessors)
			{
				ProccessorAmount[AmountOfObjectives] = Queue.GetObjective(i).ProcessorAmount;
				FreeProcessors = FreeProcessors - Queue.GetObjective(i).ProcessorAmount;
				TimeOfObjectiveWork[AmountOfObjectives] = Queue.GetObjective(i).TactTime;
				CurrentTimeOfObjectiveWork[AmountOfObjectives] = 0;
				AmountOfObjectives++;
				Queue.DeleteObjective(i);
			}
			else
				return;
		}
		else
			if (Queue.GetObjective(i).ProcessorAmount <= FreeProcessors)
			{
				ProccessorAmount[AmountOfObjectives] = Queue.GetObjective(i).ProcessorAmount;
				FreeProcessors = FreeProcessors - Queue.GetObjective(i).ProcessorAmount;
				TimeOfObjectiveWork[AmountOfObjectives] = Queue.GetObjective(i).TactTime;
				CurrentTimeOfObjectiveWork[AmountOfObjectives] = 0;
				AmountOfObjectives++;
				Queue.DeleteObjective(i);
			}
	}
}

void SystemControl::FinishingObjective()
{
	for (int i = 0; i < AmountOfObjectives; i++)
	{
		if (CurrentTimeOfObjectiveWork[i] == TimeOfObjectiveWork[i])
		{
			for (int j = 0; j < AmountOfObjectives-1; j++)
			{
				FreeProcessors = FreeProcessors + ProccessorAmount[i];
				ProccessorAmount[j] = ProccessorAmount[j + 1];
				TimeOfObjectiveWork[j] = TimeOfObjectiveWork[j + 1];
				CurrentTimeOfObjectiveWork[j] = CurrentTimeOfObjectiveWork[j + 1];
			}
			AmountOfObjectives--;
			ObjectiveCompleted++;
		}
	}
}

void SystemControl::ShowResults()
{
	setlocale(LC_ALL, "Russian");
	cout << endl;
	cout << "      Результаты" << endl;
	cout <<"Выполнено задач" << endl;
	cout << ObjectiveCompleted << endl;
	cout << "Число задач в очереди"<< endl;
	cout <<Queue.getCurrentSize() << endl;
	cout << "Число пропущенных задач"<< endl;
	cout << ObjectiveSkipped << endl;
	cout <<"Число тактов простоя" << endl;
	cout << AmountOfIdleTacts << endl;
}

void SystemControl::ControlSystemSimulation()
{
	setlocale(LC_ALL, "Russian");
	int  ObjProc;
	int ObjTime;
	for (int i = 0; i < WorkTime; i++)
	{
		FinishingObjective();
		if (1.0*(rand() % 100)/100 > AddThreshold)
		{
			cout << "Введите задачу:" << endl;
			cout << "Кол-во процессоров для задачи" << endl;
			do
			{
				cin >> ObjProc;
				if ((ObjProc < 1) || (ObjProc > 64))
					cout << "Кол-во процессоров должно быть больше 0 и меньше 64" << endl;
				else
					break;
			} while (true);
			cout << "Время выполнения(такты)" << endl;
			do
			{
				cin >> ObjTime;
				if ((ObjTime < 1) || (ObjTime > 11))
					cout << "Кол-во тактов исполнения должно быть больше 0 и меньше 11" << endl;
				else
					break;
			} while (true);
			SystemAddObjective(ObjTime, ObjProc);
		}
		ObjectiveToPerformance();
		Queue.IncreasePriority();
		for (int j = 0; j < AmountOfObjectives; j++)
			CurrentTimeOfObjectiveWork[j]++;
		AmountOfIdleTacts = AmountOfIdleTacts + FreeProcessors;
	}
	ObjectiveCompleted = ObjectiveCompleted + AmountOfObjectives;
	ShowResults();
}