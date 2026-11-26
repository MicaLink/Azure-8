#include "../src/Azure8/Memory.h"

#include <cassert>

void TestMemoryBoundaryLow()
{
    Memory memory;

    memory.Write8(0x0000, 0x42);

    assert(memory.Read8(0x0000) == 0x42);
}

void TestMemoryBoundaryHigh()
{
    Memory memory;

    memory.Write8(0xFFFF, 0x42);

    assert(memory.Read8(0xFFFF) == 0x42);
}

void TestMemoryBoundaryRead16Low()
{
    Memory memory;

    memory.Write8(0x0000, 0x34);
    memory.Write8(0x0001, 0x12);

    assert(memory.Read16(0x0000) == 0x1234);
}

void TestMemoryBoundaryRead16High()
{
    Memory memory;

    memory.Write8(0xFFFF, 0x34);
    memory.Write8(0x0000, 0x12);

    const u16 value = memory.Read16(0xFFFF);

    assert(value == 0x1234);
}

void TestMemoryBoundaryWrite16High()
{
    Memory memory;

    memory.Write16(0xFFFF, 0x1234);

    assert(memory.Read8(0xFFFF) == 0x34);
    assert(memory.Read8(0x0000) == 0x12);
}