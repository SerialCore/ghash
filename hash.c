#include <stdio.h>
#include "hash.h"
#include "table.h"
#include "fileio.h"

void hash_merge(unsigned char* _data, unsigned char* _table, long length);
void hash_cross(unsigned char* _data, unsigned char* _table, long length);


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

void prepare_hash(char* _file, char* _tfile, int _option)
{
    long length;
    if ((length = get_length(_file)) == FER)
        return;

    unsigned char data[length];
    unsigned char table[TABL];
    if (read_binary(_file, data, length) && read_binary(_tfile, table, TABL))
    {
        if (_option == MERGE)
        {
            hash_merge(data, table, length);
        }
        else if (_option == CROSS)
        {
            hash_cross(data, table, length);
        }
    }
}

void hash_merge(unsigned char* _data, unsigned char* _table, long _length)
{
    unsigned char left;
    unsigned char right;
    unsigned char product_h;
    unsigned char product_l;

    long data_count = 0;
    long data_length = _length;
    while (data_length > HASHL)
    {
        for (long i = 0, data_count = 0; i < data_length; i += 2, data_count++)
        {
            left = _data[i] >> 4;
            right = _data[i + 1] >> 4;
            product_h = _table[left * 16 + right];

            left = _data[i] & 0x0F;
            right = _data[i + 1] & 0x0F;
            product_l = _table[left * 16 + right];

            _data[data_count] = product_h << 4 | product_l;
        }
        data_length /= 2;
    }

    for (int i = 0; i < data_length; i++)
    {
        printf("%02X", _data[i]);
    }
    printf("\n");
}

void hash_cross(unsigned char* _data, unsigned char* _table, long _length)
{
    unsigned char left;
    unsigned char right;
    unsigned char product_h;
    unsigned char product_l;

    long data_count = 0;
    long data_length = _length;
    while (data_length > HASHL)
    {
        for (long i = 0, data_count = 0; i < data_length; i += 2, data_count++)
        {
            left = _data[i] >> 4;
            right = _data[i + 1] & 0x0F;
            product_h = _table[left * 16 + right];

            left = _data[i] & 0x0F;
            right = _data[i + 1] >> 4;
            product_l = _table[left * 16 + right];

            _data[data_count] = product_h << 4 | product_l;
        }
        data_length /= 2;
    }

    for (int i = 0; i < data_length; i++)
    {
        printf("%02X", _data[i]);
    }
    printf("\n");
}