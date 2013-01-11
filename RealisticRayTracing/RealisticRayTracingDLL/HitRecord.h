//#pragma once
#ifndef __RAYTRACING_HITRECORD__
#define __RAYTRACING_HITRECORD__
#include "import.h"
#include "Vec3d.h"
#include "Rgb.h"
class R_DECLDIR txHitRecord
{
public:
	txHitRecord(void);
	~txHitRecord(void);

	double t;
	txVec3d normal;
	txRgb color;
};

#endif


