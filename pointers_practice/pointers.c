#include <stdio.h>

int main() {
    int age = 23;
    int *ptr = &age; // ptr holds the memory address of age

    printf("Value of age: %d\n", age);
    printf("Memory address of age (&age): %p\n", (void*)&age);
    printf("Value stored in ptr (ptr):    %p\n", (void*)ptr);
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr);

    // Modify the value using the pointer
    *ptr = 25;
    printf("\nNew value of age after '*ptr = 25': %d\n", age);

    return 0;
}