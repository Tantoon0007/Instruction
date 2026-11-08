#include "Instruction.h"
#include "DataTransferInstr.h"
#include "ControlInstr.h"
using namespace std;
Instruction::Instruction()
{
    opcode = 0;
    r = 0;
    s = 0;
    t = 0;
    xy = 0;
}

Instruction::~Instruction() {}

void Instruction::decode(unsigned short word)
{
    opcode = (word >> 12) & 0xF;
    r = (word >> 8) & 0xF;
    s = (word >> 4) & 0xF;
    t = word & 0xF;
    xy = word & 0xFF;
}

bool Instruction::isValid(unsigned short word)
{
    int op = (word >> 12) & 0xF;
    int R = (word >> 8) & 0xF;

    switch (op)
    {
    case 0x1:
    case 0x2:
    case 0x3:
    case 0xB:
        return true;

    case 0x4:
        return R == 0;

    case 0xC:
        return word == 0xC000;

    default:
        return false;
    }
}

unique_ptr<Instruction> Instruction::create(unsigned short word)
{
    if (!isValid(word))
        return nullptr;

    int op = (word >> 12) & 0xF;

    unique_ptr<Instruction> ins = nullptr;

    if (op >= 0x1 && op <= 0x4)
    {
        ins = make_unique<DataTransferInstr>();
    }
    else if (op == 0xB || op == 0xC)
    {
        ins = make_unique<ControlInstr>();
    }

    if (ins != nullptr)
    {
        ins->decode(word);
    }

    return ins;
}
