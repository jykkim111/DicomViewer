#include "Vec2.h"
#include "Vec3.h"

using namespace std;

int main() {

	Vec2 vector1 = Vec2(10, 10);
	Vec2 vector1_1 = Vec2(2, 2);
	Vec3 vector2 = Vec3(10, 10, 10);
	Vec3 vector2_1 = Vec3(2, 2, 2);
	
	std::cout << vector1 << std::endl;
	cout << vector2 << endl;

	cout << vector1 + vector1_1 << endl;
	cout << vector2 + vector2_1 << endl;
	cout << vector1 - vector1_1 << endl;
	cout << vector1 * 2 << endl;
	cout << vector1 * vector1_1 << endl;
	
	vector1.normalize();
	cout << vector1 << endl;


	return 1;
}

