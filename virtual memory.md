#memory 

# recall

- how does linking work?

# summary

- you compile each module, then concatenate them and move around the addresses within them to match their new positions
# notes

- linking
	- linking is using multiple modules of code together
		- eg importing or including libraries
	- how
		- compile all modules as if they were loaded at position 0
		- concatenate all modules, moving their addresses accordingly
- memory address space
	- each process gets its own virtual memory space with its own address space
		- in program x, address 0 is a different address than program y's address 0
	- options to ensure a program only uses its own memory
		1. maintain base and limit register and each time program tries to get from memory, ensure address is between base and limit
		2. split memory into fixed size spaces for programs
			- if a program doesn't use its whole space this is **internal fragmentation**
		3. split memory into variably sized partitions
			- eventually will **external fragmentation** and leave gaps between address spaces
		4. segments
			- many mini address spaces as to allow non contiguous space per program