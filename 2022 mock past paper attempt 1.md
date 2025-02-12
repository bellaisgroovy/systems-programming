#revision #past-paper 
53/83 63%

1a.
2

WRONG -1/3

doubles are bigger than long ints

b.
1

CORRECT 3/3

c.
3

CORRECT 3/3

d.
4

CORRECT 3/3

e.
1

CORRECT 3/3

f.
2

CORRECT 3/3

g.
3

CORRECT 3/3

h.
4

WRONG -1/3

this was due to wording but copies have different addresses so cannot race condition, tow threads accessing the same memory - editing not just reading - causes a race condition

i.
4

WRONG -1/3

a thread is create and managed by an operating system - even if it is part of a process, green threads are language constructs

j.
4

CORRECT 3/3

2a.
- . not -> at line 10 because it accesses values of a struct at a pointer
	- switch to ->
- -> not . at lines 15 and 16 because it accesses a struct directly, not via a pointer
	- switch to .

CORRECT 7/7

2b.
- `num` not `*num` in lines 4, 5, and 7 because num is a pointer to an int not an int itself
	- use `*num` instead

CORRECT 5/5

c.
- `pthread_exit` has a pointer to a stack variable as an argument at line 13. This pointer will not be able to be dereferenced outside of `printInfo`.
	- put len in the heap with `malloc`
	- replace lines 9 and 10 with:
	- `long int * len = malloc(sizeof(long int));`
	- `*len = strlen(user_input);`
	- and then free it between line 32 and 33 with `free(*lengths[i]);`

CORRECT 7/7

3ai.
In C, the memory is split into the heap and the stakc. The ehap is managed manually by the developer explicitly allocating and freeing memeory. The stack is managed automatically as function calls are made and terminated.

Each process has its own stack and heap, but threads within a process, share heap and stack memory

WRONG 0/4

Each process has a heap which its threads share, however each thread has its own stack as the stack is tied to the lifetime of functions.

ii.
a memory leak cannot happen to stack allocated memory because it is automatically managed and will never lose reference or forget to deallocate memory.  It is also automatically deallocated as soon as its scope is finished.

CORRECT 2/2

stack memory is tied to the lifetime of a function and automatically freed at the end of its lifetime.

iii.
no idea

IGNORE/4

b.
Paging and virtual memory mitigates memory fragmentation by splitting memory into equally, fixed size blocks. Essentially, contiguous blocks of memory are not needed because there is a virtual mapping between real memory and memory addresses as reported to the program. This means that a small part of one programs memory can fit in the small gaps left.

CORRECT 2/2

c.
posix is a standard for threads that applies between most OS's but notably not windows. This means that it is harder to run C programs on a windows machine.

WRONG 3/6

you would use POSIX if you want to use operating system features like starting threads but also wanted portability

POSIX is a standard for threading and processes, file IO, and standard C headers.

a non POSIX standard OS like windows means that POSIX code may not work due to broke APIs. C programs taking advantage of windows must make different OS calls like with a different include statement for `sleep()` for windows.

di.
A race condition is caused by multiple threads simultaneously editing a shared resource (usually by accessing a critical section).

CORRECT 2/2

ii.
The name of the concurrency primitive is a mutex. its misuse can cause deadlock when multiple mutexes are waiting on each other to become free.

For example if there were two shared resources and two threads, each of which had the mutex of one resource, they could both be waiting for the other to relinquish access of the other resource.

CORRECT 2/2

4.
1 this line allocates a block of memory the size of n in the heap. It then returns the address of this block to the `new` pointer.

2 this line checks if r is 0 and if it isn't enters its block.

3 checks if e has the same value as the value in `r->val`. `r->vale` refers to the val property in the struct at the pointer r.

4 this calls c with the pointer r, the integer e, and the integer 0. It creates a 

5 this line is a recursive call to the function `i()` with the l attribute of the struct at pointer r as well as the integer e passed in

`i()` inserts a new value, `e`, into a binary tree, `r` at the correct place.

`c()` creates a new node for the binary tree with the value v. r is a boolean value to indicate if it should be added as the right child or the left child of the node p.

This code will not print anything when run.

WRONG 8/16

should have referenced more than literally what the code did in line explanations.
Should have taken "printing" as the output from the insertion order.

