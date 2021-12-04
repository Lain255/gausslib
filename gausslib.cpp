#include "gausslib.hpp"

float v3_dot_v3(v3 l, v3 r)
{
    return l.x*r.x + l.y*r.y + l.z*r.z;
}

v3 v3_cross_v3(v3 l, v3 r)
{
    return {l.y * r.z - l.z * r.y, l.z * r.x - l.x * r.z, l.x * r.y - l.y * r.x};
}