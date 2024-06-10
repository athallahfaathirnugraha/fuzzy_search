#include <tap.h>
#include <fsearch.h>

int main()
{
    plan(1);
    lives_ok({ fsearch("consectetur", "consectetur"); });
    done_testing();
    return 0;
}