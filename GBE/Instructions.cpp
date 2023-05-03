#include "Instructions.h"

Instruction::Instruction(InstructionTypes inType, AddressModes adMode,
	RegisterTypes reTypeOne, RegisterTypes reTypeTwo, ConditionTypes coType, u8 params)
{

}

InstructionManager::InstructionManager()
{
	instructions[0x00] = Instruction(IT_NOP, AM_IMP);
	instructions[0x05] = Instruction(IT_DEC, AM_R, RT_B);
	instructions[0x0E] = Instruction(IT_LD, AM_R_D8, RT_C);
	instructions[0xAF] = Instruction(IT_XOR, AM_R, RT_A);
	instructions[0xC3] = Instruction(IT_JP, AM_D16);
	instructions[0xF3] = Instruction(IT_DI);
}

Instruction* InstructionManager::GetByOpcode(u8 opcode)
{
	return nullptr;
}

char* InstructionManager::GetName(InstructionTypes type)
{
	return nullptr;
}
