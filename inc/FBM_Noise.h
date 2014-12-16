#ifndef _FBM_NOISE_H_
#define _FBM_NOISE_H_

#include "SimplexNoise.h"

float fbm_2d(int octaves,
	     float lacunarity,
	     float gain,
	     float scale,
	     float x,
	     float y);

float fbm_3d(int octaves,
	     float lacunarity,
	     float gain,
	     float scale,
	     float x,
	     float y,
	     float z);

#endif /* _FBM_NOISE_H_ */
