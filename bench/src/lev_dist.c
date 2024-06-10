#include "bench.h"
#include <fsearch.h>

void func()
{
    lev_dist("consectetur", "consectetur");
}

int main()
{
    bench(&func, 100);
    return 0;
}