#!/usr/bin/env bash
#
# Compile-check every C source in the repository with warnings enabled.
# Exits non-zero if any file fails to compile. Used by `make check` and by CI.
#
set -uo pipefail

CC="${CC:-gcc}"
CFLAGS="-Wall -Wextra -std=c11"
fail=0

echo "Compile-checking single-file programs (examples + mini-projects)..."
while IFS= read -r f; do
    if ! $CC $CFLAGS -fsyntax-only "$f" 2>/tmp/ccheck.err; then
        echo "  FAIL: $f"
        sed 's/^/      /' /tmp/ccheck.err
        fail=1
    fi
done < <(find examples mini-projects reference -name '*.c' | sort)

echo "Compile-checking multi-file assignments..."
for m in assignments/*/main.c; do
    [ -e "$m" ] || continue
    if ! $CC $CFLAGS -fsyntax-only "$m" 2>/tmp/ccheck.err; then
        echo "  FAIL: $m"
        sed 's/^/      /' /tmp/ccheck.err
        fail=1
    fi
done

if [ "$fail" -eq 0 ]; then
    echo "All sources compile cleanly."
else
    echo "One or more sources failed to compile."
fi
exit $fail
