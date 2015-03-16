#include "SimplexNoise.h"

float	raw_noise_2d(float x, float y)
{
  float n0, n1, n2;
  float s = (x + y) * F2;
  int i = FASTFLOOR(x + s);
  int j = FASTFLOOR(y + s);

  float t = (i + j) * G2;
  float X0 = i - t;
  float Y0 = j - t;
  float x0 = x - X0;
  float y0 = y - Y0;

  unsigned int i1, j1;
  if (x0 > y0)
    {
      i1 = 1;
      j1 = 0;
    }
  else
    {
      i1 = 0;
      j1 = 1;
    }

  float x1 = x0 - i1 + G2;
  float y1 = y0 - j1 + G2;
  float x2 = x0 - GX2;
  float y2 = y0 - GX2;

  unsigned int ii = i & 255;
  unsigned int jj = j & 255;

  float t0 = 0.5f - x0*x0-y0*y0;
  if (t0 < 0)
    n0 = 0.f;
  else
    {
      t0 *= t0;
      n0 = t0 * t0 * dot2(grad3[perlin_perm[ii+perlin_perm[jj]] & 0xF], x0, y0);
    }

  float t1 = 0.5f - x1*x1-y1*y1;
  if (t1 < 0)
    n1 = 0.f;
  else
    {
      t1 *= t1;
      n1 = t1 * t1 * dot2(grad3[perlin_perm[ii+i1+perlin_perm[jj+j1]] & 0xF], x1, y1);
    }

  float t2 = 0.5f - x2*x2-y2*y2;
  if (t2 < 0)
    n2 = 0.f;
  else
    {
      t2 *= t2;
      n2 = t2 * t2 * dot2(grad3[perlin_perm[ii+1+perlin_perm[jj+1]] & 0xF], x2, y2);
    }
  return 70.f * (n0 + n1 + n2);
}

float	raw_noise_3d(float x, float y, float z)
{
  float n0, n1, n2, n3;
  float s = (x + y + z) * F3;
  int i = FASTFLOOR(x + s);
  int j = FASTFLOOR(y + s);
  int k = FASTFLOOR(z + s);

  float t = (i + j + k) * G3;
  float X0 = i - t;
  float Y0 = j - t;
  float Z0 = k - t;
  float x0 = x - X0;
  float y0 = y - Y0;
  float z0 = z - Z0;
  unsigned int i1, j1, k1;
  unsigned int i2, j2, k2;

  if (x0 >= y0)
    {
      if (y0 >= z0)
	{
	  i1 = i2 = j2 = 1;
	  j1 = k1 = k2 = 0;
	}
      else if (x0 >= z0)
	{
	  i1 = i2 = k2 = 1;
	  j1 = k1 = j2 = 0;
	}
      else
	{
	  k1 = i2 = k2 = 1;
	  i1 = j1 = j2 = 0;
	}
    }
  else
    {
      if (y0 < z0)
	{
	  k1 = j2 = k2 = 1;
	  i1 = j1 = i2 = 0;
	}
      else if (x0 < z0)
	{
	  j1 = j2 = k2 = 1;
	  i1 = k1 = i2 = 0;
	}
      else
	{
	  j1 = i2 = j2 = 1;
	  i1 = k1 = k2 = 0;
	}
    }

  float x1 = x0 - i1 + G3;
  float y1 = y0 - j1 + G3;
  float z1 = z0 - k1 + G3;
  float x2 = x0 - i2 + F3;
  float y2 = y0 - j2 + F3;
  float z2 = z0 - k2 + F3;
  float x3 = x0 - E3;
  float y3 = y0 - E3;
  float z3 = z0 - E3;

  int ii = i & 255;
  int jj = j & 255;
  int kk = k & 255;
  int gi0 = perlin_perm[ii+perlin_perm[jj+perlin_perm[kk]]] & 0xF;
  int gi1 = perlin_perm[ii+i1+perlin_perm[jj+j1+perlin_perm[kk+k1]]] & 0xF;
  int gi2 = perlin_perm[ii+i2+perlin_perm[jj+j2+perlin_perm[kk+k2]]] & 0xF;
  int gi3 = perlin_perm[ii+1+perlin_perm[jj+1+perlin_perm[kk+1]]] & 0xF;

  float t0 = 0.6f - x0*x0 - y0*y0 - z0*z0;
  if (t0 < 0)
    n0 = 0.f;
  else
    {
      t0 *= t0;
      n0 = t0 * t0 * dot3(grad3[gi0], x0, y0, z0) * -1;
    }

  float t1 = 0.6f - x1*x1 - y1*y1 - z1*z1;
  if (t1 < 0)
    n1 = 0.f;
  else
    {
      t1 *= t1;
      n1 = t1 * t1 * dot3(grad3[gi1], x1, y1, z1) * -1;
    }

  float t2 = 0.6f - x2*x2 - y2*y2 - z2*z2;
  if (t2 < 0)
    n2 = 0.f;
  else
    {
      t2 *= t2;
      n2 = t2 * t2 * dot3(grad3[gi2], x2, y2, z2) * -1;
    }

  float t3 = 0.6f - x3*x3 - y3*y3 - z3*z3;
  if (t3 < 0)
    n3 = 0.f;
  else
    {
      t3 *= t3;
      n3 = t3 * t3 * dot3(grad3[gi3], x3, y3, z3) * -1;
    }
  return 32.f * (n0 + n1 + n2 + n3);
}
