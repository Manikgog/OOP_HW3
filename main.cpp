/*
Тема: Константная функция-член, explicit конструктор.
Задание.
Разработать класс Reservoir(водоем). Класс должен обязательно иметь поле «название».
Класс должен содержать:
конструктор по умолчанию, конструктор с параметрами,
при необходимости реализовать деструктор и конструктор копирования.
Добавить методы для:
1. Определения приблизительного объема (ширина*длина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному
типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов
одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).
Написать интерфейс для работы с классом. Реализовать
динамический массив объектов класса с возможностью
добавления, удаления объектов из массива. Реализовать
возможность записи информации об объектах массива
в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функции члены
(например, для отображения данных о водоёме и т.д.).
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

	Reservoir r2("Море", "Чёрное море", "км", 1150, 580, 1.24);
	//r2.ShowData();
	//std::cout << "Примерный объём: " << r2.ApproximateVolume() << " куб." << r2.GetUnitOfMeasurement() << ".\n\n";

	Reservoir r3("озеро", "Байкал", "км", 636, 79, 1.187);
	/*r3.ShowData();
	std::cout << "Примерный объём: " << r3.ApproximateVolume() << " куб." << r3.GetUnitOfMeasurement() << ".\n\n";*/

	Reservoir r4(r3);
	//r4.ShowData();
	//std::cout << "Примерный объём: " << r4.ApproximateVolume() << " куб." << r4.GetUnitOfMeasurement() << ".\n\n";

	Reservoir r5("озеро", "Онежское озеро", "км", 248, 91, 0.03);
	//std::cout << r5.CheckTypes(r3) << std::endl;

	Reservoir r6("МОРЕ", "Азовское море", "км", 380, 200, 0.0074);

	/*if (r3.CompareSurfaceArea(r5) == 1)
		std::cout << "Озеро " << r3.GetName() << " больше озера " << r5.GetName() << std::endl;*/

	BaseOfReservoirs base;
	base.AddReservoir(&r2);
	base.AddReservoir(&r3);
	base.AddReservoir(&r5);
	base.AddReservoir(&r6);
	base.WriteBaseToFile("base_of_reservoirs.txt");
	base.ShowBase();
	std::cout << "\n--------------------------------------------------\n";
	base.DeleteElement("Байкал");
	base.ShowBase();

	return 0;
}
