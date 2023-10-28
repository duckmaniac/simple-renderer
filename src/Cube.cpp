#include "Cube.h"

Cube::Cube(Point3D position, float side_length) : 
	Object3D{ position }, side_length_{side_length} {

	float half_side_length = side_length_ / 2;

	// Cube vertices.
	Point3D A = position_ + Point3D{ -half_side_length, -half_side_length, half_side_length };
	Point3D B = position_ + Point3D{ half_side_length, -half_side_length, half_side_length };
	Point3D C = position_ + Point3D{ half_side_length, half_side_length, half_side_length };
	Point3D D = position_ + Point3D{ -half_side_length, half_side_length, half_side_length };
	Point3D E = position_ + Point3D{ -half_side_length, -half_side_length, -half_side_length };
	Point3D F = position_ + Point3D{ half_side_length, -half_side_length, -half_side_length };
	Point3D G = position_ + Point3D{ half_side_length, half_side_length, -half_side_length };
	Point3D H = position_ + Point3D{ -half_side_length, half_side_length, -half_side_length };

	// Cube edges.
	mesh_.push_back(std::make_pair(A, B));
	mesh_.push_back(std::make_pair(B, C));
	mesh_.push_back(std::make_pair(C, D));
	mesh_.push_back(std::make_pair(D, A));
	mesh_.push_back(std::make_pair(E, F));
	mesh_.push_back(std::make_pair(F, G));
	mesh_.push_back(std::make_pair(G, H));
	mesh_.push_back(std::make_pair(H, E));
	mesh_.push_back(std::make_pair(A, E));
	mesh_.push_back(std::make_pair(B, F));
	mesh_.push_back(std::make_pair(C, G));
	mesh_.push_back(std::make_pair(D, H));
}