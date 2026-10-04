/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

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

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
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
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


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

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return (1 << 31);
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return ~(~(x & ~y) & ~(~x & y));
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (x >> 31) & (~x +1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  return (0xFF&(x>>(src<<3)))<<(dst<<3)|(~(0xFF<<(dst<<3))&x);
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  return (x>>n) & ~(((1<<31)>>n<<1));
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int mask = (0x0F<<28) | (0x0F<<20) | (0x0F<<12) | (0x0F<<4);
  int a = mask&x;
  int mask_a = ~(0x0F<<28);
  int b = ~mask&x;
  return ((a>>4)&mask_a)|(b<<4);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int lowest_zero = ~x & (x + 1);
  int x2 = x | lowest_zero;
  return ~x2 & (x2 + 1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  x = x^(x>>16);
  x = x^(x>>8);
  x = x^(x>>4);
  x = x^(x>>2);
  x = x^(x>>1);
  x = x & 0x01;
  return !x;
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  n = n&31;
  int left = x<<((~n + 1) & 31);
  int mask_right = ~((~0)<<((~n + 1) & 31));
  int right = (x>>n) & mask_right;
  return left|right;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int pow2n = 1 << n; // 2^n
  int half = pow2n >> 1; // 2^(n-1)
  int mask = pow2n + ~0; // 2^n - 1
  int q = x >> n; // 原始商
  int r = x & mask; // 余数
  int q_rounded = (x + half) >> n; // 先加 half 再右移，常规四舍五入
  int special = !(r ^ half) & !(q & 0x01); // 恰好中点且商为偶数时需要调整
  q_rounded = q_rounded + (~special + 1);
  return q_rounded << n;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int is_sign_diff = ((x>>31) ^ (y>>31)) & 0x01;
  int is_x_bigger = ((!is_sign_diff) & ~((x + (~y+1))>>31)) | (is_sign_diff & (y>>31));
  int sum = x+y;
  int sign_x = x>>31 & 0x01;
  int has_overflowed = (!(sign_x^(y>>31 & 0x01))) & (sign_x^(sum>>31 & 0x01));
  int midpoint_raw = sum>>1;
  int midpoint = midpoint_raw^(has_overflowed<<31);
  int is_odd = sum & 0x01;
  return midpoint+(is_odd & is_x_bigger);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int is_sign_diff = ((x>>31) ^ (b>>31)) & 0x01;
  int eq = (!(a^x))|(!(b^x));
  int is_x_smaller_than_b = ((!is_sign_diff) & ((x + (~b+1))>>31)) | (is_sign_diff & (x>>31)); // 得到0或1
  is_sign_diff = ((a>>31) ^ (x>>31)) & 0x01;
  int is_a_smaller_than_x = ((!is_sign_diff) & ((a + (~x+1))>>31)) | (is_sign_diff & (a>>31));
  return (!eq & (!((is_a_smaller_than_x^is_x_smaller_than_b) & 0x01))) | eq;
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int t = 102; // 0x66
  t = (t << 8) | t; // 0x6666
  t = (t << 16) | t; // 0x66666666
  int int_min = 1 << 31;
  int C = t >> 2; // 0x19999999，正溢出阈值
  int T = t | int_min; // 0xE6666666，负溢出阈值

  int sign_x = x >> 31;

  int pos_cond = (x + ~C) >> 31; // x>C时为0，否则全1
  int pos_ovf = ~sign_x & ~pos_cond; // x>=0且x>C时全1，否则全0

  int neg_cond = (x + ~T) >> 31; // x>T时为0，否则全1
  int neg_ovf = sign_x & neg_cond; // x<0且x<=T时全1，否则全0

  int ovf = pos_ovf | neg_ovf; // 溢出掩码：全1表示溢出

  int sat = (sign_x & int_min) | (~sign_x & ~int_min);
  int mul5 = (x << 2) + x;

  return (mul5 & ~ovf) | (sat & ovf);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  // 低 32 位相加，并计算每一步的无符号进位
  int s1 = x + y;
  int c1 = (((x & y) | ((x | y) & ~s1)) >> 31) & 0x01; //两个数在某一位上都是1，或至少有一个1但和是0（说明这一位一定接收了来自低位的进位）
  int s2 = s1 + z;
  int c2 = (((s1 & z) | ((s1 | z) & ~s2)) >> 31) & 0x01;
  int carry = c1 + c2;

  int sign_low = s2 >> 31; // 低 32 位的符号扩展

  // 各数的高 32 位（符号扩展）
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int sign_z = z >> 31;

  // 高 32 位之和
  int sum_high = sign_x + sign_y + sign_z + carry;

  int eq = !(sum_high ^ sign_low);
  int neg_mask = (sum_high + (~sign_low + 1)) >> 31;
  int pos_mask = ~neg_mask & ~eq; 

  return neg_mask | (pos_mask & 0x01);
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  // 将浮点数的三个部分分离，便于后续运算和判断类型
  unsigned s = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  if (exp == 0xFF) return uf; // NaN或Inf
  if (exp == 0 && frac == 0) return uf; // ±0

  unsigned M;
  int E;
  if (exp == 0) { // 非规格化
    M = frac;
    E = -149; // 因为M用整数表示，相当于小数点向右移了23位，因此E要-23补齐
  } else { // 规格化
    M = (1 << 23) | frac;
    E = exp - 150;
  }
  
  M = M * 3;

  // 非规格化数：将M/2舍入到整数，需要考虑运算后超出非规格化范围的情况
  if (exp == 0) {
    unsigned M_new = M >> 1;
    if ((M & 1) && (M_new & 1)) // M的最低位（被舍掉的余数）和M/2的最低位都是1，说明刚好在一半且去尾舍入后商为奇数，应使结果+1
      M_new++;
    // 判断舍入后的M*3/2是否还是非规格化数
    if (M_new >= (1 << 23)) { // 如果M_new >= 2^23（即表示成浮点数时是1.… 不是0.…），说明结果已经进入了规格数范围
      // 此时值=M_new * 2^(-149)，表示成规格化数：frac部分（即M_new）去掉最高位1，exp=1但为了拼接应左移23位
      return s | (1 << 23) | (M_new & 0x7FFFFF);
    }
    return s | M_new; // 仍能用非规格化表示，阶码全0，直接拼接
  }

  // 规格化数：/2在可变的阶码上操作
  E = E - 1;
  int k;
  // 24位的M乘3后只可能是25或26位，即最高有效位下标k=24或25
  if (M >> 25) k = 25;
  else k = 24;
  int exp_new = k + E + 127; // 实际浮点数的小数点是在最高有效位后面的，但是这里把M当成了整数处理，恢复回去需要小数点左移k位，因此exp对应加上k以配平
  // 进行舍入
  unsigned M_new;
  if (k == 24) {
    M_new = M >> 1;
    if ((M & 1) && (M_new & 1)) M_new++;
  } else {
    M_new = M >> 2;
    unsigned last = M & 3;
    if (last > 2 || (last == 2 && (M_new & 1))) M_new++;
  }
  if (exp_new >= 255) return s | 0x7F800000; // 舍入后溢出为无穷
  return s | (exp_new << 23) | (M_new & 0x7FFFFF);
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned s = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  if (exp == 0xFF) return uf; // NaN或Inf
  if (exp == 0 && frac == 0) return uf; // ±0

  unsigned M;
  int E;
  if (exp == 0) {
    M = frac;
    E = -126;
  } else {
    M = (1 << 23) | frac;
    E = exp - 127;
  }

  if (E >= 23) return uf; // 已经是整数，直接返回

  if (E < 0) {
    if (E == -1) {
      // 值在[0.5, 1)之间
      if (M > (1 << 23)) return s | (127 << 23);  // 舍入到1.0（1.0的浮点表示是阶码为127，尾数为0）
    } else {
      return s; // <0.5，舍入到0
    }
  }

  int frac_bit = 23 - E;
  unsigned int_part = M >> frac_bit;
  unsigned frac_part = M & ((1 << frac_bit) - 1);
  unsigned half = 1 << (frac_bit - 1);

  if (frac_part > half) {
    int_part++;
  } else if (frac_part == half) {
    if (int_part & 1) int_part++; // 中点，舍入到偶数
  }

  if (int_part == 0) return s; // 舍入后为0直接返回

  // 整数转浮点
  int k = 31;
  while (!((int_part>>k) & 1)) k--;
  unsigned exp_new = k + 127;
  unsigned M_new = int_part << (23 - k); // 把整数有效位左移到bit23位置
  return s | (exp_new << 23) | (M_new & 0x7FFFFF);
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  if (x == 0) return 0;
  unsigned s = 0;
  if (x < 0) {
    s = 0x80000000;
    if (x == 0x80000000) { // INT_MIN，若取相反数用int范围会溢出，故需要特判
      return 0xCF000000; // -2^31的浮点数表示（1 10011110 00…00）
    }
    x = -x;
  }

  int k = 31;
  while (!(x>>k & 1)) k--;

  unsigned exp = k + 127;
  unsigned frac;
  if (k > 23) {
    int rshift = k - 23; // 需要将小数部分右移k-23位以填入23位尾数
    unsigned half = 1 << (rshift - 1);
    unsigned left_part = x & ((1 << rshift) - 1);
    // unsigned round_bit = (x >> (rshift - 1)) & 1; // 余数的最高位
    // unsigned sticky = (x & ((1u << (rshift - 1)) - 1)) != 0;
    frac = x >> rshift;
    if (left_part > half || (left_part == half && (frac & 1))) {
      frac++;
      if (frac >= (1 << 24)) { // frac++后可能产生进位，此时直接右移舍入（会产生进位则此时最后两位一定是00，直接去尾）
        frac = frac>>1;
        exp++;
      }
    }
  } else {
    frac = x << (23 - k); // 小数部分不足23位，直接填入对应位置
  }

  return s | (exp << 23) | (frac & 0x7FFFFF);
}

// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int m16 = 0xFF | (0xFF << 8); // 0x0000FFFF
  int m8 = 0xFF | (0xFF << 16); // 0x00FF00FF
  int m4 = m8 ^ (m8 << 4); // 0x0F0F0F0F
  int m2 = m4 ^ (m4 << 2); // 0x33333333
  int m1 = m2 ^ (m2 << 1); // 0x55555555

  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);
  x = (x & m8) + ((x >> 8) & m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
  int m16 = 0xFF | (0xFF << 8);
  int m8 = 0xFF | (0xFF << 16);
  int m4 = m8 ^ (m8 << 4);
  int m2 = m4 ^ (m4 << 2);
  int m1 = m2 ^ (m2 << 1);

  x = ((x & m1) << 1) | ((x >> 1) & m1);
  x = ((x & m2) << 2) | ((x >> 2) & m2);
  x = ((x & m4) << 4) | ((x >> 4) & m4);
  x = ((x & m8) << 8) | ((x >> 8) & m8);
  x = (x << 16) | ((x >> 16) & m16);
  return x;
}
