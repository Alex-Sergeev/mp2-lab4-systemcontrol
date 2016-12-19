#include "SystemControl.h"
#include <iostream>

using namespace std;

int main()
{
	double addThreshold;
	int Time;
	setlocale(LC_ALL, "Russian");
	cout << "Введите кол-во тактов работы программы "<< endl;
	do
	{
		cin >> Time;
		if ((Time < 1) || (Time > 100))
			cout << "Кол-во тактов работы не должно быть меньше 0 и не должно быть больше 100" << endl;
		else
			break;
	} while (true);
	cout << " Введите порог появления задач" << endl;
	do
	{
		cin >> addThreshold;
		if ((addThreshold < 0) || (addThreshold > 0.9))
			cout << "Порог от 0 до 1" << endl;
		else
			break;
	} while (true);
	SystemControl system(addThreshold,Time);
	system.ControlSystemSimulation();
	return 0;
}