#pragma once
#include "import.h"
#include "Shape.h"
#include "Vec3d.h"
#include "Rgb.h"

class R_DECLDIR txTriangle :
	public txShape
{
public:
	txTriangle(void);
	explicit txTriangle(const txVec3d &v0_, const txVec3d &v1_, const txVec3d &v2_, const txRgb &color_=txRgb(0.0,1.0,0.0));

	~txTriangle(void);

	bool IsValid();
	// CC
	txVec3d TriPlaneNormal();
	virtual bool Hit(const txRay& r, float tmin, float tmax, float time, 
		txHitRecord& record) const ;

	virtual bool ShadowHit(const txRay& r, float tmin, float tmax, float time) const;

private:
	txVec3d v0;
	txVec3d v1;
	txVec3d v2;
	txVec3d normal;

	txRgb color;
};

