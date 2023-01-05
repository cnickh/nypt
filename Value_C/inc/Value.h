#ifndef VALUE_H
#define VALUE_H

#include "Page.h"
#include "Types.h"
#include <stdio.h> //printf

/*
Utility Functions
@defined in Util.c
*/
void destroy(Value val);

word shrink(uint len, word value);

char *hex(Value val);

char *_hex(word value, uint len);

uint byteOrder(byte b);

uint wordOrder(uint len, word a);

byte byteMask(uint size);

bool flip(bool sign);

uint shift_size(uint len, word a, uint magnitude, bool direction);

Value cleanZeros(Value a);


/*
Functions for creating values
@defined in Genesis.c
*/
Value emptyValue(uint len);

Value makeValue(word value, uint len, bool sign);

Value fromUlong(long long num);

Value cpy(Value a);

/*
Functions that operate on one or two words (byte arrays)
@defined in Bit.c
*/
Value neg(Value dest, bool inplace);

Value op(Value dest, Value src, char operand, bool inplace);

Value shift(Value dest, uint magnitude, bool direction, bool inplace);

bool isZero(Value a);

/*
Functions that operate on one or two words (byte arrays)
@defined in Value.c
*/
Value add(Value a, Value b, bool inplace);

Value sub(Value a, Value b, bool inplace);

bool max_cmp(Value a, Value b);

Value mlt(Value a, Value b, bool inplace);

Value dv(Value a, Value b);

Value pwr(Value a, Value b);

Value mod(Value a, Value b);

Value pwr_mod(Value a, Value b, Value c);

Value square(Value a);
//https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Binary_numeral_system_(base_2)

int square_int(int a);

/** TODO **/
//
// Value ds_lg(Value a, Value b, bool inplace);
//
// Value phi(Value a);
//
// Value gcd(Value a, Value b);
//
#endif
