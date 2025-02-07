#past-paper #revision
SCORED 39/60, 65%, C(?)

1a)
```C
int matrix[40][20]

matrix[19][0]
matrix[18][20]
```
WRONG 1/2 `matrix[no of rows][no of columns]` and you need to express the address of the first element in the 20th row, not the value.

```c
&matrix[19][0]
matrix[19]
```

1b)
3?

WRONG 0/2 not sure why TODO

1c)
i) int
ii) double
iii) float
iv) char

CORRECT 4/4

1d)
```c
char** sub_str(char* str int idx);
```
WRONG 2/4
```
char ** sub_str(char*, int);
```
1e)
i) just the size of the pointer, an int, which is 4 bytes
WRONG 0/2
ii) 
```
address of name + size of name +
address of address + size of address +
int + int + int + float

int + 11*char
+int + 40*char
+int + int + float

4+11
+4+40
+4+4+4

15+44+12

15+66

81 bytes
```
WRONG 0/2

1f) false CORRECT 1/1
1g) true CORRECT 1/1
1h) 
```c
int has_ch(char ch, char* line) {
	//iterate through line checking for char
	// if char present then return 1
	// else return 0
	for (int i=0; i<size_of(line); i++) {
		if (line[i] == ch) {
			printf("%s", line);
			return 1;
		}
	}
	return 0;
}
```

WRONG 8/10, code is not elegant

2.
a) 4 WRONG -1/2 a list of open files is not in the state otherwise why have synchronisation.

==There is not however, one program counter per process, there can be many threads each with their own program counters==
b) 1 CORRECT 2/2
c) 2 CORRECT2/2
d) 2 CORRECT2/2
e) 3 CORRECT 2/2 but why is 4 not technically correct

3.
a)
One reason to use multiple processes for implementing one application is parallelisation. You could run the different processes of the same application simultaneously to achieve greater efficiency, especially in CPU bound applications.

Another reason to use multiple processes is scalability. You could run multiple instances of one application to handle more requests in a web server for example.

Resilience? one process crahses another can keep running.

WRONG 3/4 scalablity is not a stated reason in marking instructions, resilience is mentioned but you didn't explain it well so 1/2 for that answer

b)
execution order (by line number):
2, 3, 6
result:
x = 12
y = 12

execution order (by line number):
2, 6, 3
result:
x = 12
y = 16

execution order (by line number):
6, 2, 3
result:
x = 16
y = 20

CORRECT 4/4

c)
i)
Thread one and thread two could both access line 4 at once. Then they would both have their own, unlinked version of `calls_before`. now both of them will add 1 and return that value. since they both started with the same value and added one, they will both return the same value. This means that although `count_calls()` was called twice, `total_calls` will only increment by one.

CORRECT 2/2

ii)
The total calls will be less than the actual number of calls.

CORRECT 1/1

iii)
lines 4 to 6 are problematic because they access a shared resource without any kind of synchronisation. Therefore, they create a race condition.

WRONG 0/2 although mentioned synchronisation and shared resource, did not mention critical section, the return value (line 6) is not problematic

d)
mutual exclusion means that only one thread can access a shared resource at a time. The mutex related functions in the `pthread` library can be used to realize it. These functions are `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`,  and `pthread_mutex_destroy`

WRONG 1/2 mentioned shared resource but not critical section

e)
virtual memory allows the utilization of paging. This means that memory can be used more efficiently with less unused space. If you don't use paging then you need contiguous blocks to store large data, which leaves any gaps that arent big enough unused.

virtual memory also increases security as it keeps track of which programs are allowed to access which parts of memory, so if they try to access memory they aren't allowed to they get a segmentation fault.

CORRECT 2/2 although paging wasn't mentioned, I am confident it is a benefit. A more typical answer like "physical addresses can change without virtual ones having to for defragmentation." Would have been better

f)
caching is storing data which is likely to be accessed in faster memory to decrease lookup time - and increase speed of execution.

CORRECT 1/1

g)
the fastest is usually registers.
the slowest is usually disk.

WRONG 1/2 asked for largest, not slowest.