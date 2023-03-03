#include "Vec2.h"

Vec2 Vec2::operator+(const Vec2& v) {
	Vec2 result;

	result.x_ = this->x_ + v.x_;
	result.y_ = this->y_ + v.y_;

	return result;
}

Vec2 Vec2::operator-(const Vec2& v) {
	Vec2 result;

	result.x_ = this->x_ - v.x_;
	result.y_ = this->y_ - v.y_;

	return result;
}

//multiplying float to vector
Vec2 Vec2::operator*(const float& v) {
	Vec2 result;

	result.x_ = this->x_ * v;
	result.y_ = this->y_ * v;

	return result;
}

//inner/dot product
float Vec2::operator*(const Vec2& v) {
	float result;

	result = this->x_ * v.x_ + this->y_ * v.y_;

	return result;
}


void Vec2::normalize() {

	float vec_length = len();

	this->x_ /= vec_length;
	this->y_ /= vec_length;

}