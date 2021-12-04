#include <assert.h>
#include "gausslib.hpp"
#include <stdio.h>

int test_v3() {
    v3 a;
    a.x = 1.0f;
    a.y = 0.0f;
    a.z = 1.0f;

    if(a.x == 1.0f && a.y == 0.0f && a.z == 1.0f) {
        return 0;
    } else {
        return 1;
    }
}

int test_v3_cross_v3() {
    v3 a = {1,0,1};
    v3 b = {0,1,0};
    v3 c = v3_cross_v3(a,b);

    if (c.x == -1.0f && c.y == 0.0f && c.z == 1.0f)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

#define TEST(func) assert(func() == 0); printf("Passed: %s\n", #func);

int main() {
    TEST(test_v3);
    TEST(test_v3_cross_v3);
    
    return 0;
}