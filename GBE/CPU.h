#ifndef CPU_H
#define CPU_H

#include "Common.h"
#include "Instructions.h"

struct Registers
{
	u8 a;
	u8 f;
	u8 b;
	u8 c;
	u8 d;
	u8 e;
	u8 h;
	u8 l;

	u16 stackPointer;
	u16 programCounter;
};

class CPU
{
public:
	CPU();

	void Init();

	bool Step();

private:
	Registers registers;
	Instruction* currentInstruction;

	u16 fetchData;
	u16 memDestination;
	u8 currentOpcode;

	bool halted;
	bool stepping;
};

#endif
