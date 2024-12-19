#spacey 

# Introduction (short)

# Java
## Memory Management

- Java's memory management is automatic, which reduces code complexity and development time
- When using Java, memory is split into areas by the JVM
- The stack area is where method calls and their stack frames are stored. When a method completes, its stack frame is destroyed. 
- The method area is where metadata about classes is stored. It contains the names, super classes, constructors, interfaces names, and constructors of each class.
- The heap area is where object's data is stored.
- The garbage collector free's space in the heap. It frees differently sized and aged objects in separate cycles. There are frequent minor cycles which free small, new objects, then less frequent major cycles for old or especially large objects.
## Concurrency and Synchronisation

- Java has high level concurrency means which makes programming simpler but doesn't remove the possibility of deadlocks and mistakes
- To create a new thread use the `Thread` class, which implements the `Runnable` interface. This design separates business logic from synchronisation logic, again making programming simpler.
- Java's threads are typically system, OS managed threads, so they have more overhead but can speed up CPU bound problems by running in parallel.
- There are many diverse, high level synchronisation options built in to Java which simplifies concurrent programming and reduces development time.
- The `Synchronised` keyword denotes a critical section that only one thread is allowed to enter at once.
- `wait()` is a method of `Thread` that pauses its execution. `notify()` is called from another thread to tell the waiting thread to resume. This is a very imprecise method of synchronisation.
- Semaphores are a synchronisation primitive built into java that tracks and controls the number of threads in one shared resource.
- A countdown latch lets a number of tasks complete (tracked by a countdown) before a shared resource is available
- A cyclic barrier sets a point in multiple threads and pauses each when they reach it until all threads have reached it
- A stamped lock differentiates between readers and writers. It allows only one thread access when it is writing, but when threads are reading, lets many have access.
- `ProccessBuilder` can spawn new OS-managed processes which require a new JVM to be created and incurs lots of overhead.
- The wide variety of synchronisation options offer many already implemented solutions for many different problems the team might face, which reduces development time.
# C

## Memory management

- Memory management in C is split in two parts: the heap, and the stack. 
- The heap is manually managed memory which the programmer is responsible for allocating and freeing. This system is efficient but incurs development overhead and allows for errors like dangling pointers.
- The stack is automatically managed based primarily on lexical scope and function calls.

## Concurrency and Synchronisation

- C has low level synchronisation means which incur less overhead but adds development time
- `pthreads` are part of the `unistd.h`, standard C library that works on UNIX like machines. 
	- I think that a UNIX based real time OS is suitable for the satellite because some calculations will be used for real time adjustments which are sensitive to delays.
- threads are manually started with  `pthread_create`, and waited on with `pthread_join`
- information can be passed into and returned from threads at creation and joining, including pointers to shared data in the heap which gives developers fine grained control over data but the responsibility of managing pointers which takes development time
- C uses semaphores to control access to shared resources. Semaphores are synchronisation primitives that can be used to implement higher level synchronisation concepts. This will give the team more control to make more efficient programs, but incur more development time
- Semaphores work by keeping a value which represents the number of threads accessing a resource and giving other threads access based on that.
- Semaphores are interacted with by calling the family of functions `pthread_mutex_` `init`, `lock`, `unlock`, and `destroy`.

# Python

## Memory management

Python memory management on the object level is organised with 3 levels of storage: arenas, pools, and blocks. Arenas are held in a dynamically sized list and freed when they are empty. The less arenas there are, the less memory a python program uses. Each arena contains pools, and each pool contains blocks of a single size. 

When some object is created, first it finds an arena, the most filled arenas are used first to more fully utilize memory. Next it finds a pool suitable for its size. If there are no partially full pools of its size, an empty pool is made the correct size and used. Finally, a block inside that pool is allocated to store the object.

## Concurrency and Synchronisation

- Python has many libraries for concurrency, but I will discuss `asyncio`, `threading`, and `multiprocessing` because they are common and well established.
- Use of a high level concurrency library simplifies development and saves time, but has a negative effect on performance
- `asyncio` uses co-routines that are cooperatively scheduled, which has very little extra overhead, however since its co-routines aren't managed by the OS, they can't run in parallel.
- `threading` creates real threads which are preemptively scheduled by the OS to pause when waiting for something like IO. This reduces the complexity of manually scheduling but has substantial performance costs.
- threads created by the cpython interpreter do not run in parallel because of the Global Interpreter Lock which is like a mutex that controls thread's accessing to the interpreter, only letting one run at a time.
- `multiprocessing` spawns new processes, with their own interpreters which can run in parallel, however starting a new interpreter is a very expensive operation, and in regards to the software for the satellite, not worth it.
- In IO bound problems, like a satellite speaking to its sensors, parallelism doesn't offer much speed up because computing time isn't the bottleneck. Therefore it would be best to use `asyncio`.
- To share data between threads in python there are thread-safe objects such as queue which can be used. Global variables holding thread safe objects is a relatively easy way to share data and saves time in development.

# Comparison and Recommendation

- The main requirements for the satellites software are great efficiency, and excellent support for concurrency. These properties will allow it to use its 1326 sensors to make measurements and inform constant real-time adjustments.
- In a programming language, potential for efficiency comes in the form of fine grained control, but at the cost of complexity and development time
- Development time is an important consideration  due changing requirements at SpaceY, but ultimately is secondary.

- The satellites software will be most efficient if it is written in C due to the high level of control it offers and low overhead it incurs.
- Although Python's co-routines are notably a better system for the satellites IO bound concurrency, the overhead of the interpreter makes it slower than C overall
- Java has no performance benefits over C

- Java and Python have more and easier to use synchronisation options than C
- Java has the most balance between simplicity and functionality in synchronisation, especially with its many options of locks for different situations, and python is not far behind
- C just has basic building blocks like semaphores, but these are enough to achieve anything Java or Python can with greater efficiency, even if it would take longer to develop

- Programming in C will incur the longest development time. As C is very low level, and not even object-oriented, it will take longer to develop and slower to add changes. 
- Python's relative simplicity of programming would likely yield the least development time.
- Java once again strikes a balance between the two.

- Overall, despite C's complexity, it best meets the satellite software's requirements. It's fine grained, low level control of memory management and concurrency will serve to reliably, and efficiently manage the satellite and all of its sensors.