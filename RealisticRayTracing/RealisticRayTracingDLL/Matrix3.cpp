#include "StdAfx.h"
#include "Matrix3.h"
#include "Vec3d.h"

//////////////////////////////////////////////////////////////////
/*    00 01 02
 *    10 11 12
 *    20 21 22
 *    (00, 10, 20) = v0
 *    (01, 11, 21) = v1
 *    (02, 12, 22) = v2
*/    
//////////////////////////////////////////////////////////////////

txMatrix3::txMatrix3(void)
{
	Zero();
}

txMatrix3::txMatrix3(
	double xx, double xy, double xz, 
	double yx, double yy, double yz,
	double zx, double zy, double zz){
	mat[0][0] = xx, mat[0][1] = xy, mat[0][2] = xz;
	mat[1][0] = yx, mat[1][1] = yy, mat[1][2] = yz;
	mat[2][0] = zx, mat[2][1] = zy, mat[2][2] = zz;
}

txMatrix3::txMatrix3(const txVec3d &v0, const txVec3d &v1, const txVec3d &v2){
	mat[0][0] = v0.GetX(), mat[1][0] = v0.GetY(), mat[2][0] = v0.GetZ();
	mat[0][1] = v1.GetX(), mat[1][1] = v1.GetY(), mat[2][1] = v1.GetZ();
	mat[0][2] = v2.GetX(), mat[1][2] = v2.GetY(), mat[2][2] = v2.GetZ();
}

txMatrix3::~txMatrix3(void)
{
}

bool txMatrix3::InverseSelf( void ){
	txMatrix3 inverse;
	//double det, invDet;

	inverse.mat[0][0] =   mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1];
	inverse.mat[0][1] = -(mat[1][2]*mat[2][0] - mat[1][0]*mat[2][2]);

	return false;
}
// Cramer's Rule
// http://mathworld.wolfram.com/CramersRule.html
txVec3d txMatrix3::SolveLinear3(const txVec3d &right){
	txVec3d rtn;
	double det = Determinant();
	double determinInverse = 1.0/Determinant();

	txMatrix3 xM(
		right.GetX(),mat[0][1],mat[0][2],
		right.GetY(),mat[1][1],mat[1][2],
		right.GetZ(),mat[2][1],mat[2][2]);

	txMatrix3 yM(
		mat[0][0],right.GetX(),mat[0][2],
		mat[1][0],right.GetY(),mat[1][2],
		mat[2][0],right.GetZ(),mat[2][2]);

	txMatrix3 zM(
		mat[0][0],mat[0][1],right.GetX(),
		mat[1][0],mat[1][1],right.GetY(),
		mat[2][0],mat[2][1],right.GetZ());

	rtn.SetX(xM.Determinant()*determinInverse);
	rtn.SetY(yM.Determinant()*determinInverse);
	rtn.SetZ(zM.Determinant()*determinInverse);

	return rtn;
}
