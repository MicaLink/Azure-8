#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestADD()
{
    //-------------------------------------------------
    // Normal Addition
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 10;
        cpu.GetRegister(0x01) = 32;

        memory.Write8(0x0000, 0x32);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

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

        cpu.GetRegister(0x00) = 0;
        cpu.GetRegister(0x01) = 0;

        memory.Write8(0x0000, 0x32);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0);
        assert(cpu.IsFlagSet(FLAG_ZERO));
    }

    //-------------------------------------------------
    // Carry Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 255;
        cpu.GetRegister(0x01) = 1;

        memory.Write8(0x0000, 0x32);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 0);
        assert(cpu.IsFlagSet(FLAG_CARRY));
    }

    //-------------------------------------------------
    // Negative Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 200;
        cpu.GetRegister(0x01) = 0;

        memory.Write8(0x0000, 0x32);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 200);
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

        cpu.GetRegister(0x00) = 127;
        cpu.GetRegister(0x01) = 1;

        memory.Write8(0x0000, 0x32);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.GetRegister(0x00) == 128);
        assert(cpu.IsFlagSet(FLAG_OVERFLOW));
    }
}