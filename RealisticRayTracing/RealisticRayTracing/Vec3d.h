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


private:
	double x, y, z;
};


inline txVec3d txVec3d::operator-(const txVec3d & l) const {
	return txVec3d(x-l.x,y-l.y,z-l.z);
}

inline double txVec3d::operator*(const txVec3d & l) const {
	return x*l.x + y*l.y + z*l.z;
}

#endif