#include <cstdio>

//-----------------------------------------------------
// Emulator
//-----------------------------------------------------

void TestROMMaximumSize();
void TestROMTooLarge();

//-----------------------------------------------------
// Infinite Loop
//-----------------------------------------------------

void TestMaxCycles();

//-----------------------------------------------------
// Memory
//-----------------------------------------------------

void TestReadWrite8();
void TestReadWrite16();

//-----------------------------------------------------
// Stack
//-----------------------------------------------------

void TestPushPop8();
void TestPushPop16();

//-----------------------------------------------------
// Flags
//-----------------------------------------------------

void TestZeroFlag();
void TestNegativeFlag();
void TestCarryFlag();
void TestOverflowFlag();

//-----------------------------------------------------
// Stack Overflow
//-----------------------------------------------------

void TestStackOverflow();
void TestStackOverflowPush16();

//-----------------------------------------------------
// Stack Underflow
//-----------------------------------------------------

void TestStackUnderflowPop8();
void TestStackUnderflowPop16();

//-----------------------------------------------------
// Memory Boundary
//-----------------------------------------------------

void TestMemoryBoundaryLow();
void TestMemoryBoundaryHigh();

void TestMemoryBoundaryRead16Low();
void TestMemoryBoundaryRead16High();

void TestMemoryBoundaryWrite16High();

//-----------------------------------------------------
// CPU
//-----------------------------------------------------

void TestReset();

//-----------------------------------------------------
// Instructions
//-----------------------------------------------------

void TestMOV();
void TestLOAD();
void TestSTORE();

void TestPUSH();
void TestPOP();
void TestCALL();
void TestRET();

void TestINC();
void TestDEC();
void TestADD();
void TestSUB();

void TestCMP();
void TestJMP();
void TestJZ();
void TestJNZ();

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    printf("========================================\n");
    printf("AzureEngine Test Suite\n");
    printf("========================================\n\n");

    //-------------------------------------------------
    // Emulator
    //-------------------------------------------------

    printf("Running Large ROM Tests...\n");

    TestROMMaximumSize();
    TestROMTooLarge();

    printf("Large ROM Tests Passed\n\n");

    //-------------------------------------------------
    // Infinite Loop
    //-------------------------------------------------

    printf("Running Max Cycles Tests...\n");

    TestMaxCycles();

    printf("Max Cycles Tests Passed\n\n");

    //-------------------------------------------------
    // Memory
    //-------------------------------------------------

    printf("Running Memory Tests...\n");

    TestReadWrite8();
    TestReadWrite16();

    printf("Memory Tests Passed\n\n");

    //-------------------------------------------------
    // Stack
    //-------------------------------------------------

    printf("Running Stack Tests...\n");

    TestPushPop8();
    TestPushPop16();

    printf("Stack Tests Passed\n\n");

    //-------------------------------------------------
    // Flags
    //-------------------------------------------------

    printf("Running Flags Tests...\n");

    TestZeroFlag();
    TestNegativeFlag();
    TestCarryFlag();
    TestOverflowFlag();

    printf("Flags Tests Passed\n\n");

    //-------------------------------------------------
    // Instructions
    //-------------------------------------------------

    printf("Running Instruction Tests...\n");

    TestMOV();
    TestLOAD();
    TestSTORE();

    TestPUSH();
    TestPOP();
    TestCALL();
    TestRET();

    TestINC();
    TestDEC();
    TestADD();
    TestSUB();

    TestCMP();
    TestJMP();
    TestJZ();
    TestJNZ();

    printf("Instruction Tests Passed\n\n");

    //-----------------------------------------------------
    // Stack Overflow
    //-----------------------------------------------------

    printf("Running Stack Overflow Tests...\n");

    TestStackOverflow();
    TestStackOverflowPush16();

    printf("Stack Overflow Tests Passed\n\n");

    //-----------------------------------------------------
    // Stack Underflow
    //-----------------------------------------------------

    printf("Running Stack Underflow Tests...\n");

    TestStackUnderflowPop8();
    TestStackUnderflowPop16();

    printf("Stack Underflow Tests Passed\n\n");

    //-------------------------------------------------
    // Memory Boundary
    //-------------------------------------------------

    printf("Running Memory Boundary Tests...\n");

    TestMemoryBoundaryLow();
    TestMemoryBoundaryHigh();

    TestMemoryBoundaryRead16Low();
    TestMemoryBoundaryRead16High();

    TestMemoryBoundaryWrite16High();

    printf("Memory Boundary Tests Passed\n\n");

    //-------------------------------------------------
    // CPU
    //-------------------------------------------------
    
    printf("Running CPU Tests...\n");

    TestReset();

    printf("CPU Tests Passed\n\n");

    //-------------------------------------------------
    // Success
    //-------------------------------------------------

    printf("========================================\n");
    printf("All tests passed successfully.\n");
    printf("========================================\n");

    return 0;
}