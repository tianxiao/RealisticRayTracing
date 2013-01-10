//#pragma once
#ifndef __RAYTRACING_HITRECORD__
#define __RAYTRACING_HITRECORD__
#include "Vec3d.h"
#include "Rgb.h"
class txHitRecord
{
public:
	txHitRecord(void);
	~txHitRecord(void);

	float t;
	txVec3d normal;
	txRgb color;
};

#endif


