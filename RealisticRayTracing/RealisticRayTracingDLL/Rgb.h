#pragma once
#include "import.h"

class R_DECLDIR txRgb
{
public:

	txRgb(double r_=0.0, double g_=0.0, double b_=0.0);
	~txRgb(void);

	double GetR() const { return r; };
	double GetG() const { return g; };
	double GetB() const { return b; };
	void SetR(double r_) { r = r_; };
	void SetG(double g_) { g = g_; };
	void SetB(double b_) { b = b_; };

private:
	double r, g, b;
};

