#ifndef _PERLIN_H_
#define _PERLIN_H_

#include <math.h>
#include <stdlib.h>

#define FADE(t) (t * t * t * (t * (t * 6 - 15) + 10))
#define LERP(t, a, b) ((a) + (t) * ((b) - (a)))

#define S_NOISE_GEN 1013
#define X_NOISE_GEN 1619
#define Y_NOISE_GEN 31337
#define Z_NOISE_GEN 6971

inline int FASTFLOOR(float x) { return (((x) > 0) ? ((int)x) : ((int)x - 1)); }

float	perlin_grad2d(int hash, float x, float y);

extern unsigned char perlin_perm[512];

#endif /* _PERLIN_H_ */
