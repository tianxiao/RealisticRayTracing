#pragma once
#include "Shape.h"
#include "Vec3d.h"

class txTriangle :
	public txShape
{
public:
	txTriangle(void);
	explicit txTriangle(const txVec3d &v0_, const txVec3d &v1_, const txVec3d &v2_);

	~txTriangle(void);

	virtual bool Hit(const txRay& r, float tmin, float tmax, float time, 
		txHitRecord& record) const ;

	virtual bool ShadowHit(const txRay& r, float tmin, float tmax, float time) const;

private:
	txVec3d v0;
	txVec3d v1;
	txVec3d v2;
};

