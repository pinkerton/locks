# Locks

Implementation of a basic spinlock in C and x86 assembly.

# Resources

 * [XCHG](http://x86.renejeschke.de/html/file_module_x86_id_328.html)
 * [Pseudocode](http://stackoverflow.com/questions/22424209/tsl-instruction-reference)
 * [Test & set](https://en.wikipedia.org/wiki/Test-and-set)
 * [Semaphore reference](https://en.wikipedia.org/wiki/Semaphore_(programming))
 * [Extended ASM](https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html#Clobbers)
 * [GCC inline assembly](http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#s5)


Basic usage
====
 * Clone this repo
 * `cd locks`
 * `mkdir build && cd build`
 * `cmake ..`
 * `make`
 * `./run_tests`

CMake
====

CMake is configured here to naively glob together all of the source and header files in `/src` and `/include` respectively. By default, it will compile files with debug symbols and all unit tests when you run `make`. This has been all I've needed for doing homework sets and small projects, but it will need to be configured to do release / optimized builds eventually.

For now, `make test` does not work because it seems to require all tests to be defined in `tests/CMakeLists.txt`, when I'd rather it run all tests automatically without explicitly defining them there. This should be possible to do, but running `targets/run_tests` also has the "correct" behavior. I think this is related to messing with `CMAKE_RUNTIME_OUTPUT_DIRECTORY`. 


License
====

MIT. See LICENSE for details.
