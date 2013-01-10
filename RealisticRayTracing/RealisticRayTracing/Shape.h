#pragma once
class txRay;
class txHitRecord;
class txShape
{
public:
	txShape(void);
	~txShape(void);

	virtual bool Hit(const txRay& r, float tmin, float tmax, float time, 
		txHitRecord& record) const = 0;

	virtual bool ShadowHit(const txRay& r, float tmin, float tmax, float time) const = 0;
};

