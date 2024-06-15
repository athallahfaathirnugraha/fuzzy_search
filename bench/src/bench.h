#ifndef _BENCH_H_
#define _BENCH_H_

#include <stdio.h>
#include <time.h>
#include <float.h>

void bench(void (*func)(), int iter_num)
{
    float best = FLT_MAX;
    float worst = 0;
    float sum = 0;

    for (int i = 0; i < iter_num; i++) {
        float start = (float)clock() / CLOCKS_PER_SEC;
        (*func)();
        float end = (float)clock() / CLOCKS_PER_SEC;

        float dur = end - start;

        sum += dur;
        if (dur < best) best = dur;
        if (dur > worst) worst = dur;
    }

    printf("iter num:\t%d\n", iter_num);
    printf("best time:\t%f s\t(%f ms)\n", best, best * 1000);
    printf("average time:\t%f s\t(%f ms)\n", sum / iter_num, sum / iter_num * 1000);
    printf("worst time:\t%f s\t(%f ms)\n", worst, worst * 1000);
}

#endif