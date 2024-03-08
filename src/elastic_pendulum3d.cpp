#include "elastic_pendulum3d.hpp"
#include <godot_cpp/classes/geometry3d.hpp>

namespace godot {

MeshInstance3D *draw_line_3D(Vector3 starting_point, Vector3 ending_point,
                             Color color) {
  auto mesh_instance = new MeshInstance3D;
  auto immediate_mesh = new ImmediateMesh;
  mesh_instance->set_mesh(immediate_mesh);
  mesh_instance->set_cast_shadows_setting(
      GeometryInstance3D::SHADOW_CASTING_SETTING_OFF);

  immediate_mesh->surface_begin(Mesh::PRIMITIVE_LINES);
  immediate_mesh->surface_add_vertex(starting_point);
  immediate_mesh->surface_add_vertex(ending_point);
  immediate_mesh->surface_end();
  return mesh_instance;
}

Vector3 calculate_pendulum_force_3D(double spring_rate, double eq_length,
                                    double distance, Vector3 position_vector) {
  double force = spring_rate * (eq_length - distance);
  auto force_direction = position_vector.normalized();
  return force_direction * force;
}

ElasticPendulum3D::ElasticPendulum3D() {
  time_passed = 0.0;
  // maybe I shoulde use godot::Sphere here? If it's wouldnt be used here then
  // it can be deleted
  // YEP DEFINITELLY I SHOULD
  body = new CSGSphere3D;
  body->set_radius(2);
  body->set_radial_segments(20);
  body->set_rings(10);
  this->add_child(body);

  attachment_point = Vector3(0.0, 25.0, 0.0);
  eq_length = 50.0;
  spring_rate = 2.0;
  pendulum_force = Vector3(0.0, 0.0, 0.0);
  velocity = Vector3(10.0, 10.0, 0.0);

  line = draw_line_3D(attachment_point, body->get_transform().origin);
  this->add_child(line);

  // doesn't meet DRY but will refactor this after deadline
  omnilight = new godot::OmniLight3D;
  omnilight->set_position(Vector3(0.0, 25.0, 0.0));
  this->add_child(omnilight);

  main_camera = new godot::Camera3D;
  main_camera->set_fov(75.0);
  main_camera->set_near(0.05);
  main_camera->set_far(4000.0);
  main_camera->set_position(Vector3(0, -5, 60));
  this->add_child(main_camera);
}

ElasticPendulum3D::~ElasticPendulum3D() {
  delete main_camera;
  delete omnilight;
  delete line;
}

void ElasticPendulum3D::_physics_process(double delta) {
  double distance = attachment_point.distance_to(body->get_position());
  Vector3 position_vector = body->get_position() - attachment_point;
  pendulum_force = calculate_pendulum_force_3D(spring_rate, eq_length, distance,
                                               position_vector);
  velocity += delta * (pendulum_force + G_FORCE_3D);
  body->set_position(body->get_position() + delta * velocity);
  // line->remove_point(1);
  this->remove_child(line);
  delete line;
  line = draw_line_3D(attachment_point, body->get_position());
  this->add_child(line);
}
} // namespace godot