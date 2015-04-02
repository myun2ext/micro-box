#ifndef __MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__
#define __MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__

template <typename T>
struct heap_allocator
{
	T* ptr;
	void allocate(unsigned long size) { ptr = new T[size]; }
	void deallocate(unsigned long size) { delete[] ptr; }
};

struct spec_on_standard_system
{
	typedef heap_allocator<char> MemoryAllocator;
};

template <
	unsigned long Size,
	typename Spec
>
class machine
{
	typename Spec::MemoryAllocator memory;
public:
	machine() {
		memory.allocate(Size);
	}
};

#endif//__MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__
