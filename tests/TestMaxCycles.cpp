#include "../src/Azure8/Emulator.h"

#include <cassert>
#include <cstdio>

void TestMaxCycles()
{
    FILE* file = nullptr;

    fopen_s(&file, "InfiniteLoop.bin", "wb");

    assert(file != nullptr);

    fputc(0x41, file);
    fputc(0x00, file);
    fputc(0x00, file);

    fclose(file);

    Emulator emulator;

    const bool loaded = emulator.LoadROM("InfiniteLoop.bin");

    assert(loaded);

    emulator.Run();

    remove("InfiniteLoop.bin");
}