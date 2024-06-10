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

    printf("iter num: %d\n", iter_num);
    printf("best time: %f\n", best);
    printf("average time: %f\n", sum / iter_num);
    printf("worst time: %f\n", worst);
}

#endif