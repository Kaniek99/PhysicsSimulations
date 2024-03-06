#ifndef SPHERE_H
#define SPHERE_H

#include <godot_cpp/classes/csg_sphere3d.hpp>

namespace godot {

class Sphere : public CSGSphere3D {
  GDCLASS(Sphere, CSGSphere3D)

private:
  double time_passed;
  CSGSphere3D *sphere_;

protected:
  static void _bind_methods() {}

public:
  Sphere(Vector3 position = Vector3(0.0, 0.0, 0.0), double radius = 0.5,
         double radial_segments = 12.0, double rings = 6.0);
  ~Sphere();
};

} // namespace godot

#endif
