#spacey #concurrency 

[[spacey language options]]
I will compare Java, C, and Python.

# C

Memory management in C is split in two parts: the heap, and the stack. The heap is manually managed memory which the programmer is responsible for allocating and freeing. The stack is automatically managed based primarily on lexical scope and function calls.

Concurrency and synchronisation means:
- pthreads
	- low level
	- easy access to synchronisation primitives
- `pthread_t` is the data structure which holds the information of a thread
- threads are manually started with  `pthread_create`, and waited on with `pthread_join
- C uses semaphores to control access to shared resources. Semaphores are synchronisation primitives that can be used to implement higher level synchronisation concepts. This will give the team more control to make more efficient programs, but incur more development time
- Semaphores work by keeping a value which represents the number of threads accessing a resource and giving other threads access based on that.
- Semaphores are interacted with by calling the family of functions `pthread_mutex_` `init`, `lock`, `unlock`, and `destroy`.
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
- modular
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
	- can be multiple real threads depending on JVM and hardware
- synchronized keyword, wait, notify, notifyall
	- used to communicate between threads
	- very broad and lock or release whole threads instead of individual shared resources
	- synchronized keyword ensures critical code is run one thread at a time, but multiple different bits of critical code could access the same shared resource!
- there are many other more fine grained synchronisation means in java.util.concurrent
	- reentrant lock
		- similar to a semaphore but allows more advanced methods of choosing what thread gets to access critical section next
	- semaphore
		- sychronisation primitive that controls the number of threads in one shared resource
	- countdown latch
		- let a number of tasks complete (tracked by a countdown) before a shared resource is available
	- cyclic barrier
		- sychronise threads, waiting for all to come to some poiint before continuing them all again
	- stamped lock
		- seperate read and write locks
			- many can read
			- one can write
				- none can read while one writes
- ProcessBuilder
	- spawns new processes
	- lots of overhead to create a whole new process with its own JVM

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

# Python

Python memory management on the object level is organized with 3 levels of storage, arenas, pools, and blocks. Arenas are held in a dynamically sized list and freed when they are empty. The less arenas there are, the less memory a python program uses. Each arena contains pools, and each pool contains blocks of a single size. 

When some object is created, first it finds an arena, the most filled arenas are used first to more fully utilize memory. Next it finds a pool suitable for its size. If there are no partially full pools of its size, an empty pool is made the correct size and used. Finally, a block inside that pool is allocated to store the object.

concurrency and synchronisation means:

there are many different libraries for python concurrency but they pretty much all use one of the three methods listed below. I will discuss asycio, threading and multiprocessing
- coroutines
	- `asyncio`
	- lets each coroutine decide when to give up control with keywords await and async
	- fastest for IO bound operations
		- LIKE SENSORS
- threads
	- `threading`
	- OS automatically preemptively pauses threads when waiting on IO or other
- processes
	- `multiprocessing`
	- OS runs each process in its own python interpreter, potentially on its own actual CPU core for real parallelism
	- not actually much speed up for IO bound operations

for the project:
- high level
	- will be quicker to develop and there are less likely to be mistakes while programming
	- almost no chance of low level bugs like memory leaks or segmentation faults
	- easier to make changes to
	- less efficient due to necessary overhead
		- eg garbage collection, interpretation
- interpreted
	- less efficient as it can't be optimized by a compiler
- team knows it
	- reduced development time
	- less resources in training
	- better solution at end since team has prior experience
- modular and object oriented
	- easier to amend later
		- more changes will be needed so chill

- pros
	- multithreaded
	- high level
	- I know it
	- team knows it
- cons
	- high level
		- inefficient
	- interpreted
		- inefficient

![[spacey conclusion]]