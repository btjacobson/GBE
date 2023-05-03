#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Common.h"

enum AddressModes
{
    AM_IMP,
    AM_R_D16,
    AM_R_R,
    AM_MR_R,
    AM_R,
    AM_R_D8,
    AM_R_MR,
    AM_R_HLI,
    AM_R_HLD,
    AM_HLI_R,
    AM_HLD_R,
    AM_R_A8,
    AM_A8_R,
    AM_HL_SPR,
    AM_D16,
    AM_D8,
    AM_D16_R,
    AM_MR_D8,
    AM_MR,
    AM_A16_R,
    AM_R_A16
};

enum RegisterTypes 
{
    RT_NONE,
    RT_A,
    RT_F,
    RT_B,
    RT_C,
    RT_D,
    RT_E,
    RT_H,
    RT_L,
    RT_AF,
    RT_BC,
    RT_DE,
    RT_HL,
    RT_SP,
    RT_PC
};

enum InstructionTypes
{
    IT_NONE,
    IT_NOP,
    IT_LD,
    IT_INC,
    IT_DEC,
    IT_RLCA,
    IT_ADD,
    IT_RRCA,
    IT_STOP,
    IT_RLA,
    IT_JR,
    IT_RRA,
    IT_DAA,
    IT_CPL,
    IT_SCF,
    IT_CCF,
    IT_HALT,
    IT_ADC,
    IT_SUB,
    IT_SBC,
    IT_AND,
    IT_XOR,
    IT_OR,
    IT_CP,
    IT_POP,
    IT_JP,
    IT_PUSH,
    IT_RET,
    IT_CB,
    IT_CALL,
    IT_RETI,
    IT_LDH,
    IT_JPHL,
    IT_DI,
    IT_EI,
    IT_RST,
    IT_ERR,
    IT_RLC,
    IT_RRC,
    IT_RL,
    IT_RR,
    IT_SLA,
    IT_SRA,
    IT_SWAP,
    IT_SRL,
    IT_BIT,
    IT_RES,
    IT_SET
};

enum ConditionTypes
{
    CT_NONE, 
    CT_NZ, 
    CT_Z, 
    CT_NC, 
    CT_C
};


class Instruction
{
public:
    Instruction(InstructionTypes inType = IT_NONE, AddressModes adMode = AM_IMP, 
        RegisterTypes reTypeOne = RT_NONE, RegisterTypes reTypeTwo = RT_NONE, 
        ConditionTypes coType = CT_NONE, u8 params = NULL);

private:
    InstructionTypes instructionType;
    AddressModes addressMode;
    RegisterTypes registerTypeOne;
    RegisterTypes registerTypeTwo;
    ConditionTypes conditionType;
    u8 parameters;
};

class InstructionManager
{
public:
    InstructionManager();

    Instruction* GetByOpcode(u8 opcode);

    char* GetName(InstructionTypes type);

private:
    Instruction instructions[0x100];
    const char* instructionLookup[48] =
    {
        "<NONE>",
        "NOP",
        "LD",
        "INC",
        "DEC",
        "RLCA",
        "ADD",
        "RRCA",
        "STOP",
        "RLA",
        "JR",
        "RRA",
        "DAA",
        "CPL",
        "SCF",
        "CCF",
        "HALT",
        "ADC",
        "SUB",
        "SBC",
        "AND",
        "XOR",
        "OR",
        "CP",
        "POP",
        "JP",
        "PUSH",
        "RET",
        "CB",
        "CALL",
        "RETI",
        "LDH",
        "JPHL",
        "DI",
        "EI",
        "RST",
        "IN_ERR",
        "IN_RLC",
        "IN_RRC",
        "IN_RL",
        "IN_RR",
        "IN_SLA",
        "IN_SRA",
        "IN_SWAP",
        "IN_SRL",
        "IN_BIT",
        "IN_RES",
        "IN_SET"
    };
};

#endif
