#ifndef __RAYTRACING_VEC3D__
#define __RAYTRACING_VEC3D__
//#pragma once
#include <assert.h>
class txVec3d
{
public:
	txVec3d(void);
	txVec3d(double x_, double y_, double z_);
	~txVec3d(void);

	txVec3d operator-(const txVec3d & l) const ;
	double operator*(const txVec3d & l) const ;
	txVec3d operator*(double a) const;

	friend txVec3d operator*(double a, const txVec3d &r);


private:
	double x, y, z;
};

inline txVec3d txVec3d::operator-(const txVec3d & l) const {
	return txVec3d(x-l.x,y-l.y,z-l.z);
}

inline double txVec3d::operator*(const txVec3d & l) const {
	return x*l.x + y*l.y + z*l.z;
}

inline txVec3d txVec3d::operator*(double a) const{
	return txVec3d(a*x, a*y, a*z);
}

inline txVec3d operator*(double a, const txVec3d &r){
	return txVec3d(a*r.x, a*r.y, a*r.z);
}

#endif