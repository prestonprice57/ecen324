/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Author:
*    Preston Price
* Summary:
*    Using bitwise manipulations to perform certain functions.
***********************************************************************/

/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID (Linux Lab username) if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member.
       Example: joestudent+zmename */
    "price57+kstone18", 
   /* Student name 1: Replace with the name of first team member */
   "Preston Price",
   /* Login ID 1: Replace with the login ID of first team member */
   "price57",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Name of the second team member */
   "Klenton Stone",
   /* Login ID 2: Login ID of the second team member */
   "kstone18"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.  
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x) & (~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  return (~((~x)&(~y)))&(~(x&y));

}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  return !!(x^y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int myShift;
  myShift = n << 3; 

  x = x >> myShift; 
  x = x & 0x0000FF; 

  return x;  
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  return ~(~(x << 31) >> 31);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int mask1; // create the mask 
  int result; 
  
  mask1 = 0x1 << 31; // shift the mask left 31 bits
  mask1 = mask1 >> n;        // shift right n times
  mask1 = ~(mask1 << 1);
  x = x >> n;         // shift x to align with mask 

  result = (x & mask1); 
  return result;  
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {

  /* Creates five different masks 
   * mask1 = 0101 0101
   * mask2 = 0011 0011
   * mask3 = 0000 1111
   * mask4 = 0000 0000 1111 1111
   * mask5 = 0000 0000 0000 0000 1111 1111 111 1111
   */
  int mask1; 
  int mask2; 
  int mask3; 
  int mask4; 
  int mask5; 

  int mask_piece; 
  int y; 
  int z; 

  mask_piece = ((0x55 << 8) + 0x55);
  mask1 = ((mask_piece << 16)) + mask_piece; 

  mask_piece = ((0x33 << 8) + 0x33); 
  mask2 = ((mask_piece << 16)) + mask_piece; 

  mask_piece = ((0x0F << 8) + 0x0F);
  mask3 = ((mask_piece << 16)) + mask_piece; 

  mask4 = ((0xFF << 16)) + 0xFF; 

  mask5 = ((0xFF << 8) + 0xFF);

/* Take two temp variables and set them to (x anded with the masks). 
 * Once before shifting and once after. This allows for the two to be 
 * added together. Once a number goes through the below masks and shifting
 * it will return the number of bits. 
 */
  y = x & mask1;
  x = x >> 1; 
  z = x & mask1; 
  x = y + z; 

  y = x & mask2; 
  x = x >> 2; 
  z = x & mask2; 
  x = y + z; 

  y = x & mask3; 
  x = x >> 4; 
  z =  x & mask3; 
  x = y + z; 

  y = x & mask4; 
  x = x >> 8; 
  z =  x & mask4; 
  x = y + z; 

  y = x & mask5; 
  x = x >> 16; 
  z =  x & mask5; 
  x = y + z; 

  return x; 
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {

  int x_inverted; 
  int x_add_one = 0;
  int invert_result = 0;  

  x_inverted = ~x;
  x_add_one = x_inverted + 1;

  invert_result = ((~x_add_one & x_inverted) >> 31);

    return (invert_result & 1);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
  /* By  taking two complement of x we can then use it to 
   * give us the leastBitPos. i.e. 0101, flip the bits and 1
   * this will give us 1011, we then (and) the original value(x) by 
   * the two's complement of x. */
  int y = 0; 
  y = (~x + 1);
  return x & y;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~ (1 << 31); 
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  return !(x >> 31)&1; 
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int negXor = (~(x ^ y));
  int subt = (y + (~x + 1));
  int greaterThan = (y & (x ^ y));  

  return !!(((negXor & subt) | greaterThan) >> 31);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int val_is_neg; 
  int ifNeg; 
  int ifPos; 
  
  val_is_neg = x >> 31; 

  ifNeg = val_is_neg & (x + (1 << n) + ~0) >> n;
  ifPos = (~val_is_neg & x) >> n;

    return ifNeg + ifPos; 
}
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  /* First check if x is neg, then if so convert to positive 
   * if already positive return the orginal
   */

   int isNegValue;
   int value; 

   isNegValue = x >> 31; 
  
   value = ((x & ~isNegValue) + (isNegValue & (~x + 1)));
   return value;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {

  int a = x >> 31; 
  int b = y >> 31; 
  
  int xaddy = x + y;
  int Xor; 
  xaddy = xaddy >> 31; 
  Xor = !!(a ^ b);


  return (Xor | (!(b ^ xaddy) & !(a ^ xaddy)));

  //return !!(~(y & x));

}
