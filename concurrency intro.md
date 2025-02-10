	#concurrency 

# questions

- what are the advantages of concurrency?
- what is parallelism?
- what is the difference between a thread and a process?

# recall

- concurrency allows multiple programs to run on one core, speeds up execution and increases ability to work with large loads
- parallelism is multiple process running simultaneously, not interleaved
- processes vs threads
	- threads are cheaper to make than processes
	- may be a different scheduler betweem different threads
	- processes crash individually, whereas one thread crashes all other threads
	- processes limit information sharing
	- processes can be more convenient to use

# notes

- why concurrency?
	- share resources between programs on one core
	- takes advantage of parallel hardware and speeds up
	- scaling to take more requests
	- processors have many cores now so get used to it
- processors
	- von neuman machine takes instructions and data from memory and does it
	- multi-core processors have many Arithmetic Logic Units
		- to take advantage of this you need special programming often in the application layer
- clusters
	- many computers in a network
	- running a program across many computers is also concurrent
- concurrency
	- multiple actions in progress at the same time
	- requires
		- scheduling
		- synchronisation
- parallelism
	- multiple actions executing at the same time
	- requires 
	- parallel hardware, 
	- concurrency support 
	- communication
- concurrency support types
	- shared memory
	- message passing
- threads of processes
	- a single threaded process has one thread it runs on entirely
	- a multi threaded process has multiple threads accessing the same code, data, and files while each one has its own stack and registers
		- so each thread can be at a different point in execution
- processes vs threads
	- threads are cheaper to make than processes
	- may be a different scheduler betweem different threads
	- processes crash individually, whereas one thread crashes all other threads
	- processes limit information sharing
	- processes can be more convenient to use
