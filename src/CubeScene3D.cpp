#include "CubeScene3D.h"

CubeScene3D::CubeScene3D(std::string name) : 
	Scene{ name }, 
	p_cube_{ std::make_shared<Cube>(Cube({ 0, 0, 0 }, 150)) }, 
	camera_position_{350, 350, 2500},
	angular_velocity_{ 2.5 } {
	add_object(p_cube_);
	p_camera_ = std::make_shared<Camera3D>(Camera3D(camera_position_, {720, 720}, 2500));
}

void CubeScene3D::update(float delta_time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		p_cube_->rotate_along_y(-angular_velocity_ * delta_time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p_cube_->rotate_along_y(angular_velocity_ * delta_time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		p_cube_->rotate_along_x(-angular_velocity_ * delta_time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		p_cube_->rotate_along_x(angular_velocity_ * delta_time);
	}
}