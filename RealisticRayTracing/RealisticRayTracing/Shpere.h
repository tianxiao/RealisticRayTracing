#pragma once
#include "shape.h"
#include "Vec3d.h"
#include "Rgb.h"

class txShpere :
	public txShape
{
public:
	txShpere(void);
	explicit txShpere(const txVec3d &o_, double radius_, txRgb &color_=txRgb(1.0,0.0,0.0));
	~txShpere(void);

	virtual bool Hit(const txRay& r, float tmin, float tmax, float time, 
		txHitRecord& record) const ;

	virtual bool ShadowHit(const txRay& r, float tmin, float tmax, float time) const;

	txVec3d &GetCenter() { return c; };
	double GetRadius() { return radius; };

private:
	txVec3d c;
	double radius;
	txRgb color;
};

