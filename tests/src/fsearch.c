#include <tap.h>
#include <fsearch.h>

int main()
{
    plan(1);

    lives_ok({
        char str[] = "consectetur";
        fsearch(str, "consectetur");
    });

    done_testing();
    return 0;
}