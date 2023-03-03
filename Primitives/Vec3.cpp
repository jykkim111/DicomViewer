#include "Vec3.h"


Vec3 Vec3::operator+(const Vec3& v) {
	Vec3 result;

	result.x_ = this->x_ + v.x_;
	result.y_ = this->y_ + v.y_;
	result.z_ = this->z_ + v.z_;

	return result;
}

Vec3 Vec3::operator-(const Vec3& v) {
	Vec3 result;

	result.x_ = this->x_ - v.x_;
	result.y_ = this->y_ - v.y_;
	result.z_ = this->z_ - v.z_;

	return result;
}

//multiplying float to vector
Vec3 Vec3::operator*(const float& v) {
	Vec3 result;

	result.x_ = this->x_ * v;
	result.y_ = this->y_ * v;
	result.z_ = this->z_ * v;

	return result;
}

//inner/dot product
float Vec3::operator*(const Vec3& v) {
	float result;

	result = this->x_ * v.x_ + this->y_ * v.y_ + this->z_ * v.z_;

	return result;
}


void Vec3::normalize() {

	float vec_length = len();

	this->x_ / vec_length;
	this->y_ / vec_length;
	this->z_ / vec_length;

}