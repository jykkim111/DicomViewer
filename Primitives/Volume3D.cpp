#include "Volume3D.h"

void Volume3D::setDepth(int new_depth) {
	this->m_depth = new_depth;
}

void Volume3D::setHeight(int new_height) {
	this->m_height = new_height;
}

void Volume3D::setWidth(int new_width) {
	this->m_width = new_width;
}

int Volume3D::getDepth() {
	return this->m_depth;
}

int Volume3D::getWidth() {
	return this->m_width;
}

int Volume3D::getHeight() {
	return this->m_height;
}

bool Volume3D::isOutOfBounds(float x, float y, float z) {
	return (x < 0 || y < 0 || z < 0 || x >= this->m_width || y >= this->m_height || z >= this->m_depth);
}

void Volume3D::setSpacingX(float x_spacing) {
	this->spacing_x = x_spacing;
}

void Volume3D::setSpacingY(float y_spacing) {
	this->spacing_y = y_spacing;
}

void Volume3D::setSpacingZ(float z_spacing) {
	this->spacing_z = z_spacing;
}

float Volume3D::getSpacingX() {
	return this->spacing_x;
}

float Volume3D::getSpacingY() {
	return this->spacing_y;
}

float Volume3D::getSpacingZ() {
	return this->spacing_z;
}

void Volume3D::setVoxelValue(float x, float y, float z, float val) {

	int xi = (int)round(x);
	int yi = (int)round(y);
	int zi = (int)round(z);

	if (!isOutOfBounds(xi, yi, zi)) {
		m_volume[zi * m_width * m_height + yi * m_width + xi] = val;
	}

}

float Volume3D::getVoxelValue(float x, float y, float z) {
	if (isOutOfBounds((int)floor(x), (int)floor(y), (int)floor(z))
		|| isOutOfBounds((int)ceil(x), (int)ceil(y), (int)ceil(z))) {
		return 0.0;
	}

	float v1 = m_volume[(int)floor(z) * this->m_height * this->m_width + (int)floor(y) * this->m_width + (int)floor(x)];
	float v2 = m_volume[(int)floor(z) * this->m_height * this->m_width + (int)floor(y) * this->m_width + (int)ceil(x)];
	float v3 = m_volume[(int)floor(z) * this->m_height * this->m_width + (int)ceil(y) * this->m_width + (int)floor(x)];
	float v4 = m_volume[(int)floor(z) * this->m_height * this->m_width + (int)ceil(y) * this->m_width + (int)ceil(x)];
	float v5 = m_volume[(int)ceil(z) * this->m_height * this->m_width + (int)floor(y) * this->m_width + (int)floor(x)];
	float v6 = m_volume[(int)ceil(z) * this->m_height * this->m_width + (int)floor(y) * this->m_width + (int)ceil(x)];
	float v7 = m_volume[(int)ceil(z) * this->m_height * this->m_width + (int)ceil(y) * this->m_width + (int)floor(x)];
	float v8 = m_volume[(int)ceil(z) * this->m_height * this->m_width + (int)ceil(y) * this->m_width + (int)ceil(x)];

	return interpolate_3d(v1, v2, v3, v4, v5, v6, v7, v8, x - floor(x), y - floor(y), z - floor(z));
}


float Volume3D::interpolate_1d(float v1, float v2, float x) {
	return v1 * (1 - x) + v2 * x;
}


float Volume3D::interpolate_2d(float v1, float v2, float v3, float v4, float x, float y) {
	float s = interpolate_1d(v1, v2, x);
	float t = interpolate_1d(v3, v4, x);

	return interpolate_1d(s, t, y);
}

float Volume3D::interpolate_3d(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float x, float y, float z) {
	float s = interpolate_2d(v1, v2, v3, v4, x, y);
	float t = interpolate_2d(v5, v6, v7, v8, x, y);

	return interpolate_1d(s, t, z);
}




