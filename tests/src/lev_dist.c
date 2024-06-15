#include <tap.h>
#include <fsearch.h>

int main()
{
    plan(10);
    cmp_ok(lev_dist("kitten", "sitting"), "==", 3);
    cmp_ok(lev_dist("uninformed", "uniformed"), "==", 1);
    cmp_ok(lev_dist("nformed", "formed"), "==", 1);
    cmp_ok(lev_dist("ed", "d"), "==", 1);
    cmp_ok(lev_dist("consectetur", "consectetur"), "==", 0);
    cmp_ok(lev_dist("approximate", "appromixate"), "==", 2);
    cmp_ok(lev_dist("approximate", "apprxoimate"), "==", 2);
    cmp_ok(lev_dist("oximate", "xoimate"), "==", 2);
    cmp_ok(lev_dist("ox", "xo"), "==", 2);
    cmp_ok(lev_dist("o", "x"), "==", 1);
    done_testing();
    return 0;
}