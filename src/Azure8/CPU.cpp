#include "CPU.h"
#include "Memory.h"

#include <cstdio>

namespace
{
    //-------------------------------------------------
    // Opcodes
    //-------------------------------------------------

    constexpr u8 OPCODE_NOP = 0x00;

    constexpr u8 OPCODE_MOV = 0x10;
    constexpr u8 OPCODE_LOAD = 0x11;
    constexpr u8 OPCODE_STORE = 0x12;

    constexpr u8 OPCODE_PUSH = 0x20;
    constexpr u8 OPCODE_POP = 0x21;
    constexpr u8 OPCODE_CALL = 0x22;
    constexpr u8 OPCODE_RET = 0x23;

    constexpr u8 OPCODE_INC = 0x30;
    constexpr u8 OPCODE_DEC = 0x31;
    constexpr u8 OPCODE_ADD = 0x32;
    constexpr u8 OPCODE_SUB = 0x33;

    constexpr u8 OPCODE_CMP = 0x40;
    constexpr u8 OPCODE_JMP = 0x41;
    constexpr u8 OPCODE_JZ = 0x42;
    constexpr u8 OPCODE_JNZ = 0x43;

    constexpr u8 OPCODE_HLT = 0xFF;

    //-------------------------------------------------
    // Stack
    //-------------------------------------------------

    constexpr u16 STACK_BOTTOM = 0xFE00;
    constexpr u16 STACK_TOP = 0xFFFF;
}
//-----------------------------------------------------
// Reset
//-----------------------------------------------------

void CPU::Reset()
{
    A = 0;
    B = 0;
    C = 0;
    D = 0;

    PC = 0x0000;
    SP = STACK_TOP;

    FLAGS = 0;

    m_Halted = false;

    m_StackOverflow = false;
    m_StackUnderflow = false;
}

//-----------------------------------------------------
// IsHalted
//-----------------------------------------------------

bool CPU::IsHalted() const
{
    return m_Halted;
}

//-----------------------------------------------------
// GetSP
//-----------------------------------------------------

u16 CPU::GetSP() const
{
    return SP;
}

//-----------------------------------------------------
// GetSP
//-----------------------------------------------------

u16 CPU::GetPC() const
{
    return PC;
}

//-----------------------------------------------------
// GetFlags
//-----------------------------------------------------

u8 CPU::GetFlags() const
{
    return FLAGS;
}

//-----------------------------------------------------
// GetRegister
//-----------------------------------------------------

u8& CPU::GetRegister(u8 reg)
{
    switch (reg)
    {
        case 0x00: return A;
        case 0x01: return B;
        case 0x02: return C;
        case 0x03: return D;
    
        default:
        {
            printf("INVALID REGISTER %02X\n", reg);

            m_RegisterError = true;
            m_Halted = true;

            return A;
        }
    }
}

//-----------------------------------------------------
// HasStackOverflow
//-----------------------------------------------------

bool CPU::HasStackOverflow() const
{
    return m_StackOverflow;
}

//-----------------------------------------------------
// HasStackUnderflow
//-----------------------------------------------------

bool CPU::HasStackUnderflow() const
{
    return m_StackUnderflow;
}

//-----------------------------------------------------
// FetchByte
//-----------------------------------------------------

u8 CPU::FetchByte(Memory& memory)
{
    const u8 value = memory.Read8(PC);
    
    PC++;

    return value;
}

//-----------------------------------------------------
// Push8
//-----------------------------------------------------

void CPU::Push8(Memory& memory, u8 value)
{
    if (SP < STACK_BOTTOM)
    {
        printf("STACK OVERFLOW\n");

        m_StackOverflow = true;
        m_Halted = true;

        return;
    }

    memory.Write8(SP, value);
    SP--;
}

//-----------------------------------------------------
// Pop8
//-----------------------------------------------------

u8 CPU::Pop8(Memory& memory)
{
    if (SP >= STACK_TOP)
    {
        printf("STACK UNDERFLOW\n");

        m_StackUnderflow = true;
        m_Halted = true;

        return 0;
    }
    
    SP++;
    return memory.Read8(SP);
}

//-----------------------------------------------------
// Push16
//-----------------------------------------------------

