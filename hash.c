#include <stdio.h>
#include "hash.h"
#include "table.h"
#include "fileio.h"

void compress_merge(unsigned char* _data, unsigned char* _table, long _length);
void compress_cross(unsigned char* _data, unsigned char* _table, long _length);
void hash(unsigned char* _data, unsigned char* _table, long _length);


void choose_algorithm(char* _file, char* _tfile, int _option)
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
            compress_merge(data, table, length);
        }
        else if (_option == CROSS)
        {
            compress_cross(data, table, length);
        }
        else if (_option == HASH)
        {
            hash(data, table, length);
        }
    }
}

void compress_merge(unsigned char* _data, unsigned char* _table, long _length)
{
    unsigned char left;
    unsigned char right;
    unsigned char product_h;
    unsigned char product_l;

    long data_count = 0;
    long data_length = _length;
    while (data_length > HASHL)
    {
        for (long i = 0, data_count = 0; i < data_length; i += 2, data_count++) // deal with the count and length
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

void compress_cross(unsigned char* _data, unsigned char* _table, long _length)
{
    unsigned char left;
    unsigned char right;
    unsigned char product_h;
    unsigned char product_l;

    long data_count = 0;
    long data_length = _length;
    while (data_length > HASHL)
    {
        for (long i = 0, data_count = 0; i < data_length; i += 2, data_count++) // deal with the count and length
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

void hash(unsigned char* _data, unsigned char* _table, long _length)
{
    unsigned char left;
    unsigned char right;
    unsigned char aleft;
    unsigned char aright;

    unsigned char hash[HASHL];
    for (int i = 0; i < HASHL; i++)
        hash[i] = 0;

    for (long i = 0; i < _length; i += 2)
    {
        left = _data[i] >> 4;
        right = _data[i + 1] >> 4;
        aleft = _data[i] & 0x0F;
        aright = _data[i + 1] & 0x0F;

        hash[(int)((aleft + aright) * HASHL / 32)] += _table[left * 16 + right];
    }

    for (int i = 0; i < HASHL; i++)
    {
        printf("%02X", hash[i]);
    }
    printf("\n");
}