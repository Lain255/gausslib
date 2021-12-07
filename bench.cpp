#include <math.h>
#include <stdio.h>
#include <time.h>

#include <vector>
#include <chrono>

#define LOWER_BOUND 0
#define UPPER_BOUND 1000
#define NUM_STEPS 10000000
#define PI 3.14159265359

const float HALFPI = PI / 2;
const float HALFPIINVERSE = 2 / PI;
const float STEPLENGTH = (float) ((UPPER_BOUND - LOWER_BOUND)) / NUM_STEPS;

float aTanApprox(float x)
{
    const float a = -0.087;
    const float b = -0.125;
    const float c = 0.278;
    const float l = 1.014;

    if(x > l) {
        x = HALFPI - (x / (x * x + c));
    }

    else {
        x = x + (a * x * x) + (b * x * x * x);
    }

    return x;
}

float sinapprox(float x)
{
    const float a = 1.00274;
    const float b = -0.0294;
    const float c = -0.1305;

    int y = (int) (x / HALFPI);
    x -= (float)y * HALFPI;
    y %= 4;

    if ((y & 1) == 1) { x = HALFPI - x; }

    float i = (a * x) + (b * x * x) + (c * x * x * x);
    
    if((y & 2) == 2) { i = -i; }

    return i;
}

void generateVector(std::vector<float>& inputs, const long MIN, const long MAX, const long STEPS) {
    for (long i = 0; i < STEPS; i += 1) {
        // Sean: this is incorrect if MIN < 0000
        float x = ((float)(MAX - MIN) / (float)STEPS) * (float)i;
        inputs.push_back(x);
    }
}

#define BENCHMARK_FUNCTION(approx, stdlib) { \
    std::vector<float> inputs_approx; \
    generateVector(inputs_approx, LOWER_BOUND, UPPER_BOUND, NUM_STEPS); \
 \
    std::vector<float> inputs_stdlib; \
    generateVector(inputs_stdlib, LOWER_BOUND, UPPER_BOUND, NUM_STEPS); \
 \
    auto start_approx = std::chrono::high_resolution_clock::now(); \
    for(long i = 0; i < NUM_STEPS; i += 1) { \
        inputs_approx[i] = approx(inputs_approx[i]); \
    } \
    auto end_approx = std::chrono::high_resolution_clock::now(); \
 \
    auto start_stdlib = std::chrono::high_resolution_clock::now(); \
    for(long i = 0; i < NUM_STEPS; i += 1) { \
        inputs_stdlib[i] = stdlib(inputs_stdlib[i]); \
    } \
    auto end_stdlib = std::chrono::high_resolution_clock::now(); \
 \
    float max_error = 0.0f; \
    for(long i = 0; i < NUM_STEPS; i += 1) { \
        if(fabs(inputs_stdlib[i] - inputs_approx[i]) > 0.001) { \
            float x = fabs((inputs_stdlib[i] - inputs_approx[i]) / inputs_stdlib[i]); \
            if(x > max_error) { \
                max_error = x; \
            } \
        } \
    } \
 \
    auto span_approx = std::chrono::duration_cast<std::chrono::duration<double>>(end_approx - start_approx); \
    auto span_stdlib = std::chrono::duration_cast<std::chrono::duration<double>>(end_stdlib - start_stdlib); \
 \
    printf("%s time: %.2fms\n", #approx, 1000.0f * span_approx.count()); \
    printf("%s time: %.2fms\n", #stdlib, 1000.0f * span_stdlib.count()); \
    printf("Max error: %f%%\n\n", 100.0f * max_error); \
} \

int main()
{
    BENCHMARK_FUNCTION(aTanApprox, atanf);
    BENCHMARK_FUNCTION(sinapprox, sinf);
}
