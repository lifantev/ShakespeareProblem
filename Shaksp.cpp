///Shaksp.cpp

#include "ShakspDefenitions.h"

int main(void)
{
	FILE *in, *out;

	///openning input and output files
	in = openin(in);
	out = openout(out);

	///getting the size of input file
	int FILE_SIZE = sizing(in);

	///creating a buffer for text
	char *BUF = (char *)calloc(FILE_SIZE / sizeof(char) + 1, sizeof(char));
	if (BUF == nullptr)
	{
		exit(EXIT_FAILURE);
		puts("Can't create a buffer to read the file\n");
	}

	///reading text into a buffer
	fread(BUF, sizeof(char), (FILE_SIZE / sizeof(char)), in);
	BUF[FILE_SIZE / sizeof(char)] = '\n';

	///closing input file
	in = closein(in);

	///puting text into the output file
	fwrite(BUF, sizeof(char), FILE_SIZE / sizeof(char), out);
	fputs("\n", out);

	///counting strings in th text
	int much_lines = countlines(BUF);
	const int how_much_lines = (const int)much_lines;

	///creating data of pointers on strings in the text
	Lines Line_t[how_much_lines] = {};
	if (Line_t == nullptr)
	{
		exit(EXIT_FAILURE);
		puts("memory error in creating separate lines\n");
	}

	///making pointers for strings in the text and solving their length
	makelines(Line_t, BUF);

	///creating data of addresses of pointers on strings
	Strings String_t[how_much_lines] = {};
	if (String_t == nullptr)
	{
		exit(EXIT_FAILURE);
		puts("memory error in creating separate lines\n");
	}
	makefreeS_t(String_t, much_lines);

	///making that adresses
	for (int i = 0; i <= much_lines; i++)
	{
		String_t[i].strings_adresses = &(Line_t[i].lines_ptr);
		String_t[i].strings_length = Line_t[i].lines_lenght;
	}

	///sorting
	qsort(String_t, much_lines, sizeof(String_t[0]), compare);

	///putting sorted strings in out_FILE
	putoutS_t(String_t, much_lines, out);

	///another sorting
	qsort(String_t, much_lines, sizeof(String_t[0]), anti_compare);

	///putting another sorted strings in out_FILE
	putoutS_t(String_t, much_lines, out);
	fputs("\n", out);
	makefreeS_t(String_t, much_lines);

	///putting standart strings in out_FILE
	for (int j = 0; j <= much_lines - 1; j++)
	{
		putout(Line_t[j].lines_ptr, out);
	}

	///closing out_FILE
	out = closeout(out);

	///make buffer free
	free(BUF);
	return 0;
}
