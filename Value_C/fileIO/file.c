#include "File.h"

FILE *open(char *char){

  return fopen(char,"w");

}

bool write_word(FILE *fp, word data){}

bool write_value(FILE *fp, Value data){}

bool write_string(FILE *fp, char *data){}

bool seek(FILE *fp, uint loc){

//int fseek( FILE *stream, long offset, int origin );


}

bool close(FILE *fp){

// int fclose( FILE *fp );


}


/*
#define SEEK_SET
#define SEEK_CUR
#define SEEK_END

w open /creates / seek to start
w+ also clears the file

int fputc( int c, FILE *fp );
int fputs( const char *s, FILE *fp );

char *fgets( char *buf, int n, FILE *fp );

size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
*/
