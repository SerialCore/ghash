#include <stdio.h>
#include "table.h"

void print_table(char* _table);
int write_table(char* _file, unsigned char* _table);


int read_table(char* _file, unsigned char* _table)
{
    FILE* tf = NULL;
    tf = fopen(_file, "rb");
    if (tf != NULL)
    {
        int i = 0;
        while (fscanf(tf, "%c", &_table[i]) != EOF)
        {
            if (i == 255) break;
            i++;
        }

        fclose(tf);
        tf = NULL;
        return 1;
    }
    else
    {
        printf("fail to open file %s", _file);
        return 0;
    }
}

int write_table(char* _file, unsigned char* _table)
{
    FILE* tf = NULL;
    tf = fopen(_file, "wb");
    if (tf != NULL)
    {
        fwrite(_table, sizeof(unsigned char), 256, tf);
        fclose(tf);
        tf = NULL;
        return 1;
    }
    else
    {
        printf("fail to open file %s", _file);
        return 0;
    }
}

void print_table(char* _table)
{
    for (int i = 0; i < 256; i++)
    {
        printf(" %x", _table[i]);
        if (i % 16 == 15)
            printf("\n");
    }
}

void display_table(char* _file)
{
    unsigned char table[256];
    if (read_table(_file, table))
        print_table(table);
}

void create_table_default(char* _file)
{
    unsigned char table[256];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            table[16 * i + j] = (i + j) % 16;
        }
    }

    print_table(table);
    write_table(_file, table);
}

void create_table_sudoku(char* _file)
{
    unsigned char table[256];
    // code

    print_table(table);
    write_table(_file, table);
}