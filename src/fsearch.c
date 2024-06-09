#include <fsearch.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static int min(int a, int b)
{
    return a < b ? a : b;
}

static int lev_dist_(char *a, size_t a_len, char *b, size_t b_len)
{
    if (b_len == 0) return a_len;
    else if (a_len == 0) return b_len;

    if (a[0] == b[0]) return lev_dist_(&a[1], a_len - 1, &b[1], b_len - 1);

    return 1 + min(
        lev_dist_(&a[1], a_len - 1, b, b_len),
        min(
            lev_dist_(a, a_len, &b[1], b_len - 1),
            lev_dist_(&a[1], a_len - 1, &b[1], b_len - 1)
        )
    );
}

// https://en.wikipedia.org/wiki/Levenshtein_distance#Computing_Levenshtein_distance
int lev_dist(char *a, char *b)
{
    return lev_dist_(a, strlen(a), b, strlen(b));
}

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