#include "sphere.hpp"

#include <godot_cpp/classes/csg_sphere3d.hpp>

godot::Sphere::Sphere(Vector3 position, double radius, double radial_segments,
                      double rings) {
  time_passed = 0.0;

  sphere_ = new godot::CSGSphere3D;
  sphere_->set_position(position);
  sphere_->set_radius(radius);
  sphere_->set_radial_segments(radial_segments);
  sphere_->set_rings(rings);
  this->add_child(sphere_);
}

godot::Sphere::~Sphere() { delete sphere_; }
