#ifndef __RAYTRACING_VEC3D__
#define __RAYTRACING_VEC3D__
//#pragma once
#include <assert.h>
#include <math.h>
class txVec3d
{
public:
	txVec3d(void);
	txVec3d(double x_, double y_, double z_);
	~txVec3d(void);

	txVec3d Normal(){ return (*this)/(Length()); };
	double Length(){ return sqrt(SquareLength()); };
	double SquareLength(){ return x*x + y*y + z*z; };

	txVec3d operator+(const txVec3d & r) const;
	txVec3d operator-(const txVec3d & l) const ;
	double operator*(const txVec3d & l) const ;
	txVec3d operator*(double a) const;
	txVec3d operator/(double a) const;

	friend txVec3d operator*(double a, const txVec3d &r);

	void SetXYZ(double x_, double y_, double z_) { x=x_,y=y_,z=z_; };
	void SetX(double x_) { x=x_; };
	void SetY(double y_) { y=y_; };
	void SetZ(double z_) { z=z_; };
	
	double GetX() { return x; };
	double GetY() { return y; };
	double GetZ() { return z; };

private:
	double x, y, z;
};

inline txVec3d txVec3d::operator+(const txVec3d & r) const{
	return txVec3d(x+r.x, y+r.y, z+r.z);
}

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

inline txVec3d txVec3d::operator/(double a) const{
	return (*this)*(1.0/a);
}

#endif