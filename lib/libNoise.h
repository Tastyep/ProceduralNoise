#ifndef _LIBNOISE_H_
#define _LIBNOISE_H_

float		perlin2d(float x, float y);
void		setSeed(unsigned int value);
unsigned int	getSeed();

void		initPerm();

float	raw_noise_2d(float x,
		     float y);
float	raw_noise_3d(float x,
		     float y,
		     float z);
float	fbm_2d(int octaves,
	       float lacunarity,
	       float gain,
	       float scale,
	       float x,
	       float y);

float	fbm_3d(int octaves,
	       float lacunarity,
	       float gain,
	       float scale,
	       float x,
	       float y,
	       float z);
float	ridge(float h,
	      float offset);
float	ridged_mf2(int octaves,
		   float lacunarity,
		   float gain,
		   float scale,
		   float offset,
		   int x,
		   int y);
float	ridged_mf3(int octaves,
		   float lacunarity,
		   float gain,
		   float scale,
		   float offset,
		   int x,
		   int y,
		   int z);
float	tRidged_mf2(int octaves,
		    float lacunarity,
		    float gain,
		    float scale,
		    float offset,
		    int x,
		    int y);
float	tRidged_mf3(int octaves,
		    float lacunarity,
		    float gain,
		    float scale,
		    float offset,
		    int x,
		    int y,
		    int z);
float	turbulence_2d(int octaves,
		      float lacunarity,
		      float gain,
		      float scale,
		      float x,
		      float y);
float	turbulence_3d(int octaves,
		      float lacunarity,
		      float gain,
		      float scale,
		      float x,
		      float y,
		      float z);



#endif /* _LIB_H_ */
