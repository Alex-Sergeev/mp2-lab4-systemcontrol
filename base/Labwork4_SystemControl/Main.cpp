#include "SystemControl.h"
#include <iostream>

using namespace std;

int main()
{
	double addThreshold;
	int Time;
	setlocale(LC_ALL, "Russian");
	cout << "������� ���-�� ������ ������ ��������� "<< endl;
	do
	{
		cin >> Time;
		if ((Time < 1) || (Time > 100))
			cout << "���-�� ������ ������ �� ������ ���� ������ 0 � �� ������ ���� ������ 100" << endl;
		else
			break;
	} while (true);
	cout << " ������� ����� ��������� �����" << endl;
	do
	{
		cin >> addThreshold;
		if ((addThreshold < 0) || (addThreshold > 0.9))
			cout << "����� �� 0 �� 1" << endl;
		else
			break;
	} while (true);
	SystemControl system(addThreshold,Time);
	system.ControlSystemSimulation();
	return 0;
}