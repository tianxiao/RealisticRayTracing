#pragma once
#include "Vec3d.h"
class txRay
{
public:
	txRay(void);
	txRay(const txVec3d& o_, const txVec3d &d_);
	~txRay(void);

	void SetO(const txVec3d &o){ this->o = o;};
	void SetD(const txVec3d &d){ this->d = d;};
	const txVec3d &GetO()const { return o; };
	const txVec3d &GetD()const { return d; };

private:
	txVec3d o;
	txVec3d d;
};

