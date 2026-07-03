#include <stdio.h>

/* 1. Basic typedef */
typedef int Marks;

/* 2. Struct without name */
typedef struct {
    float real;
    float imag;
} Complex;

/* 3. Struct with name */
typedef struct Student {
    char name[50];
    int age;
} Student;

/* 4. Array typedef */
typedef int IntArray5[5];

/* 5. Pointer typedef */
typedef int* IntPtr;

/* 6. Function pointer typedef */
typedef int (*Operation)(int, int);

/* Function for function pointer */
int add(int a, int b) {
    return a + b;
}

int main() {

    /* 1. Basic typedef */
    Marks m1 = 90, m2 = 85;
    printf("Marks: %d %d\n", m1, m2);

    /* 2. Struct without name */
    Complex c1;
    c1.real = 2.5;
    c1.imag = 3.5;
    printf("Complex: %.2f + %.2fi\n", c1.real, c1.imag);

    /* 3. Struct with name */
    Student s1;
    s1.age = 20;
    printf("Student age: %d\n", s1.age);

    /* 4. Array typedef */
    IntArray5 arr = {1, 2, 3, 4, 5};
    printf("Array first element: %d\n", arr[0]);

    /* 5. Pointer typedef */
    int x = 10;
    IntPtr p = &x;
    printf("Pointer value: %d\n", *p);

    /* 6. Function pointer typedef */
    Operation op = add;
    printf("Function Pointer Result: %d\n", op(5, 3));

    return 0;
}