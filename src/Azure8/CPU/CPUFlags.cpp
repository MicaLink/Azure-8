#include "../CPU.h"

//-----------------------------------------------------
// SetFlag
//-----------------------------------------------------

void CPU::SetFlag(u8 flag)
{
    FLAGS |= flag;
}

//-----------------------------------------------------
// ClearFlag
//-----------------------------------------------------

void CPU::ClearFlag(u8 flag)
{
    FLAGS &= ~flag;
}

//-----------------------------------------------------
// IsFlagSet
//-----------------------------------------------------

bool CPU::IsFlagSet(u8 flag) const
{
    return (FLAGS & flag) != 0;
}

//-----------------------------------------------------
// UpdateZeroFlag
//-----------------------------------------------------

void CPU::UpdateZeroFlag(u8 value)
{
    if (value == 0)
        SetFlag(FLAG_ZERO);
    else
        ClearFlag(FLAG_ZERO);
}

//-----------------------------------------------------
// UpdateCarryFlag
//-----------------------------------------------------

void CPU::UpdateCarryFlag(bool carry)
{
    if (carry)
        SetFlag(FLAG_CARRY);
    else
        ClearFlag(FLAG_CARRY);
}

//-----------------------------------------------------
// UpdateNegativeFlag
//-----------------------------------------------------

void CPU::UpdateNegativeFlag(u8 value)
{
    if ((value & 0x80) != 0)
        SetFlag(FLAG_NEGATIVE);
    else
        ClearFlag(FLAG_NEGATIVE);
}

//-----------------------------------------------------
// UpdateOverflowFlag
//-----------------------------------------------------

void CPU::UpdateOverflowFlag(bool overflow)
{
    if (overflow)
        SetFlag(FLAG_OVERFLOW);
    else
        ClearFlag(FLAG_OVERFLOW);
}