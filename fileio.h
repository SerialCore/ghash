#define FER -1

long get_length(char* _file);
int read_binary(char* _file, unsigned char* _data, long _length);
int write_binary(char* _file, unsigned char* _data, long _length);