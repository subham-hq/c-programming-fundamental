# Reference

## pointer_struct_cheatsheet.c

A personal, heavily-commented reference I wrote to keep pointer and struct syntax straight — the
difference between `&` and `*`, `.` vs `->`, arrays vs pointers, pointer arithmetic, and passing
structs to functions. It compiles and runs, but it exists to be **read**, not to do anything
useful when executed.

```bash
gcc -Wall -Wextra -std=c11 pointer_struct_cheatsheet.c -o cheatsheet && ./cheatsheet
```

(During the refactor, a few illustration-only expressions that had been left uncommented were
turned into comments so the file compiles — content is otherwise unchanged. See
`../docs/CODE_REVIEW.md`.)
