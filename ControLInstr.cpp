
#include "ControlInstr.h"
#include "CPU.h"

ControlInstr::ControlInstr() : Instruction() {}

ControlInstr::~ControlInstr() {}

bool ControlInstr::execute(CPU& cpu)
{
    switch (opcode)
    {
    case 0xB:
    {
        if (cpu.regs_.get(r) == cpu.regs_.get(0))
        {
            cpu.setPC(xy);
        }

        return true;
    }

    case 0xC:
    {
        cpu.halt();
        return true;
    }

    default:
        return false;
    }
}

