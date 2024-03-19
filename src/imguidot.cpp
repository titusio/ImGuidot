#include "imguidot.hpp"

#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/image.hpp>

using namespace godot;

ImGuiDot::ImGuiDot()
{
	ERR_FAIL_COND_MSG(singleton, "ImGuiDot singleton already exists");
	singleton = this;
}

ImGuiDot::~ImGuiDot()
{
	ERR_FAIL_COND_MSG(singleton != this, "ImGuiDot singleton does not match");
	singleton = nullptr;
}

ImGuiDot *ImGuiDot::get_singleton()
{
	return singleton;
}

void ImGuiDot::_bind_methods()
{
}
