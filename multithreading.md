#paper-note #concurrency 
Multithreading is when a program makes use of multiple threads in execution

**Benefits of multithreading**
Multithreading speeds up execution by taking advantage of parallel hardware.

Multithreading increases responsiveness as threads can still run while others are waiting for I/O.

Multithreading allows for scalability since it breaks down execution into chunks that can be run on multiple cores or even machines.

Multithreading can be a convenient solution to a problem, like running different aspects of a program on different cores.

**Parallelisation**
Parallelisation is running code on parallel hardware, actually running multiple things simultaneously.

**Concurrency**
Concurrency is having multiple things on the go at the same time, even if some of them are paused. For instance run program 1 until it needs I/O, then while its waiting for that run program 2. Only one program was ever running at a time, but their execution was interleaved.

**Amdahl's Law**
Amdahl's law calculates the maximum speed up available by parallelisation based on what proportion of a program can be run in parallel.
- Amdahl's law 
- 