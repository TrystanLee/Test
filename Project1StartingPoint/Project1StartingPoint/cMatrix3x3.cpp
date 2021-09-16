#include "cMatrix3x3.h"
#include "cVector3.h"
#include<iostream>
using namespace std;
// TODO: Implement as defined
cMatrix3x3::cMatrix3x3()
{
	this->vectors[0] = cVector3(1,0,0);
	this->vectors[1] = cVector3(0,1,0);
	this->vectors[2] = cVector3(0,0,1);
}

// TODO: Implement as defined
cMatrix3x3::cMatrix3x3(const cMatrix3x3& other)
{
	this->vectors[0] = other.vectors[0];
	this->vectors[1] = other.vectors[1];
	this->vectors[2] = other.vectors[2];
}

// TODO: Implement as defined
cMatrix3x3& cMatrix3x3::operator=(const cMatrix3x3& other)
{
	this->vectors[0] = other.vectors[0];
	this->vectors[1] = other.vectors[1];
	this->vectors[2] = other.vectors[2];
	return *this;
}

// TODO: Implement as defined
cMatrix3x3::cMatrix3x3(float value)
{
	this->vectors[0] = cVector3(value,0,0);
	this->vectors[1] = cVector3(0,value,0);
	this->vectors[2] = cVector3(0,0,value);
}

// TODO: Implement as defined
cMatrix3x3::cMatrix3x3(const cVector3& xCol, const cVector3& yCol, const cVector3& zCol)
{
	this->vectors[0] = xCol;
	this->vectors[1] = yCol;
	this->vectors[2] = zCol;
}

// TODO: Implement as defined
cMatrix3x3::~cMatrix3x3()
{
	//delete this;
}

// TODO: Implement as defined
cMatrix3x3 orthonormalBasis(const cVector3& xVec, const cVector3& zVec)
{
	// TODO: Generate an orthonormal basis, using xVec and zVec.
	//       The input vectors may be manipulated, however the 
	//       returned axes must essentially be:
	//       x-axis: sourced from xVec
	//       y-axis: generated using math!
	//       z-axis: sourced from zVec
	/*float dotted = scalarProduct(xVec, zVec);
	if (dotted == 0) {
		cout << "Orthonormal Basis cannot be made cause the vectors are not orthogonal" <<endl;
		return cMatrix3x3(0,0,0);
	}*/

	cVector3 c = crossProduct(xVec,zVec);
	cVector3 b = crossProduct(c, xVec);

	c.Normalize();
	b.Normalize();
	cVector3 a;
	a.operator=(xVec);
	a.Normalize();
	//cout << c.y << endl;
	return cMatrix3x3(a,b,c);
}