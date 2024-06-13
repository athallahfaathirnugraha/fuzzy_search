#include "bench.h"
#include <fsearch.h>

void func()
{
    char str[] = "consectetur";
    fsearch(str, "consectetur");
}

int main()
{
    bench(&func, 100);
    return 0;
}