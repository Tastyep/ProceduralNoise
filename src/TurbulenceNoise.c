#include <math.h>
#include "libNoise.h"

float	turbulence_2d(int octaves, float lacunarity,
		      float gain, float scale,
		      float x, float y)
{
  float total = 0.f;
  float amplitude = 1.f;
  float	max = 0.f;

  for(int i = 0; i < octaves; ++i)
    {
      max += amplitude;
      total += fabs(raw_noise_2d(x * scale, y * scale)) * amplitude;
      scale *= lacunarity;
      amplitude *= gain;
    }
  return total / max;
}

float	turbulence_3d(int octaves, float lacunarity,
		      float gain, float scale,
		      float x, float y, float z)
{
  float total = 0.f;
  float amplitude = 1.f;
  float	max = 0.f;

  for(int i = 0; i < octaves; ++i)
    {
      max += amplitude;
      total += fabs(raw_noise_3d(x * scale, y * scale, z * scale)) * amplitude;
      scale *= lacunarity;
      amplitude *= gain;
    }
  return total / max;
}
