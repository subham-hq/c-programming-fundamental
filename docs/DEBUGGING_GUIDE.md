# Debugging Guide

A short, practical reference for debugging the kind of C programs in this repository. Most of the
bugs found during the code review (see `CODE_REVIEW.md`) would have been caught faster with these
habits.

## 1. Let the compiler help first

Most beginner bugs are warnings, not mysteries. Compile with:

```bash
gcc -Wall -Wextra -std=c11 program.c -o program
```

Then compile again with optimisation, which enables extra data-flow analysis:

```bash
gcc -Wall -Wextra -O1 -std=c11 program.c -o program
```

`-O1` is how the "used uninitialised" warning for `array_average.c` was surfaced during review.

## 2. Sanitizers catch what warnings miss

AddressSanitizer and UndefinedBehaviorSanitizer instrument the program to trap errors at run time:

```bash
gcc -g -fsanitize=address,undefined -std=c11 program.c -o program
./program
```

They catch:

| Problem | Example in this repo's bug history |
|---------|------------------------------------|
| Out-of-bounds access | `arrays_ex3.c` reading `arr[5..9]` of a 5-element array |
| Use-after-free / double free | any mishandled `malloc`/`free` |
| Memory leaks | the missing `free` calls fixed in the dynamic-memory programs |
| Undefined behaviour | mismatched `scanf` specifiers in `dynamic_structs.c` |

## 3. Step through with gdb

```bash
gcc -g -std=c11 program.c -o program
gdb ./program
```

Useful commands:

| Command | Effect |
|---------|--------|
| `break main` | Stop at the start of `main` |
| `run` | Start the program |
| `next` / `step` | Execute one line (over / into calls) |
| `print x` | Show the value of `x` |
| `backtrace` | Show the call stack |
| `continue` | Resume until the next breakpoint |

## 4. printf debugging

For simple logic bugs, a temporary `printf` that shows a variable's value is often the fastest
tool — just remember to remove it afterwards. This is how a mislabelled comparison like the
"max vs. min" bug in `dynamic_structs.c` becomes obvious: print the value being compared on each
iteration and watch which one "wins".

## 5. A checklist for the common cases

- Did every `scanf` format specifier match the argument's type exactly?
- Is every array index provably within bounds?
- Was every variable initialised before it was read?
- Did every `malloc`/`fopen` get NULL-checked, and every `malloc` get a matching `free`?
- Is integer division silently truncating a value you expected to be fractional?
