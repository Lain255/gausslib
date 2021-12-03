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

#define TEST(func) assert(func() == 0); printf("Passed: %s\n", #func);

int main() {
    TEST(test_v3);
    
    return 0;
}
//test 1
