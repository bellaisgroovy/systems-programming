#concurrency  #C 

- posix is one way of doing threads
	- pthreads is the name of a C library
- operations / interface
	- everything starts on a main thread and then you fork off work to toher threads and join back later and so on
	- create
	- wait
		- for another thread to terminate
	- cancel
		- another thread
	- terminate
		- calling exit or finishing main function
	- communication 
		- between threads happens with share memory