#ifndef GREP_H
#define GREP_H

typedef enum {false, true}bool;

void read_file(char *pattern, char *file, bool mFiles);
void print_match(char* fn, char *buf, char* match, char *pattern, bool mFiles);
bool is_multiple_files(int argc);

#endif
