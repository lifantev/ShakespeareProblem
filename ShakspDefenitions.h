///ShakspDefenitions.h

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>

const char* NAME_OF_IN_FILE = "onegin_in.txt";

const char* NAME_OF_OUT_FILE = "onegin_out.txt";

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

FILE *openin(FILE *);

FILE *openout(FILE *);

FILE *closein(FILE *);

FILE *closeout(FILE *);

int compare(const void *, const void *);

int anti_compare(const void *, const void *);

int sizing(FILE *);

int countlines(char *);

void makelines(struct Lines *, char *);

void putoutS_t(struct Strings *, int, FILE *);

void makefreeS_t(Strings *, int);

void putout(char *ptr, FILE *out);

#include "Shakspfuncs.cpp"