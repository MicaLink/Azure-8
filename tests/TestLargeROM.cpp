#include "../src/Azure8/Emulator.h"

#include <cassert>
#include <cstdio>

void TestROMTooLarge()
{
    FILE* file = nullptr;

    fopen_s(&file, "LargeROM.bin", "wb");

    assert(file != nullptr);

    for (u32 i = 0; i < RAM_SIZE + 1; i++)
    {
        fputc(0xAA, file);
    }
    
    fclose(file);

    Emulator emulator;

    const bool result = emulator.LoadROM("LargeROM.bin");

    assert(result == false);

    remove("LargeROM.bin");
}

void TestROMMaximumSize()
{
    FILE* file = nullptr;

    fopen_s(&file, "MaxROM.bin", "wb");

    assert(file != nullptr);

    for (u32 i = 0; i < RAM_SIZE; i++)
    {
        fputc(0xAA, file);
    }
    
    fclose(file);

    Emulator emulator;

    const bool result = emulator.LoadROM("MaxROM.bin");

    assert(result == true);

    remove("MaxROM.bin");
}