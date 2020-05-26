#include "MemoryPool.h"
#include <iostream>


void *Core::Memory::MemoryPool::Allocate(std::size_t size) {
	if (m_malloc == nullptr) {
		m_malloc = allocateBlock(size);
	}

	Chunk* free_chunk = m_malloc;
	m_malloc = m_malloc->next;
	return free_chunk;
}

void Core::Memory::MemoryPool::deallocate(void *chunk, std::size_t size) {
	reinterpret_cast<Chunk*>(chunk)->next = m_malloc;
	m_malloc = reinterpret_cast<Chunk*>(chunk);
}

Core::Memory::Chunk* Core::Memory::MemoryPool::allocateBlock(std::size_t chunkSize) {
	std::cout << "\nAllocating block (" << m_chunk_num << " chunks):\n\n";

	std::size_t block_size = m_chunk_num * chunkSize;
	Chunk *block_begin = reinterpret_cast<Chunk*>(malloc(block_size));
	Chunk *chunk = block_begin;

	for (int i = 0; i < m_chunk_num - 1; ++i) {
		chunk->next = reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + chunkSize);
		chunk = chunk->next;
	}

	chunk->next = nullptr;
	return block_begin;
}
