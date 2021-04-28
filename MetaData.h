#ifndef METADATA_CODE
#define METADATA_CODE

#include <string>
// For Wav Files
typedef struct MetaData
{
    // Meta header
    char list_header[4]; // Contains LIST
    int meta_size;
    char info_header[4]; // Contains INFO

    // Sub Chunk 1
    char meta_sub1[4];
    int sub1_characters;
    char sub1_data[50];
} MetaData;

#endif // METADATA_CODE
