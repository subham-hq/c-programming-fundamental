# Makefile for the Introduction to Programming in C repository.
#
#   make            build every program into build/
#   make check      compile-check every .c with warnings enabled (no output binaries)
#   make format     apply .clang-format to all sources
#   make clean      remove build artifacts
#
# Each example and mini-project is a single self-contained .c file.
# Each assignment compiles its main.c (which includes the implementation .c,
# per the course convention).

CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11
BUILD   := build

# Single-file programs: examples + mini-projects
SINGLE_SRCS := $(shell find examples mini-projects -name '*.c')
SINGLE_BINS := $(patsubst %.c,$(BUILD)/%,$(SINGLE_SRCS))

# Multi-file assignments: build from each main.c
ASSIGN_MAINS := $(wildcard assignments/*/main.c)
ASSIGN_BINS  := $(patsubst assignments/%/main.c,$(BUILD)/assignments/%,$(ASSIGN_MAINS))

.PHONY: all check format clean

all: $(SINGLE_BINS) $(ASSIGN_BINS)
	@echo "Build complete -> $(BUILD)/"

# Pattern rule for single-file programs
$(BUILD)/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Assignments (main.c includes the sibling implementation .c)
$(BUILD)/assignments/%: assignments/%/main.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Compile-check only: fails on the first error/warning-as-error
check:
	@bash scripts/check.sh

format:
	@find examples mini-projects assignments reference \( -name '*.c' -o -name '*.h' \) \
		-exec clang-format -i {} + && echo "Formatted all sources."

clean:
	@rm -rf $(BUILD)
	@echo "Cleaned."
