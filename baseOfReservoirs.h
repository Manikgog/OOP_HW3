#ifndef _BASEOFRESERVOIRS_H_
#define _BASEOFRESERVOIRS_H_

#include <vector>
#include <fstream>
#include "reservoir.h"

//const char* filename = "base_of_reservoirs.txt";

class BaseOfReservoirs
{
private:
	std::vector<Reservoir*> _baseOfReservoirs;


public:
	void AddReservoir(Reservoir* r);						// метод для добавления нового элемента в вектор _baseOfReservoirs
	void ShowBase() const;									// метод для вывода на экран содержимого вектора _baseOfReservoirs
	int GetIndex(const char* const name);					// метод для получения индекса элемента с именем name
	void DeleteElement(const char* const name);				// метод для удаления элемента с именем name
	bool WriteBaseToFile(const char* const filename);		// метод для записи элементов вектора _baseOfReservoirs в текстовый файл
	bool WriteBaseToBinaryFile(const char* const filename); // метод для записи элементов вектора _baseOfReservoirs в бинарный файл
	bool ReadBaseBinaryFile(const char* const filename);	// метод для чтения из бинарного файла
	~BaseOfReservoirs();
};

#endif