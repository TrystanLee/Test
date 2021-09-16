#pragma once
#include "cVector3.h"


class cMatrix3x3
{
public:
	// TODO: Declare/Define the required data content
	//       in convenient and usable way.

	// Default Constructor
	// Initialize this matrix to an Identity.
	cMatrix3x3();
	// Copy Constructor
	// Initialize this matrix to the same contents as a given matrix.
	cMatrix3x3(const cMatrix3x3& other);
	// Copy Assignment
	// Initialize this matrix to the same contents as a given matrix.
	cMatrix3x3& operator=(const cMatrix3x3& other);
	// Parameterized Constructor
	// Initialize this matrix to a Diagonal, with a given value.
	cMatrix3x3(float value);
	// Parameterized Constructor
	// Initialize this matrix to given column vectors.
	cMatrix3x3(const cVector3& xCol, const cVector3& yCol, const cVector3& zCol);
	// Destructor
	~cMatrix3x3();
	cVector3 vectors[3];
};

// Generate an orthonormal basis, given two linearly independent vectors.
// The input vectors are unaffected.
cMatrix3x3 orthonormalBasis(const cVector3& xVec, const cVector3& zVec);