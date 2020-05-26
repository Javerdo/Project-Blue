#pragma once
#include "EngineObject.h"

#include <iostream>
#include <array>
#include <memory>

/* Key C++ 11 features: std::array, list initialization, variadic templates, constexpr, auto, lambdas, 
   range-based for loops, rvalue references, defaulted and deleted functions, std::unique_ptr */

/* Key C++ 14 features: relaxed constexpr, generic and variadic lambdas, 
   return type deduction for normal functions, std::make_unique */

/* Key C++ 17 features: structured bindings, std::string_view, class template argument deduction, 
   guaranteed copy elision, fold expressions */

/* Key C++ 20 features: Concepts, text formatting, ranges, modules */


int main() {
	/* Memory pool testing */
	std::array<std::unique_ptr<Core::EngineObject>, 10> objects;
	std::cout << "Size(Object) = " << sizeof(Core::EngineObject) << std::endl << std::endl;

	// Allocation
	for (int i = 0; i < objects.size(); ++i) {
		objects[i] = std::make_unique<Core::EngineObject>(Core::EngineObject());
		std::cout << "new [" << i << "] = " << objects[i] << std::endl;
	}

	std::cout << std::endl;

	// Deallocation
	for (int i = objects.size() - 1; i >= 0; --i) {
		std::cout << "delete [" << i << "] = " << objects[i] << std::endl;
		objects[i].reset();
	}

	std::cout << std::endl;
	objects[0] = std::make_unique<Core::EngineObject>(Core::EngineObject());
	std::cout << "new [0] = " << objects[0] << std::endl << std::endl; 

	return 0;
}