# Examples

Short, focused programs — one concept per file — written while working through the course. Each
compiles on its own (`gcc -Wall -Wextra -std=c11 <file>.c -o out`).

| Folder | Concept | Notable files |
|--------|---------|---------------|
| `01-control-flow` | `if`/`else`, `switch`, `while`, `for`, `break`, patterns | `grade_from_marks.c`, `triangle_pattern.c` |
| `02-functions` | Declarations, parameters, return values | `prime_check.c` |
| `03-arrays` | 1-D arrays, iteration, passing to functions, search | `linear_search.c`, `array_average.c` |
| `04-matrices` | 2-D arrays, matrix add/multiply | `matrix_multiplication.c` |
| `05-structures` | `struct`, `typedef`, arrays of structs | `typedef_examples.c` |
| `06-pointers` | `&`/`*`, `->` vs `.`, pointer arithmetic | `pointers_and_structs.c` |
| `07-dynamic-memory` | `malloc`/`free`, dynamic arrays and structs | `dynamic_structs.c` |
| `08-file-io` | `fgets`, reading/writing files | `find_substring_in_file.c` |

Programs in `08-file-io` read the sample `.txt` files beside them — run them from inside that
folder.
