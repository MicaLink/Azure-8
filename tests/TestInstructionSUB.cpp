#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestSUB()
{
    {
        //-------------------------------------------------
        // Normal Substraction
        //-------------------------------------------------
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();
    
        cpu.GetRegister(0x00) = 50;
        cpu.GetRegister(0x01) = 8;

        memory.Write8(0x0000, 0x33);
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

        cpu.GetRegister(0x00) = 42;
        cpu.GetRegister(0x01) = 42;

        memory.Write8(0x0000, 0x33);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

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

        cpu.GetRegister(0x00) = 10;
        cpu.GetRegister(0x01) = 42;

        memory.Write8(0x0000, 0x33);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.IsFlagSet(FLAG_NEGATIVE));
    }

    //-------------------------------------------------
    // Carry Flag
    //-------------------------------------------------
    {
        CPU cpu;
        Memory memory;

        cpu.Reset();
        memory.Reset();

        cpu.GetRegister(0x00) = 0;
        cpu.GetRegister(0X01) = 1;

        memory.Write8(0x0000, 0x33);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.IsFlagSet(FLAG_CARRY));
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
        cpu.GetRegister(0x01) = 0x01;

        memory.Write8(0x0000, 0x33);
        memory.Write8(0x0001, 0x00);
        memory.Write8(0x0002, 0x01);

        cpu.Step(memory);

        assert(cpu.IsFlagSet(FLAG_OVERFLOW));
    }
}