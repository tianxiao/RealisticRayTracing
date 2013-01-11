#pragma once
#define MATRIX_INVERSE_EPSILON		1e-14
#define MATRIX_EPSILON				1e-6
#include "import.h"
#include "Vec3d.h"
class R_DECLDIR txMatrix3
{
public:
	txMatrix3(void);
	explicit txMatrix3(const txVec3d &v0, const txVec3d &v1, const txVec3d &v2);
	explicit txMatrix3(
		double xx, double xy, double xz, 
		double yx, double yy, double yz,
		double zx, double zy, double zz);
	~txMatrix3(void);

	void Zero( void );
	void Identity( void );
	double Determinant( void ) const ;
	bool InverseSelf( void ) ;

	txVec3d SolveLinear3(const txVec3d &right);

private:
	double mat[3][3];
};


inline void txMatrix3::Zero( void ){
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			mat[i][j] = 0.0;
}

inline void txMatrix3::Identity( void ){
	Zero();
	mat[0][0] = 1.0;
	mat[1][1] = 1.0;
	mat[2][2] = 1.0;
}

inline double txMatrix3::Determinant( void ) const {
	double det2_11_22 = mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1];
	double det2_12_20 = mat[1][2]*mat[2][0] - mat[1][0]*mat[2][2];
	double det2_10_21 = mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0];

	return mat[0][0]*det2_11_22 + mat[0][1]*det2_12_20 + mat[0][2]*det2_10_21;
}



