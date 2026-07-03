# Assignments

Graded work from the course, using the multi-file layout it required: a header (`.h`) declaring the
function, an implementation (`.c`), and a `main.c` that drives it.

> The original course problem statements are **not** included here — that is the course provider's
> material. Each task is described below in my own words.

| Folder | Task |
|--------|------|
| `digit-frequency` | Given a number and a digit (0–9), count how many times the digit appears in the number. The counting is done by a `frequency()` function. |
| `grade-report` | Compute and report grades from input marks. |
| `array-rotation` | Rotate the elements of an array by a given amount. |

**Build** (the course convention has `main.c` include the implementation `.c`):

```bash
cd digit-frequency
gcc -Wall -Wextra -std=c11 main.c -o frequency && ./frequency
```

See `../docs/CODE_REVIEW.md` for why the `#include`-a-`.c` structure is kept as submitted.
