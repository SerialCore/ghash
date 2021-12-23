#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "hash.h"

void get_help();
void get_version();


int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        if (!strcmp(argv[1], "--help"))
        {
            get_help();
        }
        else if (!strcmp(argv[1], "--vers"))
        {
            get_version();
        }
    }
    else if (argc == 3)
    {
        if (!strcmp(argv[1], "-dt"))
        {
            display_table(argv[2]);
        }
        else if (!strcmp(argv[1], "-cd"))
        {
            create_table_default(argv[2]);
        }
        else if (!strcmp(argv[1], "-cs"))
        {
            create_table_sudoku(argv[2]);
        }
        else
        {
            get_help();
        }
    }
    else if (argc == 4)
    {
        if (!strcmp(argv[1], "-h"))
        {
            prepare_hash(argv[2], argv[3]);
        }
    }
    else
    {
        get_help();
    }

    return 0;
}

void get_help()
{
    printf("A hash algorithm built on multiplication table of a 16th order group\n");
    printf("\nUSAGE\n");
    printf("\tghash <command> [file] [tablefile]\n");
    printf("\nCOMMANDS\n");
    printf("\t-h\tget hash code of the input file with table\n");
    printf("\t-dt\tdisplay a table\n");
    printf("\t-cd\tcreate a default table\n");
    printf("\t-cs\tcreate a sudoku-like table\n");
    printf("\nFLAGS\n");
    printf("\t--help\tdisplay this instruction\n");
    printf("\t--vers\tget the version of ghash\n");
    printf("\nEXAMPLES\n");
    printf("\t$ ghash -h input.file table_1\n");
    printf("\t$ ghash -cd table_default\n");
}

void get_version()
{
    printf("ghash 0.1 by SerialCore\n");
}