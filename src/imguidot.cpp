#include "imguidot.hpp"

#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/image.hpp>

using namespace godot;


ImGuiDot *ImGuiDot::singleton = nullptr;

ImGuiDot::ImGuiDot()
{
	ERR_FAIL_COND(singleton != nullptr);
	singleton = this;
}

ImGuiDot::~ImGuiDot()
{
	ERR_FAIL_COND(singleton != this);
	singleton = nullptr;
}

ImGuiDot *ImGuiDot::get_singleton()
{
	return singleton;
}

void ImGuiDot::HelloThere()
{
	UtilityFunctions::print("General Kenobi");
}

void ImGuiDot::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("HelloThere"), &ImGuiDot::HelloThere);
}
