# Mini-Projects

Two of the course programs are larger and self-contained enough to stand on their own rather than
sit among the single-concept examples. Both were written during the course and cleaned up in the
refactor.

## planet-habitability

A menu-driven program that stores a set of planets (name, distance, gravity, atmospheric
composition) in an array of `struct`s, flags each as habitable using gravity and oxygen
thresholds, and lets the user: list habitable planets sorted by distance, filter by oxygen/CO₂
levels, or search names by keyword. Exercises nested structs, an array of structs, selection sort
over structs, and `string.h` search.

## grocery-inventory

Reads a dynamically allocated list of grocery items (id, name, price, quantity), then supports
looking up an item by quantity and finding the highest-priced item. Exercises `malloc`-backed
arrays of structs, returning structs from functions, and clear ownership of allocated memory
(allocated in one function, freed in `main`).
