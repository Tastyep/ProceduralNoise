#include "libNoise.h"
#include "RMF_Noise.h"

float	ridge(float h, float offset)
{
  if (h < 0)
    h = -h;
  h = offset - h;
  h = h * h;
  return h;
}

float	ridged_mf2(int octaves, float lacunarity,
		   float gain, float scale,
		   float offset,
		   int x, int y)
{
  return ridge(0.3f + 0.5f * fbm_2d(octaves, lacunarity, gain, scale, x, y), offset);
}

float	ridged_mf3(int octaves, float lacunarity,
		   float gain, float scale,
		   float offset,
		   int x, int y, int z)
{
  return ridge(0.3f + 0.5f * fbm_3d(octaves, lacunarity, gain, scale, x, y, z), offset);
}
