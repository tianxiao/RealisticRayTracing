#include "StdAfx.h"
#include "Ray.h"


txRay::txRay(void)
{
}

txRay::txRay(const txVec3d& o_, const txVec3d &d_)
	:o(o_)
	,d(d_)
{}

txRay::~txRay(void)
{
}
