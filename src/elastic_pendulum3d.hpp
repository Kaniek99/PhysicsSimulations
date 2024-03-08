#ifndef GD_ELASTIC_PENDULUM3D_HPP
#define GD_ELASTIC_PENDULUM3D_HPP

#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/csg_sphere3d.hpp>
#include <godot_cpp/classes/immediate_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/omni_light3d.hpp>

namespace godot {
const Vector3 G_FORCE_3D = Vector3(0.0, -10.0, 0.0);

MeshInstance3D *draw_line_3D(Vector3 starting_point, Vector3 ending_point,
                             Color color = Color(0, 0, 0, 1));

Vector3 calculate_pendulum_force_3D(double spring_rate, double eq_length,
                                    double distance, Vector3 position_vector);

class ElasticPendulum3D : public Node3D {
  GDCLASS(ElasticPendulum3D, Node3D)

private:
  double time_passed;
  CSGSphere3D *body;
  MeshInstance3D *line;
  Camera3D *main_camera;
  OmniLight3D *omnilight;

  Vector3 attachment_point;
  Vector3 pendulum_force;
  Vector3 velocity;
  double eq_length;
  double spring_rate;

protected:
  static void _bind_methods() {}

public:
  ElasticPendulum3D();
  ~ElasticPendulum3D();

  void _physics_process(double delta) override;
};

} // namespace godot

#endif
