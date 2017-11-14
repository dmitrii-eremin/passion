#ifndef PASSION_INCLUDE_PASSION_H_
#define PASSION_INCLUDE_PASSION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Python.h>

#include <libpassion.h>

void read_whole_file(const char *filename, char *content, long maxlen);
long get_file_size(const char *filename);


#endif