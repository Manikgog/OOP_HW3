#include "baseOfReservoirs.h"

void BaseOfReservoirs::AddReservoir(Reservoir* r)
{
	Reservoir* tmp = new Reservoir(*r);
	_baseOfReservoirs.push_back(tmp);
}


void BaseOfReservoirs::ShowBase() const
{
	for (const auto& it : _baseOfReservoirs)
	{
		it->ShowData();
	}
}

int BaseOfReservoirs::GetIndex(const char* const name)
{
	for (int i = 0; i < _baseOfReservoirs.size(); ++i)
	{
		if (strcmp(_baseOfReservoirs[i]->GetName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void BaseOfReservoirs::DeleteElement(const char* const name)
{
	int index = GetIndex(name);
	if (index >= 0)
	{
		_baseOfReservoirs.erase(_baseOfReservoirs.begin() + index);
	}
}

BaseOfReservoirs::~BaseOfReservoirs()
{
	if (_baseOfReservoirs.size())
	{
		for (const auto& it : _baseOfReservoirs)
		{
			if (it != nullptr)
				delete it;
		}
	}
}

bool BaseOfReservoirs::WriteBaseToFile(const char*const filename)
{
	std::ofstream fout;
	fout.open(filename);
	if (fout.is_open())
	{
		for (const auto& it : _baseOfReservoirs)
		{
			fout << it->GetType() << '\n';
			fout << it->GetName() << '\n';
			fout << it->GetLength() << '\n';
			fout << it->GetWidth() << '\n';
			fout << it->GetDepth() << '\n';
		}
		fout.close();
		return true;
	}
	return false;
}

bool BaseOfReservoirs::WriteBaseToBinaryFile(const char* const filename)
{
	std::ofstream fout;
	fout.open(filename, std::ios::binary);
	if (fout.is_open())
	{
		struct reservoir
		{
			char type[lengthOfString];
			char name[lengthOfString];
			char unitOfMeasurement[lengthOfString];
			double length;
			double width;
			double depth;
		};
		for (int j = 0; j < _baseOfReservoirs.size(); ++j)
		{
			static reservoir res;
			for (int i = 0; i < lengthOfString; ++i)
			{
				res.type[i] = _baseOfReservoirs[j]->GetType()[i];
			}
			for (int i = 0; i < lengthOfString; ++i)
			{
				res.name[i] = _baseOfReservoirs[j]->GetName()[i];
			}
			for (int i = 0; i < lengthOfString; ++i)
			{
				res.unitOfMeasurement[i] = _baseOfReservoirs[j]->GetUnitOfMeasurement()[i];
			}
			res.length = _baseOfReservoirs[j]->GetLength();
			res.width = _baseOfReservoirs[j]->GetWidth();
			res.depth = _baseOfReservoirs[j]->GetDepth();
			

			fout.write((char*)&res, sizeof(reservoir));
		}


		fout.close();
		return true;
	}
	return false;
}

bool BaseOfReservoirs::ReadBaseBinaryFile(const char* const filename)
{
	std::ifstream fin;
	fin.open(filename, std::ios::binary);
	if (fin.is_open())
	{
		struct reservoir
		{
			char type[lengthOfString];
			char name[lengthOfString];
			char unitOfMeasurement[lengthOfString];
			double length;
			double width;
			double depth;
		};

		reservoir res;
		while (fin.read((char*)&res, sizeof(reservoir)))
		{
			_baseOfReservoirs.push_back(new Reservoir(res.type, res.name, res.unitOfMeasurement, res.length, res.width, res.depth));
		}

		return true;
	}
	return false;
}