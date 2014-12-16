#include "Perlin.h"

static unsigned int perlin_seed = 1234;
unsigned char perlin_perm[512];

void	setSeed(unsigned int value)
{
  perlin_seed = value;
}

unsigned int	getSeed()
{
  return perlin_seed;
}

void	initPerm()
{
  unsigned int x = 0;

  while (x < 512)
    {
      perlin_perm[x] = (float)rand() / (float)RAND_MAX * 256.f;
      ++x;
    }
}
