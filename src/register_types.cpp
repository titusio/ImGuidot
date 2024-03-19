#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>

#include "imguidot.hpp"

using namespace godot;

static ImGuiDot *imguidot = nullptr;

void imguidot_initialize(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		ClassDB::register_class<ImGuiDot>();

		// create instance
		imguidot = memnew(ImGuiDot);
		Engine::get_singleton()->register_singleton("ImGuiDot", imguidot);
	}
}

void imguidot_terminate(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		Engine::get_singleton()->unregister_singleton("ImGuiDot"); 
		memdelete(imguidot);
	}
}

extern "C"
{
	GDExtensionBool GDE_EXPORT imguidot_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(imguidot_initialize);
		init_obj.register_terminator(imguidot_terminate);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();	
	}
}
