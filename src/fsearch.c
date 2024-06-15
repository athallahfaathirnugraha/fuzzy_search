#include <fsearch.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static int max(int a, int b)
{
    return a > b ? a : b;
}

static int min(int a, int b)
{
    return a < b ? a : b;
}

static int lev_dist_(char *a, size_t a_len, char *b, size_t b_len)
{
    if (b_len == 0) return a_len;
    else if (a_len == 0) return b_len;

    if (a[0] == b[0]) return lev_dist_(&a[1], a_len - 1, &b[1], b_len - 1);

    int tat = lev_dist_(&a[1], a_len - 1, &b[1], b_len - 1);
    int atail;
    int btail;

    if (a[1] == b[0]) {
        if (a_len - 1 == b_len) atail = tat;
        else atail = 1 + tat;
    } else atail = 2 + tat;

    if (a[0] == b[1]) {
        if (a_len == b_len - 1) btail = tat;
        else btail = 1 + tat;
    } else btail = 2 + tat;

    return min(tat + 1, min(atail, btail));
}

// https://en.wikipedia.org/wiki/Levenshtein_distance#Computing_Levenshtein_distance
// basic operations: insertion, deletion, substitution
int lev_dist(char *a, char *b)
{
    return lev_dist_(a, strlen(a), b, strlen(b));
}

// do not pass const/static strings to str
// returns a size_t. the closer the return value, the closer the match
size_t fsearch(
    char *str,
    char *pat
) {
    size_t str_len = strlen(str);
    size_t min_dist = SIZE_MAX;
    
    for (size_t i = 0; i < str_len; i++) {
        for (size_t j = i; j < str_len; j++) {
            char prev_c = str[j + 1];
            str[j + 1] = '\0';
            int dist = lev_dist(&str[i], pat);
            if (dist < min_dist) min_dist = dist;
            str[j + 1] = prev_c;
        }
    }

    return min_dist;
}