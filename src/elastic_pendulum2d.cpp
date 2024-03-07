#include "elastic_pendulum2d.hpp"

namespace godot {

ElasticPendulum2D::ElasticPendulum2D() {
  time_passed = 0.0;

  body = new StaticBody2D;
  attachment_point = Vector2(300.0, 100.0);
  eq_length = 100.0;
  spring_rate = 2.0;
  pendulum_force = Vector2(0.0, 0.0);
  velocity = Vector2(0.0, 0.0);
  line = new Line2D;
}

ElasticPendulum2D::~ElasticPendulum2D() {
  delete line;
  delete body;
}

void ElasticPendulum2D::_draw() {
  this->draw_circle(attachment_point, 5, godot::Color(1, 0, 0, 1));
}

void ElasticPendulum2D::_ready() {
  body->set_position(Vector2(400.0, 200.0));
  line->add_point(attachment_point);
  line->add_point(body->get_position());
  line->set_width(1.0);
  this->add_child(line);
}

Vector2 calculate_pendulum_force(double spring_rate, double eq_length,
                                 double distance, Vector2 position_vector) {
  double force = spring_rate * (eq_length - distance);
  return position_vector / distance * force;
}

void ElasticPendulum2D::_physics_process(double delta) {
  double distance = attachment_point.distance_to(body->get_position());
  Vector2 position_vector = body->get_position() - attachment_point;
  pendulum_force = calculate_pendulum_force(spring_rate, eq_length, distance,
                                            position_vector);
  velocity += delta * (pendulum_force + G_FORCE);
  body->set_position(body->get_position() + delta * velocity);
  line->remove_point(1);
  line->add_point(body->get_position());
}

} // namespace godot