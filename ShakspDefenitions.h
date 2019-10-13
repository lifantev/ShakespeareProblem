///ShakspDefenitions.h

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>

///names of input and output files
const char* NAME_OF_OUT_FILE = "shorthamletout.txt";

const char* NAME_OF_IN_FILE = "hamletshort.txt";

///creating a data structure of pointers on strings and their lengths
struct Lines
{
	char *lines_ptr;
	int lines_lenght;
};
struct Lines *Line_t = nullptr;

///creating a data structure of pointer adresses on strings and lengths of strings
struct Strings
{
	char **strings_adresses;
	int strings_length;
};
struct Strings *String_t = nullptr;

///opens input file
FILE *openin(FILE *);

///opens out file
FILE *openout(FILE *);

///closes input file
FILE *closein(FILE *);

///closes output file
FILE *closeout(FILE *);

///compares strings
int compare(const void *, const void *);

///compares strings from another side
int anti_compare(const void *, const void *);

///gets the size of text file
int sizing(FILE *);

///counts number of strings in text file
int countlines(char *);

///creates data of strings from in file
void makelines(struct Lines *, char *);

///puts strings from addresses on them 
void putoutS_t(struct Strings *, int, FILE *);

///cleans data of adresses
void makefreeS_t(Strings *, int);

///puts strings from the text in tje out file
void putout(char *ptr, FILE *out);