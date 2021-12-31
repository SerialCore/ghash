#include <stdio.h>
#include "table.h"
#include "fileio.h"

void print_table(unsigned char* _table);


void print_table(unsigned char* _table)
{
    printf("   R 0 1 2 3 4 5 6 7 8 9 A B C D E F\n");
    printf(" L   -------------------------------\n");
    for (int i = 0; i < TABL; i++)
    {
        if (i % 16 == 0)
            printf(" %X |", (unsigned char)(i / 16));
        printf(" %X", _table[i]);
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
            printf(" %02X", data[i]);
        }
        printf("\n");
    }
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