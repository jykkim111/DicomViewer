#pragma once

#include <math.h>
#include <iostream>

class Vec2
{
public:
	float x_, y_;

	Vec2() : x_(0.0f), y_(0.0f){}

	Vec2(const float& x_, const float& y_) {
		this->x_ = x_;
		this->y_ = y_;
	}

	Vec2 operator+(const Vec2& v);
	Vec2 operator-(const Vec2& v);

	//multiplying float to vector
	Vec2 operator*(const float& v);

	//inner/dot product
	float operator*(const Vec2& v);

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
		stream << "(" << vec.x() << "," << vec.y() << ")";
		return stream;
	}

	float x() const { return x_; }
	float y() const { return y_; }
	float len() { return sqrt(pow(x_, 2) + pow(y_, 2)); }

	void normalize();
	
};

