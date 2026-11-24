#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestDEC()
{
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 42;

        memory.Write8(0x0000, 0x31);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 41);
    }

    //-------------------------------------------------
    // Zero Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 1;

        memory.Write8(0x0000, 0x31);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0);
        assert(cpu.IsFlagSet(FLAG_ZERO));
    }

    //-------------------------------------------------
    // Negative Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 0;

        memory.Write8(0x0000, 0x31);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0xFF);
        assert(cpu.IsFlagSet(FLAG_NEGATIVE));
    }

    //-------------------------------------------------
    // Overflow Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 0x80;

        memory.Write8(0x0000, 0x31);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0x7F);
        assert(cpu.IsFlagSet(FLAG_OVERFLOW));
    }
}