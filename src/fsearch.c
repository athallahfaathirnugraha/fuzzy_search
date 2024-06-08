#include <fsearch.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int min(int a, int b)
{
    return a < b ? a : b;
}

// https://en.wikipedia.org/wiki/Levenshtein_distance#Computing_Levenshtein_distance
int lev_dist(char *a, char *b)
{
    unsigned long a_len = strlen(a);
    unsigned long b_len = strlen(b);

    if (b_len == 0) return a_len;
    else if (a_len == 0) return b_len;

    if (a[0] == b[0]) return lev_dist(&a[1], &b[1]);

    return 1 + min(lev_dist(&a[1], b), min(lev_dist(a, &b[1]), lev_dist(&a[1], &b[1])));
}

void fsearch(size_t *out, size_t *out_len)
{
    printf("fsearch\n");
}