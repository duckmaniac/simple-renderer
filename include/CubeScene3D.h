#ifndef CUBE_SCENE_3D_H
#define	CUBE_SCENE_3D_H

#include "FLY/Scene.h"
#include "Cube.h"

class CubeScene3D : public Scene {
private:
	std::shared_ptr<Cube> p_cube_;
	Point3D camera_position_;
	float angular_velocity_;

public:
	CubeScene3D(std::string name);
	void update(float delta_time) override;
};

#endif // CUBE_SCENE_3D_H