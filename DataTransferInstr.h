#pragma once
#include "Instruction.h"
class DataTransferInstr :public Instruction
{
public:
    DataTransferInstr();
    virtual ~DataTransferInstr();

    bool execute(CPU& cpu) override;
};

