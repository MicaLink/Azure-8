#include "../src/Azure8/CPU.h"
#include "../src/Azure8/Memory.h"

#include <cassert>

void TestStackOverflow()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();

    while (!cpu.HasStackOverflow())
    {
        cpu.Push8(memory, 0xAA);
    }
    
    assert(cpu.HasStackOverflow());
}

void TestStackOverflowPush16()
{
    CPU cpu;
    Memory memory;

    cpu.Reset();

    while (!cpu.HasStackOverflow())
    {
        cpu.Push16(memory, 0x1234);
    }
    
    assert(cpu.HasStackOverflow());
}