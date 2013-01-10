#include "StdAfx.h"
#include "txTriangle.h"


txTriangle::txTriangle(void)
{
}

txTriangle::txTriangle(const txVec3d &v0_, const txVec3d &v1_, const txVec3d &v2_)
	:v0(v0_)
	,v1(v1_)
	,v2(v2_)
{}

txTriangle::~txTriangle(void)
{
}

bool txTriangle::Hit(const txRay& r, float tmin, float tmax, float time, 
	txHitRecord& record) const 
{
	return false;
}

bool txTriangle::ShadowHit(const txRay& r, float tmin, float tmax, float time) const
{
	return false;
}

