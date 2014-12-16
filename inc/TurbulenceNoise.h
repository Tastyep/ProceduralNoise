#ifndef _TURBULENCE_NOISE_H_
#define _TURBULENCE_NOISE_H_

#include "SimplexNoise.h"

float	turbulence_2d(int octaves, float lacunarity,
		      float gain, float scale,
		      float x, float y);

float	turbulence_3d(int octaves, float lacunarity,
		      float gain, float scale,
		      float x, float y, float z);

#endif /* _TURBULENCE_NOISE_H_ */
