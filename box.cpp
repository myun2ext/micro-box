#include <stdio.h>
#include "machine.hpp"

int main()
{
	machine<10, basic_machine_spec> m;
	m.memory[3] = 99;
	printf("%d\n", m.memory[3]);
	m.memory.save_to_file("box.dat");
	return 0;
}
