#spacey #concurrency 

[[spacey language options]]
I will compare Java, C++, and Ada.

# C++

Memory management in C is split in two parts: the heap, and the stack. The heap is manually managed memory which the programmer is responsible for allocating and freeing. The stack is automatically managed based primarily on lexical scope and function calls.

Concurrency and synchronisation means:
- pthreads
	- low level
	- easy access to synchronisation primitives
- `unistd.h` / standard C library
	- Unix specific
		- if using wind river real time Linux should work

for the project:
- the team knows it already
	- quicker production timeline
	- higher quality product
	- less resources in acquiring skills
- low level
	-  really efficient
		- running things in space is expensive
			- you should minimise things running
			- your programs that run should be efficient so that they are less
	- very fine grained control of operation and memory
		- less chance of undesirable behaviour from language
		- more predictable
	- harder to program
		- slower turnaround
		- possibility of low level bugs
			- segmentation faults
			- overflows
			- ...
- old established technology
	- reliable
	- bugs in C are unlikely to cause mission failure
- excellent concurrency support
	- many sensors and processes need monitored in near real time, so they must be concurrent
	- access to synchronisation primitives
	- multi threading
		- real parallelism
			- many things can actually run at the same time
		- takes advantage of hardware fully
			- its expensive to put things in space, you should utilize them
- modular and object oriented
	- easier to add more functionality later on
		- requirements are likely to change so software has to flexible

# Java

Memory management in java is automatic. Space is automatically allocated for you and freed cyclically by the garbage collector.

The ==JVM== splits the memory into multiple sections. The main sections are the stack area, method area, and  heap area, although there are other very important areas. 

The stack area is where method calls and their stack frames are stored. When a method completes, its stack frame is destroyed. 

The method area is where metadata about classes is stored. It contains the names, super classes, constructors, interfaces names, and constructors of each class.

The heap area is comparable to the heap in C and is where object's data is stored. It categorises objects based on how long they have existed.

The garbage collector is primarily concerned with the heap area. It frees differently sized and aged objects in separate cycles. There are frequent minor cycles which free small, new objects, then less frequent major cycles for old or especially large objects.

Concurrency and synchronisation means:
- built in Thread and Runnable
- ==Process class and ProcessBuilder==

for the project:
- the team knows it already
	- quicker production timeline
	- higher quality product
	- less resources in acquiring skills
- high level
	- quicker development
		- cheaper
		- easier to change requirements down the line
	- less chance of memory leaks or other low level bugs
		- more reliable software which is important in space
	- less efficient to run in practice
		- overhead in space is not cool
- excellent concurrency support
	- many sensors and processes need monitored in near real time, so they must be concurrent
	- access to synchronisation primitives
	- multi threading
		- real parallelism
			- many things can actually run at the same time
		- takes advantage of hardware fully
			- its expensive to put things in space, you should utilize them
- modular and object oriented
	- easier to add more functionality later on
		- requirements are likely to change so software has to flexible

# Ada

