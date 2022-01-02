#include <stdio.h>
#include <stdlib.h>
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

void create_table_group(char* _file, char _uniton)
{
    unsigned char _uniton_;
    char key[] = {'0', '1', '2', '3', '4', '5', '6', '7', 
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < 16; i++)
        if (key[i] == _uniton)
            _uniton_ = i;
    
    unsigned char table[TABL];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            table[16 * i + j] = (16 + i + j - _uniton_) % 16;
        }
    }

    print_table(table);
    write_binary(_file, table, TABL);
}

void create_table_sudoku(char* _file)
{
    unsigned char swap[16];
    for (int i = 0; i < 16; i++)
    {
        int exist = 1;
        while (exist)
        {
            exist = 0;
            swap[i] = (unsigned char)(rand() % 16);
            for (int j = 0; j < i; j++)
            {
                if (swap[j] == swap[i])
                {
                    exist = 1;
                    break;
                }
            }
        }
    }
    unsigned char table[TABL];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            table[16 * i + j] = (i + j) % 16;
        }
    }

    unsigned char temp[16];
    for (int i = 0; i < 8 ; i += 2)
    {
        for (int j = 0; j < 16; j++)
        {
            temp[j] = table[16 * swap[i] + j];
            table[16 * swap[i] + j] = table[16 * swap[i + 1] + j];
            table[16 * swap[i + 1] + j] = temp[j];
        }
    }
    for (int j = 8; j < 16 ; j += 2)
    {
        for (int i = 0; i < 16; i++)
        {
            temp[i] = table[16 * i + swap[j]];
            table[16 * i + swap[j]] = table[16 * i + swap[j + 1]];
            table[16 * i + swap[j + 1]] = temp[i];
        }
    }

    print_table(table);
    write_binary(_file, table, TABL);
}