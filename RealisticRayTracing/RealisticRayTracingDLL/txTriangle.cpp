#include "StdAfx.h"
#include <assert.h>
#include "txTriangle.h"
#include "Matrix3.h"
#include "Ray.h"
#include "HitRecord.h"

#define TRIANGLE_PRECISION_EPSILON 0.00001


txTriangle::txTriangle(void)
{
}

txTriangle::txTriangle(const txVec3d &v0_, const txVec3d &v1_, const txVec3d &v2_, const txRgb &color_)
	:v0(v0_)
	,v1(v1_)
	,v2(v2_)
	,color(color_)
{
	assert(IsValid());
	normal=TriPlaneNormal();
}

txTriangle::~txTriangle(void)
{
}
// Affine coordinates
// r.o + lambda*r.d = alpha*v0 + beta*v1 + (1-alpha-beta)v2
// alpha(v0-v2) + beta(v1-v2) - lambda*r.d = (r.o-v2)
bool txTriangle::Hit(const txRay& r, float tmin, float tmax, float time, 
	txHitRecord& record) const 
{
	txMatrix3 A((v0-v2),(v1-v2),-1.0*r.GetD());
	txVec3d rtn = A.SolveLinear3(r.GetO()-v2);
	double alpha = rtn.GetX();
	double beta = rtn.GetY();
	double lambda = rtn.GetZ();

	// TODO! check if it one the edge or on the triangle vertex
	if (  alpha>-TRIANGLE_PRECISION_EPSILON && alpha<1+TRIANGLE_PRECISION_EPSILON
		&&beta>-TRIANGLE_PRECISION_EPSILON&&beta<1+TRIANGLE_PRECISION_EPSILON){
			record.normal = normal;
			record.t = lambda;
			record.color = color;
			return true;
	}
	return false;
}

bool txTriangle::ShadowHit(const txRay& r, float tmin, float tmax, float time) const
{
	return false;
}

bool txTriangle::IsValid(){
	double area = ((v1-v0)%(v2-v0)).Length();

	if (area>TRIANGLE_PRECISION_EPSILON) return true;

	return false;
}

// CC v0->v1->v2
txVec3d txTriangle::TriPlaneNormal(){
	return ((v1-v0)%(v2-v0)).Normal();
}

