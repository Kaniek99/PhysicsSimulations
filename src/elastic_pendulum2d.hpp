#ifndef GD_ELASTIC_PENDULUM2D_HPP
#define GD_ELASTIC_PENDULUM2D_HPP

#include <godot_cpp/classes/line2d.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/static_body2d.hpp>

namespace godot {

const Vector2 G_FORCE = Vector2(0, 100);

Vector2 calculate_pendulum_force(double spring_rate, double eq_length,
                                 double distance, Vector2 gowno);

class ElasticPendulum2D : public Node2D {
  GDCLASS(ElasticPendulum2D, Node2D)

private:
  double time_passed;

protected:
  static void _bind_methods() {}
  StaticBody2D *body;
  // Sprite2D *icon;
  // Ref<Image> img;
  Vector2 attachment_point;
  Vector2 pendulum_force;
  Vector2 velocity;
  double eq_length;
  double spring_rate;
  Line2D *line;

public:
  ElasticPendulum2D();
  ~ElasticPendulum2D();

  void _draw() override;
  void _ready() override;
  void _physics_process(double delta) override;
};

} // namespace godot

#endif
