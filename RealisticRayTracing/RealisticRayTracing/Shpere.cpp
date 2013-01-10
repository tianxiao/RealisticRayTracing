#include "StdAfx.h"
#include <math.h>
#include "precition.h"
#include "Shpere.h"
#include "Ray.h"
#include "HitRecord.h"
#include "Rgb.h"


txShpere::txShpere(void)
{
}

txShpere::txShpere(const txVec3d &o_, double radius_, txRgb &color_)
	:c(o_)
	,radius(radius_)
	,color(color_)
{}

txShpere::~txShpere(void)
{
}

 bool txShpere::Hit(const txRay& r, float tmin, float tmax, float time, 
	txHitRecord& record)  const
{
	double a = r.GetD()*r.GetD();
	double b = 2*r.GetD()*(r.GetO()-c);
	double c = (r.GetO()-this->c)*(r.GetO()-this->c) - radius*radius;
	double delta = b*b - 4*a*c;

	double labda = 0.0;
	double labda1 = 0.0;
	txVec3d normal;
	if (delta>-txEpsilon && delta<txEpsilon) {
		// assert the if a<txEpsilon
		labda = (-b /*+ sqrt(delta)*/)/(2.0*a);
		// check if the labda is negative, opposite from the ray direction 
		if (-b<-txEpsilon) return false;

		record.t = labda;
		record.normal = this->c - (r.GetO() + labda*r.GetD());
		record.color = color;
		return true;
	} else if (delta<-txEpsilon){
		return false;
	} else {
		labda = (-b + sqrt(delta))/(2.0*a);
		labda1 = (-b - sqrt(delta))/(2.0*a);
		if (labda>labda1) labda = labda1;
		
		record.t = labda;
		record.normal = this->c - (r.GetO() + labda*r.GetD());
		//record.color = color;
		// set the color to linear with the distance
		// http://www.cnblogs.com/clever101/archive/2011/09/21/2184403.html
		// http://www.cnblogs.com/clever101
		// and see the doc folder to get the details about 
		// 
		//color.GetR();
		record.color.SetR(color.GetR()*(1000.0-labda)/150.0);
		return true;
	}

	
}

 bool txShpere::ShadowHit(const txRay& r, float tmin, float tmax, float time) const
 {
	return false;
 }

