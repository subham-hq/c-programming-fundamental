/*
========================================================
                C POINTER + STRUCT CHEAT SHEET
========================================================

This file is designed to permanently clear confusion about:

- pointers
- arrays
- structs
- & operator
- * operator
- ->
- .
- arrays vs pointers
- package *p vs package p[]
- pointer arithmetic
- function arguments
- pass by value vs pass by reference

Keep this forever and revisit often.

========================================================
                    1. BASIC VARIABLES
========================================================
*/

#include <stdio.h>

int main()
{
    int x = 10;

    /*
    x stores VALUE 10
    */

    printf("%d\n", x);

    /*
    &x means:
    "address of x"
    */

    printf("%p\n", &x);

    /*
    Example:

    x = 10
    address of x = 1000 (example)

    Memory:
    Address     Value
    1000        10
    */




/*
========================================================
                    2. POINTERS
========================================================
*/

    int *p;

    /*
    p can store address of an int
    */

    p = &x;

    /*
    Now p stores address of x

    x = 10
    &x = 1000

    p = 1000
    */

    printf("%p\n", p);

    /*
    *p means:
    "value stored at address p"
    */

    printf("%d\n", *p);

    /*
    Output:
    10
    */

    /*
    IMPORTANT:

    int *p;

    Means:
    p is POINTER TO int

    NOT multiplication.
    */




/*
========================================================
            3. * OPERATOR HAS TWO MEANINGS
========================================================
*/

    /*
    Meaning 1: Declare pointer
    */

    int *a;

    /*
    Meaning 2: Dereference pointer
    */

    printf("%d\n", *p);

    /*
    Context decides meaning.
    */




/*
========================================================
                    4. STRUCTS
========================================================
*/

    struct package
    {
        int weight;
        int cost;
    };

    struct package pkg;

    pkg.weight = 50;
    pkg.cost = 100;

    /*
    Use . with ACTUAL struct variable
    */

    printf("%d\n", pkg.weight);




/*
========================================================
                5. POINTER TO STRUCT
========================================================
*/

    struct package *ptr;

    ptr = &pkg;

    /*
    ptr stores address of pkg
    */

    /*
    ACCESS METHODS
    */

    /*
    Method 1
    */

    printf("%d\n", (*ptr).weight);

    /*
    Method 2 (MOST COMMON)
    */

    printf("%d\n", ptr->weight);

    /*
    IMPORTANT:

    ptr->weight

    SAME AS:

    (*ptr).weight
    */




/*
========================================================
                6. ARRAYS
========================================================
*/

    int arr[3] = {10, 20, 30};

    /*
    arr means address of first element
    */

    printf("%p\n", arr);

    printf("%p\n", &arr[0]);

    /*
    SAME ADDRESS
    */




/*
========================================================
            7. ARRAY INDEXING MAGIC
========================================================
*/

    /*
    THESE ARE SAME:
    */

    // arr[0]

    /*
    SAME AS:
    */

    // *(arr + 0)

    /*
    arr[1]
    */

    // *(arr + 1);

    /*
    arr[i]

    SAME AS:

    *(arr + i)
    */




/*
========================================================
            8. POINTER ARITHMETIC
========================================================
*/

    int nums[3] = {5, 10, 15};

    int *q = nums;

    /*
    q points to nums[0]
    */

    printf("%d\n", *q);

    /*
    Output:
    5
    */

    q++;

    /*
    q now points to next integer
    */

    printf("%d\n", *q);

    /*
    Output:
    10
    */




/*
========================================================
                9. ARRAY OF STRUCTS
========================================================
*/

    struct package packages[3] =
    {
        {10, 20},
        {30, 40},
        {50, 60}
    };

    /*
    packages[0]
    is ACTUAL STRUCT
    */

    printf("%d\n", packages[0].weight);

    /*
    IMPORTANT:

    // packages[i].weight

    Use . because packages[i]
    is actual struct
    */




/*
========================================================
            10. ADDRESS OF STRUCT IN ARRAY
========================================================
*/

    /*
    &packages[i]

    means:
    address of that struct
    */

    struct package *temp;

    temp = &packages[1];

    printf("%d\n", temp->weight);




/*
========================================================
            11. FUNCTION PARAMETERS
========================================================
*/

    /*
    PASS BY VALUE
    */

    /*
    Makes copy
    Original unchanged
    */

    /*
    Example:
    */

    /*
    void func(int x)
    */




/*
========================================================
            12. PASS BY REFERENCE (POINTER)
========================================================
*/

    /*
    Original CAN change
    */

    /*
    Example:
    */

    /*
    void func(int *x)
    {
        *x = 100;
    }
    */




/*
========================================================
            13. STRUCT FUNCTION RULES
========================================================
*/

    /*
    IF only reading:
    can pass by value
    */

    /*
    IF modifying:
    pass pointer
    */




/*
========================================================
            14. THESE ARE EQUIVALENT
========================================================
*/

    /*
    package *packages

    SAME AS:

    package packages[]
    */

    /*
    INSIDE FUNCTION PARAMETERS ONLY

    THESE MEAN:
    pointer to first package
    */




/*
========================================================
            15. IMPORTANT DISTINCTION
========================================================
*/

    /*
    package *packages

    POINTER TO package
    */

    /*
    package packages[5]

    ARRAY OF 5 packages
    */




/*
========================================================
            16. ACCESS CHEAT SHEET
========================================================
*/

    /*
    NORMAL VARIABLE
    */

    int y = 10;

    // y

    /*
    ADDRESS OF VARIABLE
    */

    // &y

    /*
    POINTER VARIABLE
    */

    int *py = &y;

    /*
    VALUE INSIDE POINTER ADDRESS
    */

    // *py




/*
========================================================
            17. STRUCT ACCESS CHEAT SHEET
========================================================
*/

    struct package p1;

    /*
    ACTUAL STRUCT
    */

    // p1.weight

    /*
    POINTER TO STRUCT
    */

    struct package *pp = &p1;

    // pp->weight

    /*
    SAME AS:
    */

    // (*pp).weight




/*
========================================================
            18. COMMON BEGINNER MISTAKES
========================================================
*/

    /*
    WRONG:
    */

    /*
    packages[]->weight
    */

    /*
    CORRECT:
    */

    // packages[i].weight

    /*
    OR
    */

    // (packages + i)->weight




/*
========================================================
            19. VERY IMPORTANT EQUIVALENCES
========================================================
*/

    /*
    arr[i]

    SAME AS

    *(arr + i)
    */

    /*
    ptr->x

    SAME AS

    (*ptr).x
    */

    /*
    package *p

    SAME AS

    package p[]

    ONLY IN FUNCTION PARAMETERS
    */




/*
========================================================
            20. MOST IMPORTANT MEMORY MODEL
========================================================
*/

    /*
    VARIABLE:
    stores VALUE

    POINTER:
    stores ADDRESS

    *pointer:
    gets VALUE at address

    &variable:
    gets ADDRESS of variable
    */




/*
========================================================
                21. GOLDEN RULE
========================================================
*/

    /*
    Use .

    when you have actual object
    */

    /*
    Use ->

    when you have pointer to object
    */




/*
========================================================
                22. FINAL MENTAL MODEL
========================================================
*/

    /*
    house           = struct
    house address   = pointer

    .  = enter house directly
    -> = go to house using address
    */




/*
========================================================
                    23. SUMMARY
========================================================
*/

    /*
    x          -> value
    &x         -> address of x
    p          -> pointer
    *p         -> value at address p

    arr[i]     -> element
    *(arr+i)   -> same thing

    obj.field  -> access struct
    ptr->field -> access through pointer

    */

    return 0;
}