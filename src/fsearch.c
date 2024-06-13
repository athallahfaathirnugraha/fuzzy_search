#include <fsearch.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static int min(int a, int b)
{
    return a < b ? a : b;
}

// https://en.wikipedia.org/wiki/Levenshtein_distance#Computing_Levenshtein_distance
// TODO: optimise (?)
int lev_dist(char *a, char *b)
{
    unsigned long a_len = strlen(a);
    unsigned long b_len = strlen(b);

    if (b_len == 0) return a_len;
    else if (a_len == 0) return b_len;

    if (a[0] == b[0]) return lev_dist(&a[1], &b[1]);

    return 1 + min(lev_dist(&a[1], b), min(lev_dist(a, &b[1]), lev_dist(&a[1], &b[1])));
}

// TODO: OPTIMISE!!!
// do not pass const/static strings to str
size_t fsearch(
    char *str,
    char *pat
) {
    size_t min_dist = SIZE_MAX;
    
    for (size_t i = 0; i < strlen(str); i++) {
        for (size_t j = i; j < strlen(str); j++) {
            char prev_c = str[j + 1];
            str[j + 1] = '\0';
            int dist = lev_dist(&str[i], pat);
            if (dist < min_dist) min_dist = dist;
            str[j + 1] = prev_c;
        }
    }

    return min_dist;
}