Matriculation Number: 2770706H
Name: Bellatrix Hodgson
# Introduction

The choice of programming language is an important factor in designing software for a space-based solar power satellite. The main requirements for the satellite software are efficiency and excellent support for concurrency. These properties will allow it to use its 1326 sensors to make measurements that inform constant real-time adjustments. The non-functional requirements of the software are that it must be maintainable, and economical to develop. This report will compare the suitability of Java, C, and Python in terms of their memory management, and concurrency features in relation to the satellite's requirements.

# Java

## Memory Management

Java's memory management is automatically managed by the Java Virtual Machine (JVM) which reduces code complexity and development time. The JVM splits memory into three areas:
1. **Stack Area:** The stack area is where method calls and their stack frames are stored. When a method completes, its stack frame is destroyed. 
2. **Method Area:** The method area is where metadata about classes is stored. This metadata includes the names, super-classes, constructors, and interface names of each class.
3. **Heap Area:** The heap area is where the actual data of objects is stored.

The Garbage collector is responsible for freeing redundant data in memory. It frees differently sized and aged objects in separate cycles. There are frequent minor cycles which free small, new objects, then less frequent major cycles for old or especially large objects. As these cycles are controlled by the JVM, not the developer, they can lead to unpredictable pauses which is problematic for the real-time processing needed by the satellite.

## Concurrency and Synchronisation

Java takes a high-level approach to concurrency which makes concurrent programming simpler, although it doesn't remove the possibility of concurrency issues like deadlocks.

Creating and calling a Thread object is how threads are created in Java. This design simplifies programming by separating business logic concurrency management.

Java has lots of built-in synchronisation tools. The synchronised keyword protects critical sections from multiple threads simultaneously accessing them. Threads can pause and resume each other with the `wait()` and `notify()` methods. There are also a variety of advanced locks like semaphores, countdown latches, cyclic barriers, and stamped locks which offer fine-grained control for complex synchronisation logic.

While Java's concurrency tools are strong, their ease of use necessitates some overhead behind the scenes. Regardless, the many options offer flexibility and speed while developing.

# C
## Memory Management

In C, the memory is split into the heap and the stack. The heap is managed manually by the developer explicitly allocating and freeing memory. The stack is managed automatically as function calls are made and terminated. Although this leaves the possibility of memory leaks or dangling pointers and requires more attention to detail, it offers very high performance.

## Concurrency and Synchronisation

C's concurrency management is more basic than Java's, but it contains all the same fundamental parts. It uses the standard library to create Portable Operating System Interface (POSIX) standard threads which work on UNIX-like machines. Thread's life cycles are more explicitly managed. The programmer must create, start and wait on threads, but once created they are real threads managed by the OS.

Synchronisation is managed with semaphores. A semaphore represents the availability of some shared resource or critical section of code. Multiple semaphores can be used in creative ways to manage complex synchronisation. As with everything, the greater control and performance this permits comes at the cost of complexity and development time.

# Python

## Memory Management

Python memory management on the object level is organised with 3 levels of storage: arenas, pools, and blocks. Arenas are held in a dynamically sized list and freed when they are empty. The fewer arenas there are, the less memory a Python program uses. Each arena contains pools, and each pool contains blocks of a single size. 

When some object is created, first it finds an arena, the most filled arenas are used first to more fully utilize memory. Next, it finds a pool suitable for its size. If there are no partially full pools of its size, an empty pool is made the correct size and used. Finally, a block inside that pool is allocated to store the object.

As with Java, this means that the developer doesn't need to be concerned with memory management, but incurs overhead.

## Concurrency and Synchronisation

Python has many libraries for high-level concurrency, but I will discuss `asyncio`, `threading`, and `multiprocessing` because they each have unique strengths and are commonly used.
- `asyncio` uses co-routines that are cooperatively scheduled, which has very little extra overhead
- `threading` creates real threads which are preemptively scheduled by the OS to pause when waiting for something like IO. This reduces the complexity of manual scheduling but has substantial performance costs.
- `multiprocessing` spawns new processes, with their own interpreters which can run in parallel, however starting a new interpreter is a very expensive operation.

Of these libraries, only `multiprocessing` allows for parallelism because one Python interpreter can only run one section of code at a time due to the Global Interpreter Lock (GIL). However, as the satellite is IO bound, `asyncio` with its low overhead co-routines is still faster.

# Comparison

## Efficiency and Concurrency

The satellite software must handle real-time data from its 1326 sensors to operate critical systems like course correction where delay can mean catastrophic failure.

C offers the highest performance due to its low level control over every aspect of the program, including its concurrency means. C is ideal for performance-critical systems where development time can be sacrificed to take full advantage of it.

Java strikes a balance by being compiled even if it is still high level with automatic garbage collection. However, the unpredictable pauses from the garbage collector are a serious downside when milliseconds can matter.
 
Python's concurrency library `asyncio` is wonderfully suited to the IO bound satellite, even if it can't run parallel threads. Despite this, Python's performance simply can't match C due to it being interpreted and having the overhead that comes with automatic memory management.

## Development Time

As a consequence of its fine-grained control, programming in C takes significantly more development time. Especially in implementing complex synchronisation, the team will spend more time developing solutions than if they were to use built-in high-level options with Java or Python.

Java is balanced between its performance and development time. The JVM's automatic garbage collection and its use of the object-oriented paradigm make it much easier to develop large-scale programs such as the satellite's software.

Python has extensive libraries and beautifully simple syntax, both of which massively reduce development time. As a direct result of this ease of use, its performance is severely limited.

# Recommendation

Although it will incur the most development time, C is the best choice for the satellite's software. C's low-level control and resulting performance make it perfectly suited for the constant real-time readings and adjustments required. Ultimately, the software in the satellite will protect the massive resources invested in the entire mission. To ensure the satellite's software is efficient enough to reliably protect it, C is the recommended language.

