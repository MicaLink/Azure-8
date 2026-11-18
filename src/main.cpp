#include "Azure8/Emulator.h"

#include <cstdio>

int main()
{
    //-------------------------------------------------
    // Configuration
    //-------------------------------------------------

    constexpr const char* ROM_PATH = "roms/add.rom";

    //-------------------------------------------------
    // Init
    //-------------------------------------------------

    Emulator emulator;

    emulator.Reset();

    //-------------------------------------------------
    // Load ROM
    //-------------------------------------------------

    if (!emulator.LoadROM(ROM_PATH))
    {
        printf("FAILED TO LOAD ROM\n");

        return 1;
    }

    //-------------------------------------------------
    // Initialisation
    //-------------------------------------------------

    emulator.GetCPU().GetRegister(0x00) = 0x42;

    //-------------------------------------------------
    // Affichage initial
    //-------------------------------------------------

    printf("\n");
    printf("========================================\n");
    printf("Azure-8 Stack Overflow Validation\n");
    printf("========================================\n");
    printf("\n");

    printf("SP before execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf("Overflow before execution = %s\n",
        emulator.GetCPU().HasStackOverflow() ? "TRUE" : "FALSE");

    printf("\n");

    //-------------------------------------------------
    // Execution
    //-------------------------------------------------

    emulator.Run();

    //-------------------------------------------------
    // Resultats
    //-------------------------------------------------

    printf("\n");

    printf("SP after execution = %04X\n",
        emulator.GetCPU().GetSP());

    printf("Overflow detected = %s\n",
        emulator.GetCPU().HasStackOverflow() ? "TRUE" : "FALSE");

    printf("CPU halted        = %s\n",
        emulator.GetCPU().IsHalted() ? "TRUE" : "FALSE");

    printf("\n");

    if (emulator.GetCPU().HasStackOverflow())
    {
        printf("STACK OVERFLOW validation : SUCCESS\n");
    }
    else
    {
        printf("STACK OVERFLOW validation : FAILED\n");
    }

    printf("\n");

    printf("========================================\n");
    printf("Overflow ROM Validation Completed\n");
    printf("========================================\n");

    return 0;
}