#include <stdio.h>
#include "grep.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
        return printf("Please provide a file to grep\n");

    for(int i = 2; i < argc; i++)
        read_file(argv[1], argv[i], is_multiple_files(argc));
}


