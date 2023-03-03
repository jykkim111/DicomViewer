#pragma once

#include <vector>

using namespace std;

class Volume3D
{

private:
	int m_depth, m_height, m_width;
	vector<float> m_volume;
	float spacing_x, spacing_y, spacing_z = 1;

public:
	Volume3D() : m_depth(1), m_height(1), m_width(1) {}

	Volume3D(const int& depth, const int& height, const int& width) {
		this->m_depth = depth;
		this->m_height = height;
		this->m_width = width;

		m_volume.reserve(this->m_depth * this->m_height * this->m_depth);
	}

	void setDepth(int new_depth);
	void setHeight(int new_height);
	void setWidth(int new_width);

	int getDepth();
	int getHeight();
	int getWidth();

	void setSpacingX(float x_spacing);
	void setSpacingY(float y_spacing);
	void setSpacingZ(float z_spacing);

	float getSpacingX();
	float getSpacingY();
	float getSpacingZ();

	void setVoxelValue(float x, float y, float z, float val);
	float getVoxelValue(float x, float y, float z);

	vector<float> getVolumeData() { return m_volume; }


private:
	bool isOutOfBounds(float x, float y, float z);
	float interpolate_1d(float v1, float v2, float x);
	float interpolate_2d(float v1, float v2, float v3, float v4, float x, float y);
	float interpolate_3d(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8,
		float x, float y, float z);
};

