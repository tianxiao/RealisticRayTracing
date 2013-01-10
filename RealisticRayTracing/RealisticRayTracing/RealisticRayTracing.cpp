// RealisticRayTracing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include "Vec3d.h"
#include "Ray.h"
#include "Shpere.h"
#include "txTriangle.h"

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

	txVec3d *pixels = new txVec3d[w*h];

	int c, r;
	txRay ray;
	ray.SetD(rayDir);
	for (int i=0; i<w*h; i++){
		r = i%w;
		c = i%h;
		ray.SetO(txVec3d(r,c,0.0));

	}


	delete pixels;
	return 0;
}

