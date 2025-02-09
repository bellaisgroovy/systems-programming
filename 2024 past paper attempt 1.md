#revision #past-paper
1ai.
WRONG 0/3
pointers cannot be added to each other


ii.
WRONG 0/3
`middle - start + (end - start) / 2`
only pointer subtraction and adding of integers is taking place here

1bi.
The statement is invalid because w holds the actual data n, not the pointer to it. As such, `->` is not the correct operator.

CORRECT 2/2

ii.
`printf("%d", w->n.min);`

CORRECT 1/1

iii.
w holds n which holds max. w itself does not hold max, so this statement misses a step by not referencing n between w and max.

CORRECT 1/1

iv.
`w->n.max = 999;`

CORRECT 1/1

1ci.
The issue is a dangling pointer. It occurs because `ptr` is stored in stack memory, which only persists as long as `initialiseInteger()` does. So once returned, it isn't allocated anymore.

CORRECT 2/2

it cannot be dereferenced outside of the `intitialiseInteger()` function

ii.
It will be discovered at run time because there is nothing syntactically wrong with the segment. However when it runs, if something tries to reference the returned pointer, it will cause errors. 

This is also known as a semantic error, where the function of the code is wrong even though it is syntactically valid.

CORRECT 2/2
very wordy

2a.
the pointer p is stored on stack memory.
the value p points to is stored on heap memory.

CORRECT 2/2

2bi.
line 18 because `array` holds a pointer to an integer. so once `array[1]` was referenced, it would error

WRONG 0/2
double free on line 25 (but I don't see it)
`int * arr[] = malloc(sizeof(int) * len);` is correct for allocating an array.

ii.
it wouldn't keep the values because `allocateArray()` allocates a potentially different set of spaces in memory and doesn't put old values in those new spaces.

CORRECT 2/2

iii
```c

// replace lines 3 to 10 with below
int * allocateArray(int arr[], int len, int oldLen) {
	int * newArr[] = (int *) malloc(len * sizeof(int));

	if (arr) {
		for (int i=0; i<oldLen; i++) {
			newArr[i] = arr[i];
		}

		free(arr);
		arr = NULL;
	}

	return newArr;
}

//replace line 14 with below
int *array = allocateArray(NULL, size, NULL);

//replace lines 22 to 23 with below
int newSize = 10;
array = allocateArray(array, newSize, size);
```

WRONG 0/4

use realloc instead of copying over things manually.

That said mine would technically work so..

3a.
One reason is parallelism. This means that two cores can run code at the same time, with the right problem, this halves execution time.

Another reason is concurrency. This means that while one thread is waiting on something like IO, another thread can jump in and do computation. This increases utilization and makes programs run faster.

WRONG 2/4

Only mentioned speednig up, not responsiveness, scaling, or convenience.

3bi.
multiple threads could enter sell_a_ticket at once, this means that they would run line 4 at the same time and two tickets would have the same ID, furthermore, they would both increment tickets_sold at the same time, meaning that it would only increment by one even though two tickets were sold.

CORRECT 2/2

should have referenced line 5 for ticets sold

ii.
lines 4 and 5 are problematic because they access a shared resource without any protections like a semaphore and lead to a race condition. A race condition is where the speed of threads running and therefore the order they run in can lead to different results

CORRECT 2/2

say "critical section"

c.
a mutex is to track and control access to a shared resource. 

`pthread_mutex_lock` to indicate a shared resourse is being accessed and ensure that no other resources are already locked

`pthread_mutex_unlock` to indicate that the thread is done with a shared resource and other threads can use it.

WRONG 2/3

It provides mutual exclusion, it ensures only one thread has access to a critical section or shared resource. use those buzzwords girl.

di.
3

CORRECT 2/2

dii.
2

CORRECT 2/2

4ai.
code, static data, and heap

WRONG 0/1

all entire address spaec of a process is accessible to its threads.

ii.
stack is specific to a thread, heap is specific to a process

CORRECT 1/1

b.
virtual memory. Since the memory is allocated virtually by maintaining a table that holds virtual addresses and real addresses, the real addresses can be on hard drives or elsewhere as well as RAM. As such, a system with 8GB of RAM can use 10GB of memory by storing those extra 2GB outside of RAM.

CORRECT 2/2

c.
a process control block (PCB) holds registers so that when a process is reloaded, the registers can go back to how they were when it stopped running.

WRONG 1/2

Must mention that "stopped running" means losing access to the CPU.
Better to say "restores state" than "when a process is reloaded"

d.
disks, main memory, caches, registers

CORRECT 2/2

ei.
3

CORRECT 2/2

ii.
1

CORRECT 2/2

iii.
2

CORRECT 2/2