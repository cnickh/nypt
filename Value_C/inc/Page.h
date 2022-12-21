#ifndef PAGE_H
#define PAGE_H

#include "Types.h"
#include "Value.h"
#include <stdlib.h> //malloc
#include <stdio.h> //printf

uint get_space();

uint get_line_count();

int new_page();

void seek_page(int page);

void close();

void *draw(uint len);

bool check(line cur, uint len);

void erase(void *drawing);

void print_page();

void heal();

#endif
