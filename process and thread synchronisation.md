#concurrency

# questions

- what is a race condition?
- what are the rules for dealing with race conditions?
- what is a semaphore and a mutex?

# summary

- a race condition is when the output of the program depends on which concurrent operations finished first.
- when dealing with race conditions
	- only let one process in a critical section at once
	- vary the process that is let into critical sections
	- don't starve any processes from entering critical sections
- a semaphore is a variable that tracks the availability of a shared resource, it can be used to remove race conditions.
	- a mutex is a semaphore that can only be 0 or 1

# Notes

- race condition
	- result depends on running order of parallel processes
	- only a problem when result is undesirable
- dealing with race conditions
	- a critical section is a section of cdoe where shared resources are used
	- rules
		- don't let more than one process into a critical section at a time
		- let different processes into critical sections rather than always prioritising one
		- no process should wait forever to enter a critical section
	- Peterson's solution
		- have code for each thread
		- have a flag variable for each thread
		- start in each with flag for self as true and turn set to the others turn
		- have a turn variable
		- ensure the flag for the other is false and the turn is set to the others before executing
		- at the end set own flag to false
- semaphores
	- mutexes are a semaphore that can only be 1 or 0
		- method of protecting shared resources
		- mutex is set to 1 when resource is available
			- mutex is set to 0 when not available
		- when trying to aquire mutex, only release after mutex is 1 then immediately set back to 0
			- code that aquired the mutex will run and lock the mutex
		- when releasing mutex, set it to 1
			- code is done with the mutex and the next code trying to acquire the mutex will exit the while loop and get it
	- example problems
		- consumer producer
			- one process adds to a list, another removes from a list, the list can only be accessed by one process at a time
		- readers-writers problem
			- many readers can read variable at the same time. a writer can only write if noone is also reading or writing to the variable at the same time
			- have a read/write mutex, reader count, and a mutex to protect that reader count
	- matters of life and death
		- starvation
			- one process never gets access because of other processes always using it
		- livelock
			- starvation by two processes trying not to starve each other
		- priority inversion
			- lower priority processes starving higher priority ones
		- deadlock
			- multiple mutexes causing each other to wait on each other
			- all parties of a group waiting for ever for another party to take action
- monitors
	- method of temporarily unblocking semaphores based on a condition