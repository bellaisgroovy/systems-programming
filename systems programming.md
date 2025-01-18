#part-1 

# recall

- what entities are systems programs written for?
- why are systems programs written in systems programming languages?
- what was the motivation for creating C
- what does a compiler do?
- what are the steps of the C compiler?

# summary

- systems programs are written for other programs, they aren't applications
- systems programs are written in systems programming languages so that they are more performant and can make use of fine control
- the motivation for creating C was two people in the 80s wanting to port UNIX from one architecture to another
- a compiler turns human readable code into machine code
- the C compiler does 4 steps when compiling
	- pre-processing
		- all the # things at the start
		- macros
		- file inclusion - this function comes from this file
		- ==conditional compilation==
			- compiling if statements including skipping compilation of branches that will never be picked
		- other stuff
	- intermediate representation
		- this is basically assembly but not for a specific architecture
		- easy to translate to other architecture specific assembly so less work must be done for each type of architecture you want to support
	- assembly
		- architecture specific
	- machine code
# notes

- what is systems programming?
	- software for other software
	- not application software
- has performance constraints
	- so systems programming languages are used because they give more control
- history
	- until the 70s, there were only architecture specific languages
	- when people wanted to port an operating system from one architecture to another they made C
		- C is an abstraction above architecture languages
	- in 1983 ANSI standardized C
	- in 1980 C++ was created which is Object oriented
	- Rust is another systems language, Swift is apples system language
		- notably both C and Rust were created as passion projects
- why C?
	- few keywords
	- portable bc standards
	- versatile
	- builds understanding
- compilers
	- translate C (or any other language) into machine code
	- C compiler steps
		- start with C
		- move to intermediate language that isn't quite assembly as it is architecture independent
		- move to architecture specific assembly
		- move to machine code