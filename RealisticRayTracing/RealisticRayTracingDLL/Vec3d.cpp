#include "StdAfx.h"
#include "Vec3d.h"


txVec3d::txVec3d(void)
{
}

txVec3d::txVec3d(double x_, double y_, double z_)
	:x(x_)
	,y(y_)
	,z(z_)
{}

txVec3d::~txVec3d(void)
{
}

// cross product
// http://mathworld.wolfram.com/CrossProduct.html
txVec3d txVec3d::operator%(const txVec3d &r) const{
	return txVec3d(y*r.z-z*r.y,z*r.x-x*r.z,x*r.y-y*r.x);
}
