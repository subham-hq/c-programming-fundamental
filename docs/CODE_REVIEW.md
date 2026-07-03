# Code Review

When this coursework was organised into a repository, every source file was reviewed and
compiled with warnings enabled (`gcc -Wall -Wextra -std=c11`). The goal was honest quality:
**fix genuine defects, preserve the code's original intent and style.** Nothing was rewritten
to look more advanced than it is. This document records what was found, what was fixed, and —
just as importantly — what was deliberately left alone.

## Method

1. Compile every file with `-Wall -Wextra`.
2. Compile the dynamic-memory programs additionally under `-O1` to surface use-of-uninitialised
   warnings that only appear with optimisation.
3. Run the fixed programs against sample input to confirm behaviour actually changed correctly.
4. Leave stylistic choices (brace placement, spacing, naming) untouched where they were
   consistent and clearly the author's.

## Defects fixed

| # | File | Defect | Severity | Fix |
|---|------|--------|----------|-----|
| 1 | `examples/03-arrays/array_average.c` | `sum` read before initialisation (`sum += arr[i]`) | Undefined behaviour | `int sum = 0;` |
| 2 | `examples/03-arrays/arrays_ex3.c` | Loop read `arr[0..9]` from a 5-element array; unused `sum` | Out-of-bounds read | Bound corrected to `< 5`; dead variable removed |
| 3 | `examples/05-structures/struct_basics.c` | `strcpy` used with no `#include <string.h>` | Undefined behaviour (implicit declaration) | Added the header |
| 4 | `examples/05-structures/student_average.c` | Integer division assigned to a `float` average | Logic bug (truncation) | Divide by `2.0f` |
| 5 | `examples/07-dynamic-memory/dynamic_structs.c` | `%d` used for a `char[]` and a `float`; `malloc` unchecked; never freed; "max" loop selected the **minimum** | UB + logic + leak | `%s`/`%f`; NULL check; `free`; comparison flipped |
| 6 | `mini-projects/grocery-inventory/grocery_inventory.c` | `int max_price` compared against `float`; `malloc` unchecked; never freed | Logic + leak | `float max_price`; NULL check; `free` |
| 7 | `examples/08-file-io/find_substring_in_file.c` | `fopen` result used without a NULL check | Crash on missing file | NULL check |
| 8 | `examples/08-file-io/copy_lines_between_files.c` | Both `fopen` calls unchecked | Crash on missing file | NULL checks (read + write) |
| 9 | `reference/pointer_struct_cheatsheet.c` | Illustration-only expressions left uncommented; file did not compile | Compile error | Commented the illustration lines; content otherwise unchanged |

### Bug classes represented

These map to the most common mistakes a C beginner makes, which is exactly why they are worth
keeping visible:

- **Uninitialised reads** (#1) — C does not zero locals for you.
- **Off-by-one / bounds** (#2) — the compiler will not stop you indexing past an array.
- **Format-specifier mismatches** (#5) — `scanf`/`printf` specifiers must match the argument type exactly.
- **Unchecked resource acquisition** (#5, #6, #7, #8) — `malloc` and `fopen` can fail and must be checked.
- **Missing `free`** (#5, #6) — every `malloc` needs a matching `free`.
- **Integer vs. floating-point division** (#4) — a classic silent logic bug.

## Left as written (reviewed, intentionally unchanged)

- **`scanf("%s", ...)` for strings** — unbounded and unsafe on long input, but taught by the
  course and used consistently. Flagged, not changed. Real code should bound the width (`%49s`)
  or use `fgets`.
- **`#include "frequency.c"`** and the other assignments — including a `.c` file is an
  anti-pattern, but the course's auto-grader compiled `main.c` this way, so the submitted
  structure is preserved.
- **Signed/unsigned `sizeof` comparisons** in `arrays_ex1.c` / `arrays_ex2.c` — a
  `-Wsign-compare` warning; the logic is correct for these sizes.
- **Implicit `return 0` from `main`** in several programs — valid since C99.

## Excluded from the repository

- Compiled binaries (`a.out`), `.DS_Store`, and the embedded `.git` from the original archive.
- Course-platform problem statements (`*.html`, `problem statement.md`) — the provider's
  material, not the author's, so not republished.
- Empty/scratch files (a 0-byte `module_5.c`, a throwaway `sample.c`).
