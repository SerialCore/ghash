#include <stdio.h>
#include "fileio.h"


long get_length(char* _file)
{
    FILE* f = NULL;
    f = fopen(_file, "rb");

    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        long length = ftell(f);

        fclose(f);
        f = NULL;
        return length;
    }
    else
    {
        printf("fail to open %s\n", _file);
        return FER;
    }
}

int read_binary(char* _file, char* _data, long length)
{
    FILE* f = NULL;
    f = fopen(_file, "rb");

    if (f != NULL)
    {
        //long i = 0;
        //while (fscanf(f, "%c", &_data[i]) != EOF)
        //{
        //    if (i == length - 1) break;
        //    i++;
        //}

        fread(_data, sizeof(char), length, f);
        fclose(f);
        f = NULL;
        return 1;
    }
    else
    {
        printf("fail to open %s\n", _file);
        return 0;
    }
}

int write_binary(char* _file, char* _data, long length)
{
    FILE* f = NULL;
    f = fopen(_file, "wb");

    if (f != NULL)
    {
        fwrite(_data, sizeof(char), length, f);
        fclose(f);
        f = NULL;
        return 1;
    }
    else
    {
        printf("fail to open %s\n", _file);
        return 0;
    }
}

int write_string(char* _file, char* _string)
{
    FILE* f = NULL;
    f = fopen(_file, "w");

    if (f != NULL)
    {
        //fprintf(f, "%s", _string);
        fputs(_string, f);
        fclose(f);
        f = NULL;
        return 1;
    }
    else
    {
        printf("fail to open %s\n", _file);
        return 0;
    }
}