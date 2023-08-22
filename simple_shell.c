#include <stdio.h>
#include <string.h> // Include the string.h header for strcpy function

int main(int ac, char **av) {

    // Initialize character arrays
    char *result = av[0]; // This should be a pointer, not an array
    char result1[20];     // Declare character array with size 20
    char result2[20];     // Declare character array with size 20

    // Copy the values of av[1] and av[2] into result1 and result2
    strcpy(result1, av[1]);
    strcpy(result2, av[2]);

    // Print the values of the character arrays
    printf("Result: %s\n", result);
    printf("Result1: %s\n", result1);
    printf("Result2: %s\n", result2);

    return 0;
}
