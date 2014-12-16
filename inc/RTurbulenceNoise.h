#ifndef _RTURBULENCENOISE_H_
#define _RTURBULENCENOISE_H_

#include "TurbulenceNoise.h"
#include "RMF_Noise.h"

float	tRidged_mf2(int octaves, float lacunarity,
		    float gain, float scale,
		    float offset,
		    int x, int y);

float	tRidged_mf3(int octaves, float lacunarity,
		    float gain, float scale,
		    float offset,
		    int x, int y, int z);


#endif /* _RTURBULENCENOISE_H_ */
