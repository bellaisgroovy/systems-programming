#paper-note #memory 
**Process Control Block (PCB)**
The process control block stores the state of running programs including their:
- state
- number 
- program counter 
- registers 
- memory limits 
- list of open files

## Virtual Memory
Memory virtualisation is having a layer between actual hardware memory where things are stored, and memory addresses that are reported to programs.

**Advantages**
Virtual memory allows programs to have a seemingly contiguous memory space which makes memory management much simpler.

Disk can be used as memory which allows programs to have more memory if they need it.

Access control can be applied along with virtual memory.
### Paging
Paging is a method of splitting up the memory into many small fixed size blocks to avoid fragmentation.

**Page Frame**
A page frame is a space for a page to go in. The memory is split into page frames

**Page**
A page is information inside of a page frame allocated to a program.

Equally, fixed size partitions of address space.

**Page Table**
The page table has an entry for each page frame. It contains the real address of that page in memory, and a resident bit that indicates if a page is currently inside of that page frame.

**Page replacement**
Some page table entries are held in faster memory called the translation lookaside buffer (TLB), this is what makes it acceptable that virtual memory requires two lookups per lookup.

Most pages are held on disk (as there are loads), and page replacement refers to replacing a page table entry in memory with one from disk.

Usually, frames are constantly being freed so there are always some free ones when they are needed
## Caching
Caching is storing frequently accessed data in faster but scarcer memory. This means that you can have less fast expensive memory, and still run things quickly.

Usually values are close in memory to other related values so caching close values is a good idea.

**Levels of Memory**
Some memory is big, cheap, and slow, like hard drives, other memory is small, expensive, and fast, like registers. This creates a hierarchy of memory.