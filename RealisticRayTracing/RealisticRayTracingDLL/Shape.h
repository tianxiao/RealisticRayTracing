#pragma once
#include "import.h"
class txRay;
class txHitRecord;
class R_DECLDIR txShape
{
public:
	txShape(void);
	~txShape(void);

	virtual bool Hit(const txRay& r, float tmin, float tmax, float time, 
		txHitRecord& record) const = 0;

	virtual bool ShadowHit(const txRay& r, float tmin, float tmax, float time) const = 0;
};

