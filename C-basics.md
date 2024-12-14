#part-1 #C

- `int main()`
	- entry point
	- return 0 means normal
	- return non 0 means something weird happened
	- you *should* explicitly return 0
- `printf(someString)`
	- prints values
	- `%` symbol is like `{}` in python f-strings
		- `printf("hi %name", "Jim")` -> hi Jim
		- in` stdio.h` library
- `#include <someFilename.h>`
	- instructs the linker to add contents to file
	- `#include <filename.h>`
	- common libraries
		- `stdio.h`
		- `stdlib.h`
		- `string.h`
		- `limits.h`
- variables
	- reference assigned to a point in memory
	- has a datatype
	- `int variable;`
- data types
	- C is statically typed, functions and variables need a type to exist
- variable declarations
	- `typedef int whole_number`
	- now `whole_number` is an alias for `int`
- `#define PI 3.14159`
	- defines a constant
	- in pre-compilation, every `PI` is replaced with `3.14159`
- `const long debt = 120,000`
	- defines a constant
	- typed
	- stored in memory
- statement
		- an instruction that does something
- `break`
	- break out of nearest loop
- `continue`
	- skip to next iteration in loop
- `switch (expression) { case value1: f(x);}`
	- like an if statement
- `int data[3];` or `int data[] = {3, 7};`
	- stores fixed number of elements of the same size
	- accessed by name and index
	- size can be **manually** changed
	- can be multi dimensional
		- `int array[6][4]`
	- char arrays are strings
		- they must end with `\0` (but that is automatically part of a string literal)
- Strings
	- char arrays that end with `\0`
	- manipulated with string.h library
- `struct point { int x; int y; };`
	- like classes
	- data structure that combines multiple elements of any combination of types
	- can access members like `instance_of_point.x`
	- unless you use typedef, you must say `struct point` when referencing this structure
- functions
	- `type name(type name) { body }`
	- function declarations
		- the interface of a function, what it takes, and what it returns
		- abstract implementation
		- `type name(type name);` notice no body
	- function calls
		- functions aren't executed until they are called
		- when function are called, they are added to the stack
		- will go back to previous element on stack once function has completed
- value vs reference
	- difference
		- if you pass a reference, you pass the memory location
		- if you pass the value, you pass an actual value
		- if you edit a value passed by reference, the value is changed everywhere it is accessed
	- functions in c take parameters as values
		- apart from arrays which just get a reference to the start of the array (because really they are a `pointer` to the first element)
- lexical scopes
	- contained in `{}`
	- variable names must be unique inside each lexical scope
	- where variable names shadow other variable names, the innermost is taken
- variable lifetime
	- variables are stored in the same place until their lifetime ends
	- there are 3 ways a variables lifetime can end
		- automatically
			- declared inside a block/scope, lifetime ends at the end of that scope
			- lives on the stack
		- static
			- declared with `static` keyword
			- lives outside of their scope, lifetime ends at the end of the program
			- anything at any point in the program can edit it
			- lives on the stack
		- allocated
			- explicitly requested memory
			- lifetime ends when it is manually ended
			- lives on the heap
- make
	- builds just source files that have changed (like maven)
- pointers
	- memory has an address and a space
		- value(s) go in that space
	- `&y`
		- the memory location of y
	- `int * x`, x is the memory location of an integer
		- `float* z`, z is the memory location of a float
	- `*x = 0`, set the value at the memory address x to 0
	- `const`
		- `const float * ptr`
			- the value pointed to is constant
		- `float * const ptr`
			- the address stored in the pointer is constant
		- `const float * const ptr`
			- both
	- NULL
		- if you dereference a value (`*x`), and it is NULL, then there will be an error
	- pointer arithmetic
		- changing the value of a pointer manually
		- allowed modifications
			- add/subtract integers to/from pointer
			- subtract pointers from each other
			- compare pointers
		- `int * i_ptr = &i;`, `i++` increments by size of one int (4 bytes)
	- structs
		- if you hold pointers in a struct you can implement many different data structures
- command line arguments
	- `int main(int argc, char* argv[]) {...}`
		- `argc` is no of arguments in `argv`
		- `argv` is an array of command line arguments
- `void *`
	- generic, just points to a memory point with no sense of what is there
	- 