#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grep.h"
#include "term_colors.h"

void read_file(char *pattern, char *file, bool mFiles)
{
    FILE* fp;
    int bSize = 255;
    char buf[bSize];
    char *match = NULL;

    if((fp = fopen(file, "r")) != NULL) {
        while (fgets(buf, bSize, fp))
            if ((match = strstr(buf, pattern)) != NULL && strlen(buf) > 0)
                print_match(file, buf, match, pattern, mFiles);
        fclose(fp);
    } else {
        printf("Error: file %s does not exist or could not be opened.\n", file);
    }
}

void print_match(char *fn, char *buf, char *match, char *pattern, bool mFiles)
{
    int pos = match - buf;
    int len = strlen(pattern);
    
    if(mFiles) {
        printf(KCYN "%s:", fn);
    }
    for(int i = 0; i < strlen(buf); i++) {
        if(i >= pos && i <= (pos + len))
            printf(KGRN "%c", buf[i]);
        else
            printf(KWHT "%c", buf[i]);
    }
}

bool is_multiple_files(int argc)
{
    if(argc > 3)
        return true;
    return false;
}
