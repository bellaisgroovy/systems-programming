# recall

- what is the difference between a page and a page frame?
- what is the page table
- what is in the page table
- why is it ok that the paging requires two lookups per lookup?
- what is a page fault
- what is page replacement

# summary

- a page frame is a slot in the page table for a page, a page is a fixed size partition of the address space
- the page table keeps track of where pages are
- the page table contains (at minimum) the real address of a page and the resident bit to indicate if page is loaded in memory
- paging requires two lookups per lookup but caching is used to make page lookups on average very fast
- a page fault is when you try to access a page but it isn't loaded yet so you need to wait for disk
- page replacement is when you move pages out of the cache to make way for new ones - the pages are still stored but just in slower memory.

# notes

- a method of memory virtualization and allocating memory to processes
- page
	- equally, fixed size partitions of the address space
- page table
	- for each address space
	- entries are of page frames
	- entry contains
		- resident bit indicates whether page is in page frame right now
		- frame address indicates reall address of page frame
	- ==ahhhhhh==
- perforamance considerations
	- page table is managed by the operating systems but most hardware CPU's support it and have special registers for it
	- virtual memory requires two lookups per lookup
		- but page table is stored in special cache (Translation Lookaside Buffer) which is very fast and on CPU
	- page tables are per process so switching process is expensive as TLB must be reloaded
	- shared pages
		- expensive to copy processes and copying parent's address space
		- so only copy entries when they change (copy on write)
	- demand paging
		- pages are kept on disk
			- there can be lots
		- only load pages into memory when they are accessed
		- use resident bit from page table to know when to load pages
		- page faults
			- when page has to be loaded
	- page faults
		- less page faults -> much faster
			- when many many page faults performance decreases by factor of thousands
		- page replacement
			- when no empty page frames in memory, must replace page with another page
				- and store that page in disk
			- use some algorithm to decide which page won't be needed
			- usually constant process frees frames so there are always some free frames