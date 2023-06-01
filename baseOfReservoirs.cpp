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