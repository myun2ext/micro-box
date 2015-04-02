#ifndef __MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__
#define __MYUN2__GITHUB__MICRO_BOX__MACHINE__HPP__

template <typename T>
struct heap_allocator
{
	T* ptr;
	void allocate(unsigned long size) { ptr = new T[size]; }
	void deallocate() { delete[] ptr; }

	T& operator [](unsigned long n) { return ptr[n]; }
	const T& operator [](unsigned long n) const { return ptr[n]; }
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
