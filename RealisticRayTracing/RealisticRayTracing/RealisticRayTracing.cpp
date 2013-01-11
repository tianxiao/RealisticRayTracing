// RealisticRayTracing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include "../RealisticRayTracingDLL/Vec3d.h"
#include "../RealisticRayTracingDLL/Ray.h"
#include "../RealisticRayTracingDLL/Shpere.h"
#include "../RealisticRayTracingDLL/txTriangle.h"
#include "../RealisticRayTracingDLL/HitRecord.h"
#include "../RealisticRayTracingDLL/txTriangle.h"

#define SCENE_INFINITE 100000

inline double clamp(double x){return x<0?0:x>1?1:x;};
inline int toInt(double x){return int (pow(clamp(x),1/2.2)*255+0.5);};

int _tmain(int argc, _TCHAR* argv[])
{
	int w,h;
	w=h=512;

	txVec3d rayDir(0.0,0.0,-1.0);
	

	txShpere shpere(txVec3d(250.0,250.0,-1000.0),150.0);

	txVec3d triV0(300.0,400.0,-800.0),triV1(0.0,100.0,-1000.0), triV2(450.0,20.0,-1000.0);
	txTriangle tri(triV0, triV1, triV2);

	txRgb *pixels = new txRgb[w*h];
	for (int i=0; i<w*h; i++){
		pixels[i] = txRgb(); 
	}

	int c, r;
	txHitRecord record;
	txHitRecord recordtri;
	txRay ray;
	ray.SetD(rayDir);
	txRgb temp(0.0,0.0,0.0);
	for (int i=0; i<w*h; i++){
		r = i/w;
		c = i-r*w;
		// z buffer check distance 
		double z=SCENE_INFINITE;
		ray.SetO(txVec3d(r,c,0.0));
		if ( shpere.Hit(ray,0.0,0.0,0.0,record)) {
			if (record.t<z) {
				z = record.t;
				temp = record.color;
			}
		}
		//if ( tri.Hit(ray,0.0,0.0,0.0,recordtri)){
		//	if (recordtri.t<z) {
		//		z = recordtri.t;
		//		temp = recordtri.color;
		//	}
		//}
		pixels[i] = temp;
	}

	FILE *f = fopen("..//results//image.ppm", "w");
	fprintf(f,"P3\n%d %d\n%d\n", w, h, 255);
	for (int i=0 ;i<w*h; i++) {
		fprintf(f,"%d %d %d ", toInt(pixels[i].GetR()), toInt(pixels[i].GetG()), toInt(pixels[i].GetB()));
	}
	fclose(f);

	delete[] pixels;
	return 0;
}

