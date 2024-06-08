#include <tap.h>
#include <fsearch.h>

int main()
{
    plan(2);
    cmp_ok(lev_dist("kitten", "sitting"), "==", 3);
    cmp_ok(lev_dist("uninformed", "uniformed"), "==", 1);
    done_testing();
    return 0;
}