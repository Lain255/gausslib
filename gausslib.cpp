#include "gausslib.hpp"

float v3_dot_v3(v3 l, v3 r)
{
    return l.x*r.x + l.y*r.y + l.z*r.z;
}