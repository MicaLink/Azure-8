#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestINC()
{
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 41;

        memory.Write8(0x0000, 0x30);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 42);
    }

    //-------------------------------------------------
    // Zero Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 0xFF;

        memory.Write8(0x0000, 0x30);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0x00);
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

        cpu.GetRegister(0x00) = 0x7F;

        memory.Write8(0x0000, 0x30);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0x80);
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

        cpu.GetRegister(0x00) = 0x7F;
        
        memory.Write8(0x0000, 0x30);
        memory.Write8(0x0001, 0x00);

        cpu.Step(memory);

        assert(cpu.IsFlagSet(FLAG_OVERFLOW));
    }
}