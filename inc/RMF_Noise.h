#ifndef _RMF_NOISE_H_
#define _RMF_NOISE_H_

#include "FBM_Noise.h"

float	ridge(float h, float offset);
float	ridged_mf2(int octaves, float lacunarity,
		   float gain, float scale,
		   float offset,
		   int x, int y);

float	ridged_mf3(int octaves, float lacunarity,
		   float gain, float scale,
		   float offset,
		   int x, int y, int z);


#endif /* _RMF_NOISE_H_ */
