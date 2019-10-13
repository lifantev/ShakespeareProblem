///ShakspFuncs.h

FILE *openin(FILE *in)
{
    if ((in = fopen(NAME_OF_IN_FILE, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n",
                NAME_OF_IN_FILE);
        exit(EXIT_FAILURE);
    }
    return in;
}

FILE *openout(FILE *out)
{
    if ((out = fopen(NAME_OF_OUT_FILE, "w")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", NAME_OF_OUT_FILE);
        exit(EXIT_FAILURE);
    }
    return out;
}

FILE *closein(FILE *in)
{
    if (fclose(in))
    {
        printf("Cant't close the %s file", NAME_OF_IN_FILE);
        exit(EXIT_FAILURE);
    }
    return in;
}

FILE *closeout(FILE *out)
{
    if (fclose(out))
    {
        printf("Cant't close the %s file", NAME_OF_IN_FILE);
        exit(EXIT_FAILURE);
    }
    return out;
}

int countlines(char *BUF)
{
    int much_lines = 1;
    for (char *st = strchr(BUF, '\n'); st != NULL; st = strchr(st + 1, '\n'))
    {
        much_lines++;
    }
    return much_lines;
}

///getting the size of in_FILE
int sizing(FILE *in)
{
    fseek(in, 0L, SEEK_END);
    int FILE_SIZE = ftell(in);
    fseek(in, 0L, SEEK_SET);
    return FILE_SIZE;
}

///compare function
int compare(const void *str1, const void *str2)
{
    const struct Strings *String_t1 = (const struct Strings *)str1;
    const struct Strings *String_t2 = (const struct Strings *)str2;

    return strcmp(*(String_t1->strings_adresses), *(String_t2->strings_adresses));
}

///anti_compare function
int anti_compare(const void *str1, const void *str2)
{
    const struct Strings *String_t1 = (const struct Strings *)str1;
    const struct Strings *String_t2 = (const struct Strings *)str2;

    int minsize = 0;

    if ((String_t1->strings_length) >= (String_t2->strings_length))
        minsize = String_t2->strings_length;
    else
        minsize = String_t1->strings_length;

    if (strcmp(*String_t1->strings_adresses, *String_t2->strings_adresses) == 0)
        return 0;

    else
    {

        for (int way = 0; way < minsize; way++)
        {
            if (*(*String_t1->strings_adresses + String_t1->strings_length - 1 - way) == *(*String_t2->strings_adresses + String_t2->strings_length - 1 - way))
            {
                continue;
            }
            else if (*(*String_t1->strings_adresses + String_t1->strings_length - 1 - way) > *(*String_t2->strings_adresses + String_t2->strings_length - 1 - way))
            {
                return 1;
                break;
            }
            else if (*(*String_t1->strings_adresses + String_t1->strings_length - 1 - way) < *(*String_t2->strings_adresses + String_t2->strings_length - 1 - way))
            {
                return -1;
                break;
            }
        }
    }
}

///making pointers for strings in the text and solving their length
void makelines(struct Lines *Line_t, char *BUF)
{
    int much_lines = 0;
    Line_t[much_lines].lines_ptr = BUF;
    much_lines++;

    for (char *st = strchr(BUF, '\n'); st != NULL; st = strchr(st + 1, '\n'), much_lines++)
    {
        //
        Line_t[much_lines].lines_ptr = st + 1;
        much_lines--;
        //
        Line_t[much_lines].lines_lenght = st + 1 - Line_t[much_lines].lines_ptr;
        much_lines++;
        //
        *(st) = '\0';
    }
    Line_t[much_lines - 1].lines_lenght = strlen(Line_t[much_lines - 1].lines_ptr);
}

void putoutS_t(Strings *String_t, int much_lines, FILE *out)
{
    for (int j = 0; j <= much_lines - 1; j++)
    {
        fputs(*(String_t[j].strings_adresses), out);
        fputs("\n", out);
    }
}

void makefreeS_t(Strings *String_t, int much_lines)
{
    for (int j = 0; j <= much_lines - 1; j++)
    {
        String_t[j].strings_adresses = nullptr;
        String_t[j].strings_length = 0;
    }
}

void putout(char *ptr, FILE *out)
{
    fputs(ptr, out);
    fputs("\n", out);
    ///make pointers on strings null
    ptr = nullptr;
}