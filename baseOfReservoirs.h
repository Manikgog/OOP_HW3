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
	void AddReservoir(Reservoir* r);
	void ShowBase() const;
	int GetIndex(const char* const name);
	void DeleteElement(const char* const name);
	bool WriteBaseToFile(const char* const filename);
	~BaseOfReservoirs();
};

#endif