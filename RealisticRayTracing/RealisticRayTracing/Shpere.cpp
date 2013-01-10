#include "StdAfx.h"
#include "Shpere.h"
#include "Ray.h"


txShpere::txShpere(void)
{
}

txShpere::txShpere(const txVec3d &o_, double radius_)
	:o(o_)
	,radius(radius_)
{}

txShpere::~txShpere(void)
{
}

 bool txShpere::Hit(const txRay& r, float tmin, float tmax, float time, 
	txHitRecord& record)  const
{
	double a = r.GetO()*r.GetO();
	double b = 2*r.GetD()*(r.GetD()-o);
	double c = (r.GetO()-o)*(r.GetO()-o);
	double delta = b*b - 4*a*c;

	return false;
}

 bool txShpere::ShadowHit(const txRay& r, float tmin, float tmax, float time) const
 {
	return false;
 }

