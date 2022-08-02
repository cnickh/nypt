#ifndef PAGE_H
#define PAGE_H

#include "Types.h"
#include "Value.h"
#include <stdlib.h>
#include <stdio.h>


uint get_space();

uint get_line_count();

void new_page();

void close();

void *draw(uint len);

void erase(void *drawing);

void print_page();

void heal();

#endif
