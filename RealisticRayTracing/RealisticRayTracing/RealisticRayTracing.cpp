// RealisticRayTracing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include "Vec3d.h"
#include "Ray.h"
#include "Shpere.h"
#include "txTriangle.h"
#include "HitRecord.h"

inline double clamp(double x){return x<0?0:x>1?1:x;};
inline int toInt(double x){return int (pow(clamp(x),1/2.2)*255+0.5);};

int _tmain(int argc, _TCHAR* argv[])
{
	int w,h;
	w=h=512;

	txVec3d rayDir(0.0,0.0,-1.0);
	

	txShpere shpere(txVec3d(250.0,250.0,-1000.0),150.0);
	txVec3d v0(300.0,600.0,-800.0), v1(0.0,100.0,-1000.0), v2(450.0,20.0,-1000.0);
	txTriangle tri(v0,v1,v2);

	txRgb *pixels = new txRgb[w*h];
	for (int i=0; i<w*h; i++){
		pixels[i] = txRgb(); 
	}

	int c, r;
	txHitRecord record;
	txRay ray;
	ray.SetD(rayDir);
	for (int i=0; i<w*h; i++){
		r = i/w;
		c = i-r*w;
		ray.SetO(txVec3d(r,c,0.0));
		if ( shpere.Hit(ray,0.0,0.0,0.0,record)) {
			pixels[i] = record.color;
		}
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

