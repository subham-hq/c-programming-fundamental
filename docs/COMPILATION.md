# Compilation Guide

Everything here is standard C11 and builds with any modern C compiler (GCC or Clang). No
external libraries are used.

## Quick start

```bash
# Build every program into build/
make

# Compile-check everything with warnings, without producing binaries
make check

# Remove build artifacts
make clean
```

## Compiling a single program by hand

Each file in `examples/` and `mini-projects/` is self-contained:

```bash
gcc -Wall -Wextra -std=c11 examples/03-arrays/linear_search.c -o linear_search
./linear_search
```

Recommended flags while learning:

| Flag | Why |
|------|-----|
| `-Wall -Wextra` | Turn on the warnings that catch real bugs early |
| `-std=c11` | Compile against a well-defined standard |
| `-g` | Include debug symbols (needed for `gdb`) |
| `-fsanitize=address,undefined` | Catch memory errors and UB at run time (see the Debugging Guide) |
| `-O1` or higher | Enables extra data-flow warnings such as use-of-uninitialised |

## Programs that read files

The programs in `examples/08-file-io/` read the sample `.txt` files that sit next to them, so
run them from inside that directory:

```bash
cd examples/08-file-io
gcc -Wall -Wextra -std=c11 find_substring_in_file.c -o find
./find            # reads data1.txt
```

## Multi-file assignments

The programs in `assignments/` follow the course convention where `main.c` `#include`s the
implementation `.c` file. Compile `main.c`:

```bash
cd assignments/digit-frequency
gcc -Wall -Wextra -std=c11 main.c -o frequency
./frequency
```

> In a production project you would instead compile each translation unit separately and link
> the objects (`gcc -c frequency.c`, `gcc -c main.c`, `gcc *.o -o app`), with declarations in
> the `.h` and **no** `#include` of a `.c`. The course harness required the `#include` form, so
> it is kept as submitted. See the Code Review for context.

## Using Clang instead of GCC

```bash
clang -Wall -Wextra -std=c11 examples/02-functions/prime_check.c -o prime_check
```

The code is portable standard C; the compiler choice does not matter.
