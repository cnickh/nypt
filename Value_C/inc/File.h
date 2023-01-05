#ifndef FILE_H
#define FILE_H

#include <stdio.h> //fopen, ... etc
#include "Types.h"

char BASE64[64] = {

'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'

};

FILE *open(char *char);

bool write_word(FILE *fp, word data);

bool write_value(FILE *fp, Value data);

bool write_string(FILE *fp, char *data);

bool seek(FILE *fp, uint loc);

bool close(FILE *fp);

#endif
