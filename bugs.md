#C #part-1 

# recall

- what are the two categories of error?
- what causes a segmentation fault?
- what is a debugger?
- what is static analysis?
- what is dynamic analysis?

# summary

- syntax errors are when code does not follow the syntax of the language, semantic errors are when code leads to erroneous outputs.
- a segmentation fault is caused by the OS shutting down a program that tries to access memory outside of its permissions
- a debugger is a tool that lets you step through a programs execution
- static analysis is analysis of code without running it, like type checking. This does not catch runtime errors.
- dynamic analysis is analysis of code while it is running. 
# notes

- when errors happen
	- syntactical errors
	- semantic errors
		- when the program runs but the output is wrong
- segmentation fault
	- thrown by OS when trying to access restricted areas of memory
	- causes
		- dangling pointers
			- pointing to de-allocated memory
		- dereferencing null
		- buffer overflow
            - accessing memory out of bounds
            - like accessing an index greater than (len(array)-1) in an array
		- stack overflow
            - writing outside of allocated memory
            - often from recursion
		- heap overflow
            - memory leak
- debugger
    - step through programs
    - most popular are GDB and LLDB
- static analysis
    - analyses code without executing it
    - type checking and the like
    - examples
        - compilers
        - linter
- dynamic analysis tools
	- address sanitizer
	    - tools that run the program and analyse results
	    - finds
	        - out of bounds memory
	        - user after free
	        - double free 
	        - eg
    - memory sanitizer
	    - detects uninitialized reads from memory
	- leak sanitizer
		- checks for leaks
	- undefined behaviour sanitizer
		- checks for things that may lead to behaviour you didn't expect
		- finds
			- integer overflows
