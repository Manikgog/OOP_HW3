/*
����: ����������� �������-����, explicit �����������.
�������.
����������� ����� Reservoir(������). ����� ������ ����������� ����� ���� ���������.
����� ������ ���������:
����������� �� ���������, ����������� � �����������,
��� ������������� ����������� ���������� � ����������� �����������.
�������� ������ ���:
1. ����������� ���������������� ������ (������*�����*������������ �������);
2. ����������� ������� ������ �����������;
3. ����� ��� �������� ��������� �� ������� � ������
���� (����-����; �������-����);
4. ��� ��������� ������� ������ ����������� ��������
������ ����;
5. ��� ����������� ��������;
6. ��������� ������ �� ���������� ������������ (������ set � get).
�������� ��������� ��� ������ � �������. �����������
������������ ������ �������� ������ � ������������
����������, �������� �������� �� �������. �����������
����������� ������ ���������� �� �������� �������
� ��������� ����, �������� ����.
����������� explicit ����������� � ����������� ������� �����
(��������, ��� ����������� ������ � ������ � �.�.).
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "reservoir.h"
#include "baseOfReservoirs.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 

	//Reservoir r1;
	//r1.ShowData();

	Reservoir r2("����", "׸���� ����", "��", 1150, 580, 1.24);
	//r2.ShowData();
	//std::cout << "��������� �����: " << r2.ApproximateVolume() << " ���." << r2.GetUnitOfMeasurement() << ".\n\n";

	Reservoir r3("�����", "������", "��", 636, 79, 1.187);
	/*r3.ShowData();
	std::cout << "��������� �����: " << r3.ApproximateVolume() << " ���." << r3.GetUnitOfMeasurement() << ".\n\n";*/

	//Reservoir r4(r3);
	//r4.ShowData();
	//std::cout << "��������� �����: " << r4.ApproximateVolume() << " ���." << r4.GetUnitOfMeasurement() << ".\n\n";

	Reservoir r5("�����", "�������� �����", "��", 248, 91, 30);
	//std::cout << r5.CheckTypes(r3) << std::endl;

	/*if (r3.CompareSurfaceArea(r5) == 1)
		std::cout << "����� " << r3.GetName() << " ������ ����� " << r5.GetName() << std::endl;*/

	BaseOfReservoirs base;
	base.AddReservoir(&r2);
	base.AddReservoir(&r3);
	base.AddReservoir(&r5);
	base.WriteBaseToFile("base_of_reservoirs.txt");
	base.ShowBase();
	std::cout << "\n--------------------------------------------------\n";
	base.DeleteElement("������");
	base.ShowBase();

	return 0;
}
