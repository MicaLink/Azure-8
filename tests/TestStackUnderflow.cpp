#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestStackUnderflowPop8()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();

    cpu.Pop8(memory);

    assert(cpu.HasStackUnderflow());
}

void TestStackUnderflowPop16()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();

    cpu.Pop16(memory);

    assert(cpu.HasStackUnderflow());
}