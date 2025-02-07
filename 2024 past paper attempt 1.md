#revision #past-paper
1ai.


ii.

1bi.
The statement is invalid because w holds the actual data n, not the pointer to it. As such, `->` is not the correct operator.

ii.
`printf("%d", w->n.min);`

iii.
w holds n which holds max. w itself does not hold max, so this statement misses a step by not referencing n between w and max.

iv.
`w->n.max = 999;`

1ci.
The issue is a dangling pointer. It occurs because `ptr` is stored in stack memory, which only persists as long as `initialiseInteger()` does. So once returned, it isn't allocated anymore.

ii.
It will be discovered at run time because there is nothing syntactically wrong with the segment. However when it runs, if something tries to reference the returned pointer, it will cause errors. 

This is also known as a semantic error, where the function of the code is wrong even though it is syntactically valid.

2a.
the pointer p is stored on stack memory.
the value p points to is stored on heap memory.

2bi.
line 18 because `array` holds a pointer to an integer. so once `array[1]` was referenced, it would error

ii.
it wouldn't keep the values because `allocateArray()` allocates a potentially different set of spaces in memory and doesn't put old values in those new spaces.

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

3a.
One reason is parallelism. This means that two cores can run code at the same time, with the right problem, this halves execution time.

Another reason is concurrency. This means that while one thread is waiting on something like IO, another thread can jump in and do computation. This increases utilization and makes programs run faster.

3bi.
multiple threads could enter sell_a_ticket at once, this means that they would run line 4 at the same time and two tickets would have the same ID, furthermore, they would both increment tickets_sold at the same time, meaning that it would only increment by one even though two tickets were sold.

ii.
lines 4 and 5 are problematic because they access a shared resource without any protections like a semaphore and lead to a race condition. A race condition is where the speed of threads running and therefore the order they run in can lead to different results

c.
a mutex is to track and control access to a shared resource. 

`pthread_mutex_lock` to indicate a shared resourse is being accessed and ensure that no other resources are already locked

`pthread_mutex_unlock` to indicate that the thread is done with a shared resource and other threads can use it.

di.
3

dii.
2

4ai.
code, static data, and heap

ii.
stack is specific to a thread, heap is specific to a process

b.
virtual memory. Since the memory is allocated virtually by maintaining a table that holds virtual addresses and real addresses, the real addresses can be on hard drives or elsewhere as well as RAM. As such, a system with 8GB of RAM can use 10GB of memory by storing those extra 2GB outside of RAM.

c.
a process control block (PCB) holds registers so that when a process is reloaded, the registers can go back to how they were when it stopped running.

d.
disks, main memory, caches, registers

ei.
3

ii.
1

iii.
2