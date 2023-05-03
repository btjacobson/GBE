#ifndef BUS_H
#define BUS_H

#include "Common.h"
#include "Cartridge.h"

class Bus
{
public:
	Bus(Cartridge* cart);

	u8 Read(u16 address);

	void Write(u16 address, u8 value);

private:
	Cartridge* cartridge;
};

#endif
