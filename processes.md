#concurrency 
# recall

- what does the process control block do?
- what does the scheduler do?
- what does it mean for a process to be CPU or IO bound?
- where are processes created?

# summary

- the PCBs store information about running programs, like the state of the registers while they are running
- the scheduler moves processes between their running states
- a process is CPU bound if the CPU time dominates the running time
- processes are created inside of parent processes

# notes 

- lifecycle of a process
	- states
		- new
		- ready
		- waiting
		- running
		- terminated
	- transitions between the states especially ready, running, and waiting
- process control block
	- stores information associated with each process
	- stores their 
		- state, 
		- number 
		- program counter 
		- registers 
		- memory limits 
		- list of open files
		- other
- process creation
	- parent processes create child processes
		- like `pthread_create` in C
	- execution options
		- let parent and children execute concurrently
		- make parent process wait for child process to terminate
	- since parents make children, processes can be represented as a tree
- processes can be io or cpu bound
	- cpu bound
		- if the speed of the cpu dominates the running time, it is cpu bound, 
	- io bound
		- if the speed of reading writing io dominates running time it is io bound
- process scheduling
	- maximize cpu utilization
	- eg round robin
	- uses queues to track processes
		- job queue
			- all processes
		- ready queue
			- all rpocesses in memory which are ready
		- device queue
			- all processes waiting on a given device
			- eg printer queue waits to run printing on the printer
	- styles
		- preemptive scheduling stops processes
		- non-preemptive scheduling just waits for processes to stop themselves
- dispatcher
	- lets processes control the CPU
	- responsibilites
		- switch context
			- load registers
			- load the PCB with process data
		- switch to user mode
		- jump to instructions in user programs 