#pragma once
#include "MemoryPool.h"
#include <iostream>

namespace Core {
	class EngineObject {
	public:
		uint64_t data[2]{0, 0};
		static Memory::MemoryPool allocator;

		static void* operator new(std::size_t size) {
			return allocator.Allocate(size);
		}

		static void operator delete(void* ptr, std::size_t size) {
			return allocator.deallocate(ptr, size);
		}
	};

	// Instantiate allocator with 8 chunks per block
	Memory::MemoryPool EngineObject::allocator(8);
}