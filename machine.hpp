#ifndef __MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__
#define __MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__

#include <memory.h>
#include <stdio.h>

template <typename T>
struct heap_allocator
{
	T* ptr;
	unsigned long size;
	void allocate(unsigned long allocate_size) {
		ptr = new T[allocate_size];
		size = allocate_size;
	}
	void deallocate() { delete[] ptr; }

	T& operator [](unsigned long n) { return ptr[n]; }
	const T& operator [](unsigned long n) const { return ptr[n]; }

	size_t write(const T* from_ptr, unsigned long write_address, unsigned long length) {
		memcpy(ptr + write_address, from_ptr, length);
	}
	bool save_to_file(const char* filename) const
	{
		FILE* fp = fopen(filename, "w+b");
		if ( fp == NULL ) return false;
		return fwrite(ptr, sizeof(T), size, fp) == (size * sizeof(T));
	}
};

struct spec_on_standard_system
{
	typedef heap_allocator<char> MemoryAllocator;
};
typedef spec_on_standard_system basic_machine_spec;

template <
	unsigned long Size,
	typename Spec
>
class machine
{
public:
	typename Spec::MemoryAllocator memory;
	machine() {
		memory.allocate(Size);
	}
	virtual ~machine() { memory.deallocate(); }
};

#endif//__MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__
