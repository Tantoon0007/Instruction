#pragma once
#include "Instruction.h"

class ControlInstr : public Instruction
{
public:
    ControlInstr();
    virtual ~ControlInstr();

    bool execute(CPU& cpu) override;
};

