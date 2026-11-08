
#include "DataTransferInstr.h"
#include "CPU.h"

DataTransferInstr::DataTransferInstr() : Instruction() {}

DataTransferInstr::~DataTransferInstr() {}

bool DataTransferInstr::execute(CPU& cpu)
{
    switch (opcode)
    {
    case 0x1:
    {
        unsigned char value = cpu.memory_.read(xy);
        cpu.regs_.set(r, value);
        return true;
    }

    case 0x2:
    {
        cpu.regs_.set(r, xy);
        return true;
    }

    case 0x3:
    {
        unsigned char value = cpu.regs_.get(r);

        if (xy == 0xFF)
        {
            cpu.screen_.write(value);
        }
        else
        {
            cpu.memory_.write(xy, value);
        }

        return true;
    }

    case 0x4:
    {
        unsigned char value = cpu.regs_.get(s);
        cpu.regs_.set(t, value);
        return true;
    }

    default:
        return false;
    }
}


