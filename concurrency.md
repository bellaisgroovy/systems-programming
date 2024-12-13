#concurrency 

# questions

 - what coordination is required for concurrent programming?
 - what are the trade-offs of using higher level concurrency?
 - what are user vs kernel threads?
 - what is strong vs weak scaling?

# recall

- concurrent programming requires coordinating partitioning, placement, communication, and synchronisation
- using a higher level language's concurrency features is simpler and less prone to errors but usually less efficient
- a kernel thread is a thread managed by the OS which can run on its own core at the same time as other kernel threads, whereas a user thread is a thread managed by a language which must run on the same core. user threads are also known as green threads
- strong scaling is where the same problem runs twice as fast with double the resources. weak scaling is where a problem double the size runs the same speed on double the resources.

# notes

- coordination required for concurrent programming
	- partitioning
		- deciding how program should be split to different threads
	- placement
		- deciding which threads should be executed where
	- communication
		- what data to send when
	- synchronisation
		- allowing threads to work together without interfering with each other
		- eg
			- mutexes protect shared data
			- slower threads can force faster ones to wait
- high level languages abstract away things (including coordination), often leading to less efficient but easier to write and understand code
- green threads
	- user threads
		- are managed entirely by the language
		- threads that run on the same core
		- processing time must be interleaved by language through cooperative or preemptive methods
			- eg first in first out or round robin
		- pros
			- lightweight compared to creating/destroying kernel threads
			- independent of OS
			- easy to use
		- cons
			- will not run parallel
			- if no pre-emption, there is blocking
			- if thread waits on IO, the OS will set it (and all other in that kernel thread) to waiting
- kernel threads
	- threads that are managed by the operating system
	- can run on many cores
	- pros
		- runs in parallel
	- cons
		- more expensive to start
- performance depends massively on workload and execution environment
	- ram
	- cores
	- program
	- data
- scaling
	- strong scaling
		- fixed load, differing resources
		- ideally: runtime scales linearly with resources
			- double the resources, half the runtime
		- has diminishing returns
	- weak scaling
		- differing load and resources
		- ideally: twice the resources run twice the load, in the same runtime
		- does not have diminishing reutrns
	- limits
		- Amdahl's Law
		- $s_{total} = \frac {1} {(1-p)+ \frac p s}$ 
			- $s_{total}$ = runtime
			- $p$ = fraction of the program that benefits from parallelization
			- $s$ = number of cores used
			- as $s$ approaches infinity, $\frac p s$ approaches 0, and benefit becomes less noticeable 