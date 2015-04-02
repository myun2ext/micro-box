#include <stdio.h>
#include "machine.hpp"

int main()
{
	machine<10, basic_machine_spec> m;
	m.memory[3] = 3;
	printf("%d\n", m.memory[3]);
	return 0;
}
