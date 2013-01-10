#pragma once
#include "shape.h"
#include "Vec3d.h"

class txShpere :
	public txShape
{
public:
	txShpere(void);
	explicit txShpere(const txVec3d &o_, double radius_);
	~txShpere(void);

	virtual bool Hit(const txRay& r, float tmin, float tmax, float time, 
		txHitRecord& record) const ;

	virtual bool ShadowHit(const txRay& r, float tmin, float tmax, float time) const;

	txVec3d &GetCenter() { return o; };
	double GetRadius() { return radius; };

private:
	txVec3d o;
	double radius;
};

