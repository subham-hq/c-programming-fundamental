# Style Guide

These are the conventions the repository actually follows. They are enforced mechanically by
[`.clang-format`](../.clang-format), so "the style" is not a matter of opinion — run
`make format` (or `clang-format -i <file>`) and the code conforms.

## Formatting

| Rule | Setting |
|------|---------|
| Indentation | 4 spaces, never tabs |
| Braces | Allman style — opening brace on its own line |
| Line length | 100 columns |
| Pointer alignment | bound to the name: `int *p` |
| Short `if`/loops on one line | not allowed — always brace and break |
| Include ordering | left as written (not auto-sorted) |

Example:

```c
int frequency(int num, int digit)
{
    int freq = 0;

    while (num > 0)
    {
        if (num % 10 == digit)
        {
            freq++;
        }
        num /= 10;
    }

    return freq;
}
```

## Naming

- Functions and variables: `lower_snake_case` (`check_prime`, `max_index`).
- Constants and compile-time sizes: `UPPER_SNAKE_CASE` via `#define` (`SIZE`, `MAX_PLANETS`).
- `typedef`'d struct types: `PascalCase` (`Student`, `Complex`).
- Names describe intent (`notPrimeFlag`, `distanceFromEarth`) rather than being single letters,
  except for conventional loop counters (`i`, `j`, `k`).

## Comments

- A short comment states *why* a block exists or clarifies a non-obvious step.
- Comments are not used to restate what the code plainly says.
- The pointer/struct reference file (`reference/pointer_struct_cheatsheet.c`) is deliberately
  comment-heavy — it is a study aid, not a typical source file.

## Files and structure

- One concept per file in `examples/`.
- Self-contained programs are single `.c` files.
- Multi-file work keeps declarations in a `.h` and definitions in a `.c`
  (see `assignments/`, and the note in the Code Review about the course's `#include`-a-`.c`
  convention).
