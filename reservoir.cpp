#include "reservoir.h"

Reservoir::Reservoir()
{
	_type = new char('\0');
	_name = new char('\0');
	_unitOfMeasurement = new char('\0');
	_length = 0;
	_width = 0;
	_depth = 0;
}

Reservoir::Reservoir(const char* type, const char* name, const char* unitOfMeasurement, double length, double width, double depth)
{
	if(_type)
			delete[] _type;
	_type = new char[lengthOfString] {};
	for (int i = 0; i < strlen(type); ++i)
	{
		if (type[i] == ' ')
			continue;
		_type[i] = tolower(type[i]);
	}

	if(_name)
			delete[] _name;
	_name = new char[lengthOfString] {};
	for (int i = 0; i < strlen(name) + 1; ++i)
	{
		_name[i] = name[i];
	}

	if (_unitOfMeasurement)
		delete[] _unitOfMeasurement;
	_unitOfMeasurement = new char[lengthOfString] {};
	for (int i = 0; i < strlen(unitOfMeasurement) + 1; ++i)
	{
		_unitOfMeasurement[i] = tolower(unitOfMeasurement[i]);
	}

	_length = length;
	_width = width;
	_depth = depth;
}

Reservoir::Reservoir(const Reservoir& reservoir)
{
	if (_type)
		delete[] _type;
	_type = new char[lengthOfString] {};
	for (int i = 0; i < strlen(reservoir._type) + 1; ++i)
	{
		_type[i] = reservoir._type[i];
	}

	if (_name)
		delete[] _name;
	_name = new char[lengthOfString] {};
	for (int i = 0; i < strlen(reservoir._name) + 1; ++i)
	{
		_name[i] = reservoir._name[i];
	}

	if (_unitOfMeasurement)
		delete[] _unitOfMeasurement;
	_unitOfMeasurement = new char[lengthOfString] {};
	for (int i = 0; i < strlen(reservoir._unitOfMeasurement) + 1; ++i)
	{
		_unitOfMeasurement[i] = reservoir._unitOfMeasurement[i];
	}

	_length = reservoir._length;
	_width = reservoir._width;
	_depth = reservoir._depth;
}

Reservoir::~Reservoir()
{
	if (_name)
		delete[] _name;
	if (_type)
		delete[] _type;
	if (_unitOfMeasurement)
		delete[] _unitOfMeasurement;
}

void Reservoir::ShowData() const
{
	std::cout << "\nТип водоёма: " << _type << ";\n";
	std::cout << "Название водоёма: " << _name << ";\n";
	std::cout << "Длина водоёма: " << _length << ' ' << _unitOfMeasurement << ";\n";
	std::cout << "Ширина водоёма: " << _width << ' ' << _unitOfMeasurement << ";\n";
	std::cout << "Глубина водоёма: " << _depth << ' ' << _unitOfMeasurement << ".\n";

}

bool Reservoir::CheckTypes(const Reservoir& r) const
{
	if (strcmp(_type, r._type) == 0)
		return true;
	return false;
}

int Reservoir::CompareSurfaceArea(Reservoir& r) 
{
	if (!CheckTypes(r))
	{
		std::cout << "Водоёмы разных типов.\n";
		return -2;
	}
	else
	{
		if (SurfaceArea() == r.SurfaceArea())
		{
			return 0;							// возвращает ноль если площади поверхности водоёмов одинаковые
		}
		else if (SurfaceArea() > r.SurfaceArea())
		{
			return 1;							// возвращает 1 если площадь текущего объекта больше площади переданного методу
		}
	}
	return -1;									// возвращает -1 если площадь переданного объекта больше площади текущего
}