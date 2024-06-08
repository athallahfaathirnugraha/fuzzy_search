#ifndef _FSEARCH_H_
#define _FSEARCH_H_

#include <stdlib.h>

int lev_dist(char *a, char *b);

// the lesser the return value, the closer the match
size_t fsearch(
    char *str,
    char *pat
);

#endif
