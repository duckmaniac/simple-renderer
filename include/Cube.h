#ifndef CUBE_H
#define CUBE_H

#include "FLY/Object3D.h"

class Cube : public Object3D {
private:
	float side_length_;

public:
	Cube(Point3D position, float side_length);
	void update() override {};
};

#endif // CUBE_H