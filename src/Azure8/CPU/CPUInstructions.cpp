#include "../CPU.h"
#include "../Memory.h"

#include <cstdio>

//-------------------------------------------------
// Data Transfer
//-------------------------------------------------

void CPU::ExecuteMOV(Memory& memory)
{
    const u8 destination = FetchByte(memory);
    const u8 source = FetchByte(memory);

    GetRegister(destination) = GetRegister(source);
}

void CPU::ExecuteLOAD(Memory& memory)
{
    const u8 reg = FetchByte(memory);

    const u8 low = FetchByte(memory);
    const u8 high = FetchByte(memory);

    const u16 address = static_cast<u16>(low | (high << 8));

    GetRegister(reg) = memory.Read8(address);
}

void CPU::ExecuteSTORE(Memory& memory)
{
    const u8 reg = FetchByte(memory);

    const u8 low = FetchByte(memory);
    const u8 high = FetchByte(memory);

    const u16 address = static_cast<u16>(low | (high << 8));

    memory.Write8(address, GetRegister(reg));
}

//-------------------------------------------------
// Stack
//-------------------------------------------------

void CPU::ExecutePUSH(Memory& memory)
{
    const u8 reg = FetchByte(memory);

    Push8(memory, GetRegister(reg));
}

void CPU::ExecutePOP(Memory& memory)
{
    const u8 reg = FetchByte(memory);

    GetRegister(reg) = Pop8(memory);
}

void CPU::ExecuteCALL(Memory& memory)
{
    const u8 low = FetchByte(memory);
    const u8 high = FetchByte(memory);

    const u16 address = static_cast<u16>(low | (high << 8));

    Push16(memory, PC);

    PC = address;
}

void CPU::ExecuteRET(Memory& memory)
{
    PC = Pop16(memory);
}

//-------------------------------------------------
// Arithmetic
//-------------------------------------------------

void CPU::ExecuteINC(Memory& memory)
{
    const u8 reg = FetchByte(memory);

    u8& value = GetRegister(reg);

    const u8 oldValue = value;

    value++;

    UpdateZeroFlag(value);
    UpdateNegativeFlag(value);

    // Overflow signé : +127 -> -128
    UpdateOverflowFlag(oldValue == 0x7F);
}

void CPU::ExecuteDEC(Memory& memory)
{
    const u8 reg = FetchByte(memory);

    u8& value = GetRegister(reg);

    const u8 oldValue = value;

    value--;
            
    UpdateZeroFlag(value);
    UpdateNegativeFlag(value);

    // Overflow signé : -128 -> +127
    UpdateOverflowFlag(oldValue == 0x80);
}

void CPU::ExecuteADD(Memory& memory)
{
    const u8 dst = FetchByte(memory);
    const u8 src = FetchByte(memory);

    u8& destination = GetRegister(dst);

    const u8 source = GetRegister(src);
            
    const u16 result = static_cast<u16>(destination) + static_cast<u16>(source);

    UpdateCarryFlag(result > 0xFF);

    const u8 oldDst = destination;
    destination = static_cast<u8>(result);

    UpdateZeroFlag(destination);
    UpdateNegativeFlag(destination);

    // Overflow signé
    const bool overflow = (
        ((oldDst ^ source) & 0x80) == 0 &&
        ((oldDst ^ destination) & 0x80) != 0
    );

    UpdateOverflowFlag(overflow);
}

void CPU::ExecuteSUB(Memory& memory)
{
    const u8 dst = FetchByte(memory);
    const u8 src = FetchByte(memory);

    u8& destination = GetRegister(dst);

    const u8 source = GetRegister(src);

    const bool borrow = destination < source;

    const u8 oldDst = destination;
    const u8 result = static_cast<u8>(destination - source);

    UpdateCarryFlag(borrow);

    destination = result;

    UpdateZeroFlag(destination);
    UpdateNegativeFlag(destination);

    // Overflow signé
    const bool overflow =
    (
        ((oldDst ^ source) & 0x80) != 0 &&
        ((oldDst ^ destination) & 0x80) != 0
    );

    UpdateOverflowFlag(overflow);
}

void CPU::ExecuteCMP(Memory& memory)
{
    const u8 reg1 = FetchByte(memory);
    const u8 reg2 = FetchByte(memory);
    const u8 value1 = GetRegister(reg1);
    const u8 value2 = GetRegister(reg2);

    const bool borrow = value1 < value2;

    const u8 result = static_cast<u8>(value1 - value2);

    UpdateCarryFlag(borrow);
    UpdateZeroFlag(result);
    UpdateNegativeFlag(result);
}

//-------------------------------------------------
// Control Flow
//-------------------------------------------------

void CPU::ExecuteJMP(Memory& memory)
{
    const u8 low = FetchByte(memory);
    const u8 high = FetchByte(memory);

    const u16 address = static_cast<u16>(low | (high << 8));

    PC = address;
}

void CPU::ExecuteJZ(Memory& memory)
{
    const u8 low = FetchByte(memory);
    const u8 high = FetchByte(memory);

    const u16 address = static_cast<u16>(low | (high << 8));

    if (IsFlagSet(FLAG_ZERO))
    {
        PC = address;
    }
}

void CPU::ExecuteJNZ(Memory& memory)
{
    const u8 low = FetchByte(memory);
    const u8 high = FetchByte(memory);

    const u16 address = static_cast<u16>(low | (high << 8));

    if (!IsFlagSet(FLAG_ZERO))
    {
        PC = address;
    }
}

//-------------------------------------------------
// CPU Control
//-------------------------------------------------

void CPU::ExecuteNOP()
{

}

void CPU::ExecuteHLT()
{
    printf("CPU HALTED\n");
    m_Halted = true;
}

void CPU::HandleUnknownOpcode(u8 opcode)
{
    printf("UNKNOWN OPCODE %02X\n", opcode);
    m_Halted = true;
}