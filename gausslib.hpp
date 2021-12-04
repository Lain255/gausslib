#ifndef GAUSSLIB_H
#define GAUSSLIB_H

typedef union v3 {
    struct {
        float x;
        float y;
        float z;
    };
} v3;

float v3_dot_v3(v3 l, v3 r); //dot product between two vectors
v3 v3_cross_v3(v3 l, v3 r); //cross product between two vectors

#endif
