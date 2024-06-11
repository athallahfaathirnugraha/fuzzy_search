#include "bench.h"
#include <fsearch.h>

void func()
{
    fsearch("consectetur", "consectetur");
}

int main()
{
    bench(&func, 100);
    return 0;
}