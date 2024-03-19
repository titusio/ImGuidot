#ifndef IMGUIDOT_HPP
#define IMGUIDOT_HPP

#include <godot_cpp/classes/control.hpp>
#include <imgui.h>

namespace godot 
{
	class ImGuiDot : public Control
	{
		GDCLASS(ImGuiDot, Control);

	public:
		ImGuiDot();
		~ImGuiDot();

	protected:
		static void _bind_methods();
	};
}

#endif // IMGUIDOT_HPP

