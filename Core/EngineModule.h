#pragma once
#include <string_view>
#include <stdint.h>


namespace Core::Module {
	enum class ModuleType {
		PANEL,
		RENDERING,
		PHYSICS,
		MANAGER,
		GAMEPLAY,

	};
	struct ModuleData {
		std::string_view name;
		std::string_view description;
		uint8_t unique_identifier;

	};
	class EngineModule {
	};
};