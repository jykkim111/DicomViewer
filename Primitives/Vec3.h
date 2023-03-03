#pragma once

#include <math.h>
#include <iostream>

class Vec3
{
public:
	float x_, y_, z_;

	Vec3() : x_(0.0f), y_(0.0f), z_(0.0f) {}

	Vec3(const float& x_, const float& y_, const float& z_) {
		this->x_ = x_;
		this->y_ = y_;
		this->z_ = z_;
	}

	Vec3 operator+(const Vec3& v);
	Vec3 operator-(const Vec3& v);

	//multiplying float to vector
	Vec3 operator*(const float& v);

	//inner/dot product
	float operator*(const Vec3& v);

	friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
		stream << "(" << vec.x_ << "," << vec.y_ << "," << vec.z_ << ")";
		return stream;
	}

	float x() const { return x_; }
	float y() const { return y_; }
	float z() const { return z_; }
	float len() { return sqrt(pow(x_, 2) + pow(y_, 2)); }

	void normalize();
};