void CPU::Push16(Memory& memory, u16 value)
{
    const u8 high = static_cast<u8>((value >> 8) & 0xFF);
    const u8 low = static_cast<u8>(value & 0xFF);

    Push8(memory, high);
    Push8(memory, low);
}

//-----------------------------------------------------
// Pop16
//-----------------------------------------------------

u16 CPU::Pop16(Memory& memory)
{
    const u8 low = Pop8(memory);
    const u8 high = Pop8(memory);

    return static_cast<u16>(low | (high << 8));
}

//-----------------------------------------------------
// DumpStack
//-----------------------------------------------------

void CPU::DumpStack(const Memory& memory, u16 count) const
{
    printf("\n========== STACK ==========\n");
    printf("SP = %04X\n\n", SP);

    u32 address = static_cast<u32>(SP + 1);

    for (u16 i = 0; i < count; i++)
    {
        if (address > STACK_TOP)
            break;

        printf("%04X : %02X", static_cast<u16>(address), memory.Read8(static_cast<u16>(address)));

        if (address == static_cast<u32>(SP + 1))
            printf(" <- TOP");

        printf("\n");
        address++;
    }
    printf("===========================\n");
}

//-----------------------------------------------------
// DumpRegisters
//-----------------------------------------------------

void CPU::DumpRegister() const
{
    printf("\n========== REGISTERS ==========\n");
    printf("A = %02X\n", A);
    printf("B = %02X\n", B);
    printf("C = %02X\n", C);
    printf("D = %02X\n", D);
    printf("PC = %04X\n", PC);
    printf("SP = %04X\n", SP);
    printf("FLAGS = %02X\n", FLAGS);
    printf("===============================\n");
}

//-----------------------------------------------------
// DumpMemory
//-----------------------------------------------------

void CPU::DumpMemory(const Memory& memory, u16 startAddress, u16 count) const
{
    printf("\n========== MEMORY ==========\n");

    for (u16 i = 0; i < count; i += 16)
    {
        const u16 address = startAddress + i;

        printf("%04X : ", address);

        for (u16 j = 0; j < 16; j++)
        {
            if ((i + j) >= count)
                break;

            printf("%02X ", memory.Read8(address + j));
        }
        printf("\n");
    }
    printf("============================\n");
}

//-----------------------------------------------------
// SetDebugEnabled
//-----------------------------------------------------

void CPU::SetDebugEnabled(bool enabled)
{
    m_DebugEnabled = enabled;
}

//-----------------------------------------------------
// IsDebugEnabled
//-----------------------------------------------------

bool CPU::IsDebugEnabled() const
{
    return m_DebugEnabled;
}

//-----------------------------------------------------
// Step
//-----------------------------------------------------

void CPU::Step(Memory& memory)
{
    const u8 opcode = FetchByte(memory);

    if (m_DebugEnabled)
        printf("PC=%04X SP=%04X FLAGS=%02X OPCODE=%02X\n", static_cast<u16>(PC - 1), SP, FLAGS, opcode);

    switch (opcode)
    {
        case OPCODE_NOP: ExecuteNOP(); break;
        case OPCODE_MOV: ExecuteMOV(memory); break;
        case OPCODE_LOAD: ExecuteLOAD(memory); break;
        case OPCODE_STORE: ExecuteSTORE(memory); break;

        case OPCODE_PUSH: ExecutePUSH(memory); break;
        case OPCODE_POP: ExecutePOP(memory); break;
        case OPCODE_CALL: ExecuteCALL(memory); break;
        case OPCODE_RET: ExecuteRET(memory); break;

        case OPCODE_INC: ExecuteINC(memory); break;
        case OPCODE_DEC: ExecuteDEC(memory); break;
        case OPCODE_ADD: ExecuteADD(memory); break;
        case OPCODE_SUB: ExecuteSUB(memory); break;
        case OPCODE_CMP: ExecuteCMP(memory); break;

        case OPCODE_JMP: ExecuteJMP(memory); break;
        case OPCODE_JZ: ExecuteJZ(memory); break;
        case OPCODE_JNZ: ExecuteJNZ(memory); break;
        
        case OPCODE_HLT: ExecuteHLT(); break;
        
        default: HandleUnknownOpcode(opcode); break;
    }
}
