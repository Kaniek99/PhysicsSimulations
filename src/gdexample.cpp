#include "gdexample.hpp"
#include <godot_cpp/classes/csg_sphere3d.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/omni_light3d.hpp>

godot::GDExample::GDExample() {
	time_passed = 0.0;

	sphere_ = new godot::CSGSphere3D;
	sphere_->set_radius(5.0);
	sphere_->set_radial_segments(20);
	sphere_->set_rings(20);
	this->add_child(sphere_);

	main_camera_ = new godot::Camera3D;
	main_camera_->set_fov(75.0);
	main_camera_->set_near(0.05);
	main_camera_->set_far(4000.0);
	main_camera_->set_position(Vector3(0, 0, 20));
	this->add_child(main_camera_);

	omnilight_ = new godot::OmniLight3D;
	omnilight_->set_position(Vector3(0, 7, 0));
	this->add_child(omnilight_);
}

godot::GDExample::~GDExample() {
	delete sphere_;
	delete main_camera_;
	delete omnilight_;
}
