#pragma once
#include <iostream>
#include <memory>
using namespace std;

class CPU;

class Instruction
{
protected:
    int opcode;
    int r;
    int s;
    int t;
    unsigned char xy;

    Instruction();
    void decode(unsigned short word);

public:
    virtual ~Instruction();

    static unique_ptr<Instruction> create(unsigned short word);
    static bool isValid(unsigned short word);

    virtual bool execute(CPU& cpu) = 0;
};