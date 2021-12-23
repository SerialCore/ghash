#include <stdio.h>
#include "hash.h"
#include "table.h"
#include "fileio.h"

void hash__merge(char* _data, char* _table, long length);


void display_hex(char* _file)
{
    long length;
    if ((length = get_length(_file)) == FER)
        return;

    unsigned char data[length];
    if (read_binary(_file, data, length))
    {
        for (long i = 0; i < length; i++)
        {
            printf(" %x", data[i]);
        }
        printf("\n");
    }
}

void prepare_hash(char* _file, char* _tfile, int option)
{
    long length;
    if ((length = get_length(_file)) == FER)
        return;

    unsigned char data[length];
    unsigned char table[TABL];
    if (read_binary(_file, data, length) && read_binary(_tfile, table, TABL))
    {
        if (option == MERGE)
        {
            hash__merge(data, table, length);
        }
    }
}

void hash__merge(char* _data, char* _table, long length)
{
    printf("%ld\n", length);
}