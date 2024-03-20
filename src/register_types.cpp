#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "imguidot.hpp"

using namespace godot;

static ImGuiDot *imguidot_singleton = nullptr;

void imguidot_initialize(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		ClassDB::register_class<ImGuiDot>();
		UtilityFunctions::print("ImGuiDot registered");

		imguidot_singleton = memnew(ImGuiDot);
		UtilityFunctions::print("ImGuiDot singleton created");

		Engine::get_singleton()->register_singleton("ImGuiDot", ImGuiDot::get_singleton());
		UtilityFunctions::print("ImGuiDot singleton registered");
	}
}

void imguidot_terminate(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		Engine::get_singleton()->unregister_singleton("ImGuiDot");
		UtilityFunctions::print("ImGuiDot singleton unregistered");

		memdelete(imguidot_singleton);
		UtilityFunctions::print("ImGuiDot singleton deleted");
	}
}

extern "C"
{
	GDExtensionBool GDE_EXPORT imguidot_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) 
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(imguidot_initialize);
		init_obj.register_terminator(imguidot_terminate);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();	
	}
}
