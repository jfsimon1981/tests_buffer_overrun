# tests_buffer_overrun
- (1) C program to see the effect of buffers overrun

(1) Buffer under and overruns
In most applications, buffer overruns can be quite subtle, and would probably result from dereferencing a pointer with calculated offset, or function call result, or similar causes, which compiler woulnd't be able to preemptively check.
Runtime libraries exist, as well as other mechanisms, which help reduce the consequences of such behaviours, although is possible to overwrite selectively sensitive addresses, such as return address of the running function, which is stored on stack.
This minimal example prepares two char arrays of size 10+1 for null char termination. If the OS places them adjacent to each other, a simple write beyond boundary will write into the each other's content, as can probably demonstrated on you architecure by running this 4 liner snippet.