#ifndef _RESERVOIR_H_
#define _RESERVOIR_H_

#include <string>
#include <iostream>

class Reservoir
{
private:
	char* _type;
	char* _name;
	char* _unitOfMeasurement;
	double _length;
	double _width;
	double _depth;

public:
	// конструктор по умолчанию
	Reservoir();
	// конструктор с параметрами
	explicit Reservoir(const char* type, const char* name, const char* unitOfMeasurment, double length, double width, double depth);
	// конструктор копирования
	explicit Reservoir(const Reservoir& reservoir);
	
	~Reservoir();

	char* GetName() const
	{
		return _name;
	}

	char* GetType() const
	{
		return _type;
	}

	char* GetUnitOfMeasurement() const
	{
		return _unitOfMeasurement;
	}

	double GetLength() const
	{
		return _length;
	}

	double GetWidth() const
	{
		return _width;
	}

	double GetDepth() const
	{
		return _depth;
	}

	// метод для расчёта примерного объёма водоёма
	double ApproximateVolume()
	{
		return _length * _width * _depth;
	}
	
	// метод для расчёта примерной площади поверхности
	double SurfaceArea()
	{
		return _length * _width;
	}

	// метод для сравнения типов водоёмов
	bool CheckTypes(const Reservoir& r) const;

	// метод для сравнения площадей поверхности водоёмов
	int CompareSurfaceArea(Reservoir& r);

	void ShowData() const;

};

#endif