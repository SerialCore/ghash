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
        if (!strcmp(argv[1], "-x"))
        {
            display_hex(argv[2]);
        }
        else if (!strcmp(argv[1], "-t"))
        {
            display_table(argv[2]);
        }
        else if (!strcmp(argv[1], "-td"))
        {
            create_table_default(argv[2]);
        }
        else if (!strcmp(argv[1], "-ts"))
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
            choose_algorithm(argv[2], argv[3], HASH);
        }
        else if (!strcmp(argv[1], "-c1"))
        {
            choose_algorithm(argv[2], argv[3], MERGE);
        }
        else if (!strcmp(argv[1], "-c2"))
        {
            choose_algorithm(argv[2], argv[3], CROSS);
        }
        else if (!strcmp(argv[1], "-tg"))
        {
            create_table_group(argv[3], argv[2][0]);
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
    printf("A hash algorithm built on 16th-order multiplication table\n");
    printf("\nUSAGE\n");
    printf("\tghash <command> [file] [tablefile]\n");
    printf("\nCOMMANDS\n");
    printf("\t-h\tget hash code\n");
    printf("\t-c1\tget compressed code with MERGE\n");
    printf("\t-c2\tget compressed code with CROSS\n");
    printf("\t-x\tdisplay hex code of a file\n");
    printf("\t-t\tdisplay a table\n");
    printf("\t-td\tcreate a default table\n");
    printf("\t-tg\tcreate a group table with identity element\n");
    printf("\t-ts\tcreate a sudoku-like table\n");
    printf("\nFLAGS\n");
    printf("\t--help\tdisplay this instruction\n");
    printf("\t--vers\tget the version of ghash\n");
    printf("\nEXAMPLES\n");
    printf("\t$ ghash -h file table\n");
    printf("\t$ ghash -x file\n");
    printf("\t$ ghash -t table\n");
    printf("\t$ ghash -td table_default\n");
    printf("\t$ ghash -tg A table_group_A\n");
}

void get_version()
{
    printf("ghash 0.1 by SerialCore\n");
}