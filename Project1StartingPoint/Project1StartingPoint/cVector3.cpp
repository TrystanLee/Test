#include "cVector3.h"
#include <float.h>
#include <math.h>
#include<iostream>
using namespace std;

// TODO: Implement as defined
cVector3::cVector3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

// TODO: Implement as defined
cVector3::cVector3(const cVector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

// TODO: Implement as defined
cVector3& cVector3::operator=(const cVector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

// TODO: Implement as defined
cVector3::cVector3(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
}

// TODO: Implement as defined
cVector3::cVector3(float _x, float _y, float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

// TODO: Implement as defined
cVector3::~cVector3()
{
	//delete this;
}

// TODO: Implement as defined
float cVector3::Length()
{
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

// TODO: Implement as defined
float cVector3::Length2()
{
	return this->Length()*this->Length();
}

// TODO: Implement as defined
void cVector3::Zeros()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

// TODO: Implement as defined
void cVector3::Invert()
{
	this->x *= -1.0f;
	this->y *= -1.0f;
	this->z *= -1.0f;
}

// TODO: Implement as defined
void cVector3::Normalize()
{
	this->operator/=(this->Length());
}

// TODO: Implement as defined
void cVector3::operator*=(const float value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
}

// TODO: Implement as defined
void cVector3::operator/=(const float value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
}

// TODO: Implement as defined
void cVector3::operator+=(const cVector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

// TODO: Implement as defined
void cVector3::operator-=(const cVector3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

// TODO: Implement as defined
cVector3 operator*(const cVector3& vec, const float value)
{
	return cVector3(vec.x / value, vec.y / value, vec.z / value);
}

// TODO: Implement as defined
cVector3 operator/(const cVector3& vec, const float value)
{
	return cVector3(vec.x*value,vec.y*value,vec.z*value);
}

// TODO: Implement as defined
cVector3 operator-(const cVector3& a, const cVector3& b)
{
	return cVector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

// TODO: Implement as defined
cVector3 operator+(const cVector3& a, const cVector3& b)
{
	return cVector3(a.x+b.x,a.y+b.y,a.z+b.z);
}

// TODO: Implement as defined
cVector3 componentProduct(const cVector3& a, const cVector3& b)
{
	return cVector3(a.x*b.x,a.y*b.y,a.z*b.z);
}

// TODO: Implement as defined
float scalarProduct(const cVector3& a, const cVector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// TODO: Implement as defined
cVector3 vectorProduct(const cVector3& a, const cVector3& b)
{
	float x = a.y*b.z - a.z*b.y;
	float y = a.z*b.x - a.x*b.z;
	float z = a.x*b.y - a.y*b.x;
	return cVector3(x,y,z);
}