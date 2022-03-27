<!-- ee Table Register, optionally shifted by constant
<Operand2> See Table Flexible Operand 2. Shift and rotate are only available as part of Operand2. <reglist> A comma-separated list of registers, enclosed in braces { and }.
<fields> See Table PSR fields. <reglist-PC> As <reglist>, must not include the PC.
<PSR> Either CPSR (Current Processor Status Register) or SPSR (Saved Processor Status Register) <reglist+PC> As <reglist>, including the PC.
C*, V* Flag is unpredictable in Architecture v4 and earlier, unchanged in Architecture v5 and later. +/- + or –. (+ may be omitted.)
<Rs|sh> Can be Rs or an immediate shift value. The values allowed for each shift type are the same as those § See Table ARM architecture versions.
shown in Table Register, optionally shifted by constant. <iflags> Interrupt flags. One or more of a, i, f (abort, interrupt, fast interrupt).
x,y B meaning half-register [15:0], or T meaning [31:16]. <p_mode> See Table Processor Modes
<imm8m> ARM: a 32-bit constant, formed by right-rotating an 8-bit value by an even number of bits. SPm SP for the processor mode specified by <p_mode>
Thumb: a 32-bit constant, formed by left-shifting an 8-bit value by any number of bits, or a bit <lsb> Least significant bit of bitfield.
pattern of one of the forms 0xXYXYXYXY, 0x00XY00XY or 0xXY00XY00. <width> Width of bitfield. <width> + <lsb> must be <= 32.
<prefix> See Table Prefixes for Parallel instructions {X} RsX is Rs rotated 16 bits if X present. Otherwise, RsX is Rs.
{IA|IB|DA|DB} Increment After, Increment Before, Decrement After, or Decrement Before. {!} Updates base register after data transfer if ! present (pre-indexed).
IB and DA are not available in Thumb state. If omitted, defaults to IA. {S} Updates condition flags if S present.
<size> B, SB, H, or SH, meaning Byte, Signed Byte, Halfword, and Signed Halfword respectively. {T} User mode privilege if T present.
SB and SH are not available in STR instructions -->
