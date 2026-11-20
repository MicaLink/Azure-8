#include "Emulator.h"

#include <cstdio>

//-----------------------------------------------------
// GetMemory
//-----------------------------------------------------

Memory& Emulator::GetMemory()
{
    return m_Memory;
}

CPU& Emulator::GetCPU()
{
    return m_CPU;
}

//-----------------------------------------------------
// LoadROM
//-----------------------------------------------------

bool Emulator::LoadROM(const char* fileName)
{
    FILE* file = nullptr;

    fopen_s(&file, fileName, "rb");

    if (!file)
        return false;
    
    u32 address = 0;

    while (!feof(file))
    {
        const int byte = fgetc(file);

        if (byte == EOF)
            break;

        if (address >= RAM_SIZE)
        {
            printf("ROM TOO LARGE\n");
            fclose(file);
            return false;
        }
        

        m_Memory.Write8(static_cast<u16>(address), static_cast<u8>(byte));

        address++;
    }
    
    fclose(file);

    printf("ROM Loaded\n");

    return true;
}

//-----------------------------------------------------
// Reset
//-----------------------------------------------------

void Emulator::Reset()
{
    m_Memory.Reset();
    m_CPU.Reset();
}

//-----------------------------------------------------
// Run
//-----------------------------------------------------

void Emulator::Run()
{
    constexpr u32 MAX_CYCLES = 1000000;

    u32 cycles = 0;

    while (!m_CPU.IsHalted())
    {
        m_CPU.Step(m_Memory);

        cycles++;

        if (cycles >= MAX_CYCLES)
        {
            printf("MAX CYCLES REACHED\n");
            break;
        }
        
    }
    printf("Execution Completed\n");
}