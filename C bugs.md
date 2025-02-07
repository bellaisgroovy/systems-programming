**Dangling Pointer**
Pointing to de-allocated memory. Can cause segmentation faults if the memory is outside of programs remit, or unexpected behaviour if it points to a random value in control of the program.

```c
int* initaliseInteger(int val) {
	int x = val;
	int* ptr = &x; // in stack memory
	return ptr; // dangling pointer
}
```