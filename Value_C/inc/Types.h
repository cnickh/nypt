#ifndef TYPES_H
#define TYPES_H

//Useful literals
#define P 'P'
#define N 'N'
#define Y 'Y'

//Comparison Result
#define A 'A'
#define B 'B'
#define E 'E'

//Bitwise word operands
#define AND 'A'
#define XOR 'X'
#define OR 'O'

//Bitwise shift directions
#define R 'R'
#define L 'L'

#define BYTE_SIZE 8

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned char bool;
typedef byte *word;

typedef struct Value_t{

  uint len;
  bool sign;
  word value;

} Value;

//Types for memory management
#define BOOK_SIZE 64
#define PAGE_SIZE 1024

typedef struct line_t {

  struct line_t *next;
  word this;
  bool used;
  uint len;

} *line;

#define LINE_SIZE sizeof(struct line_t)


typedef struct page_t {

  line head;
  uint space;

} *page;





#endif
