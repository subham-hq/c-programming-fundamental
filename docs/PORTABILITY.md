# Portability

The code in this repository is standard C11 using only the standard library, so it is portable
across compilers and operating systems. This note records the details that matter.

## What is portable here

- Only standard headers are used: `<stdio.h>`, `<stdlib.h>`, `<string.h>`.
- No compiler extensions, no platform APIs, no third-party libraries.
- Builds identically with GCC and Clang under `-std=c11`.
- Confirmed to compile clean under `gcc -Wall -Wextra -std=c11` (GCC 13, Linux).

## Points worth knowing

| Topic | Note |
|-------|------|
| `scanf` with `float` | Read a `float` with `%f`, a `double` with `%lf`. Mixing them is undefined behaviour — one such mismatch was fixed during review. |
| `printf` with `float` | Both `float` and `double` print with `%f` (a `float` is promoted to `double` for the call). |
| Implicit `main` return | Falling off the end of `main` returns 0 since C99; some programs here rely on that. It is valid but explicit `return 0;` is clearer. |
| Line endings | The repo uses LF (enforced by `.editorconfig`). On Windows, reading text files opened in text mode may translate line endings; the file-I/O programs assume LF input like the provided sample data. |
| Character set | Plain ASCII source and I/O. No locale-specific behaviour is relied upon. |

## The one non-portable convention

The `assignments/` programs `#include` a `.c` file (e.g. `main.c` includes `frequency.c`). This
compiles anywhere, but it is a course-imposed convention rather than good practice — in a normal
project each `.c` is a separate translation unit compiled and linked independently. This is
explained in `CODE_REVIEW.md` and `COMPILATION.md`.

## Not tested

The code has not been built with MSVC or on Windows directly. There is no reason to expect
problems given it is straight standard C, but it has only been exercised with GCC/Clang on Linux.
