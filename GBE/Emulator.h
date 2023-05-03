#ifndef EMULATOR_H
#define EMULATOR_H

#include "Common.h"
#include "Cartridge.h"
#include "CPU.h"

class Emulator
{
public:
	static Emulator* GetInstance();

	int Run(int argc, char** argv);

private:
	Emulator() 
	{
		paused = false;
		running = false;
		ticks = 0;
	};

	void Delay(u32 ms);

	static Emulator* instance;

	Cartridge cartridge;
	CPU processor;

	bool paused;
	bool running;
	u64 ticks;
};

#endif
