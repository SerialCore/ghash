#include <stdio.h>
#include "table.h"
#include "fileio.h"

void print_table(char* _table);


void print_table(char* _table)
{
    for (int i = 0; i < TABL; i++)
    {
        printf(" %x", _table[i]);
        if (i % 16 == 15)
            printf("\n");
    }
}

void display_table(char* _file)
{
    unsigned char table[TABL];
    if (read_binary(_file, table, TABL))
        print_table(table);
}

void create_table_default(char* _file)
{
    unsigned char table[TABL];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            table[16 * i + j] = (i + j) % 16;
        }
    }

    print_table(table);
    write_binary(_file, table, TABL);
}

void create_table_sudoku(char* _file)
{
    unsigned char table[TABL];
    // code

    print_table(table);
    write_binary(_file, table, TABL);
}