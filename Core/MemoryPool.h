#pragma once
#include <cstddef>
#include <memory>

// https://medium.com/@mateusgondimlima/designing-and-implementing-a-pool-allocator-data-structure-for-memory-management-in-games-c78ed0902b69
// https://github.com/cacay/MemoryPool
// http://dmitrysoshnikov.com/compilers/writing-a-pool-allocator/

namespace Core::Memory {
	struct Chunk {
		Chunk* next;
	};

	class MemoryPool {
	public:
		MemoryPool() {};
		MemoryPool(std::size_t chunks_per_block) : m_chunk_num(chunks_per_block) {};

		void *Allocate(std::size_t size);
		void deallocate(void *chunk, std::size_t size);

		/* Disable copy, copy-assignment, move and move-assignment */
		MemoryPool(const MemoryPool& alloc) = delete; //copy constructor
		MemoryPool& operator=(const MemoryPool& rhs) = delete; // copy-assignment operator
		MemoryPool(MemoryPool&& alloc) = delete;//move constructor
		MemoryPool operator=(MemoryPool&& rhs) = delete; // move-assignment operator
		
	private:
		std::size_t m_chunk_num = 0; // Number of chunks in pool
		Chunk *m_malloc = nullptr;

		Chunk *allocateBlock(std::size_t chunkSize);
	};
}