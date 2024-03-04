#include "gdexample.h"
#include <godot_cpp/classes/csg_sphere3d.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/omni_light3d.hpp>

void godot::GDExample::_ready() {
	godot::CSGSphere3D sphere;
	sphere.set_radius(5.0);
	sphere.set_radial_segments(20);
	sphere.set_rings(20);
	this->add_child(&sphere);

	godot::Camera3D main_camera;
	main_camera.set_fov(75.0);
	main_camera.set_near(0.05);
	main_camera.set_far(4000.0);
	main_camera.set_position(Vector3(0, 0, 20));
	this->add_child(&main_camera);

	godot::OmniLight3D omnilight;
	omnilight.set_position(Vector3(0, 7, 0));
	this->add_child(&omnilight);
}