#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/csg_sphere3d.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/omni_light3d.hpp>

namespace godot {

	class GDExample : public Node3D {
		GDCLASS(GDExample, Node3D)

	private:
		double time_passed;
		godot::CSGSphere3D* sphere_;
		godot::Camera3D* main_camera_;
		godot::OmniLight3D* omnilight_;

	protected:
		static void _bind_methods() {}

	public:
		GDExample();
		~GDExample();

		// void _process(double delta) override;
	};

}

#endif
