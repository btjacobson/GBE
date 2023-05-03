#include "Emulator.h"

int main(int argc, char** argv)
{
	Emulator::GetInstance()->Run(argc, argv);

	return 0;
}