#include <math.h>
#include <stdio.h>
#include <time.h>

#define LOWERBOUND 0
#define UPPERBOUND 100000
#define NUMSTEPS 100000000
#define PI 3.14159265359

const float HALFPI = PI / 2;
const float HALFPIINVERSE = 2 / PI;
const float STEPLENGTH = (float) ((UPPERBOUND - LOWERBOUND)) / NUMSTEPS;


float approxTan(float x)
{
    return HALFPI - HALFPI/(x+1);
}


int main()
{
    clock_t t0;
    clock_t t1;
    clock_t dt;
    float max;



    max = 0;
    t0 = clock();
    for (int i = 0; i < NUMSTEPS; i++)
    {
        float y = atanf(LOWERBOUND + STEPLENGTH * i);
        max = y > max ? y : max;
    }
    t1 = clock();
    dt = t1 - t0;
    printf("standard secs: %f\n", (float) dt / CLOCKS_PER_SEC);
    printf("standard max: %f\n", max);



    max = 0;
    t0 = clock();
    for (int i = 0; i < NUMSTEPS; i++)
    {
        float y = approxTan(LOWERBOUND + STEPLENGTH * i);
        max = y > max ? y : max;
    }
    t1 = clock();
    dt = t1 - t0;
    printf("approx secs: %f\n", (float)dt / CLOCKS_PER_SEC);
    printf("approx max: %f\n", max);


    max = 0;
    for (int i = 0; i < NUMSTEPS; i++)
    {
        float x = LOWERBOUND + STEPLENGTH *i;
        float error = fabsf((atanf(x) - approxTan(x)) / atanf(x));
        max = error > max ? error : max;
    }

    printf("max error: %f %%\n", max*100);

    return 0;
}