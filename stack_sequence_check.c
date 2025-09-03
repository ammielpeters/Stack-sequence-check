#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to check if the given popped sequence is valid
int validateStackSequences(int pushed[], int popped[], int n) {
    int stack[MAX], top = -1;
    int i = 0, j = 0;

    while (i < n) {
        // Push the current element from pushed[] onto stack
        stack[++top] = pushed[i++];

        // Keep popping while top of stack matches popped[j]
        while (top >= 0 && stack[top] == popped[j]) {
            top--; // pop
            j++;
        }
    }

    // If stack is empty at the end, it's valid
    return (top == -1);
}

int main() {
    int pushed[] = {5, 10, 15, 20, 25};
    int popped1[] = {20, 25, 15, 10, 5};   // Valid
    int popped2[] = {20, 15, 25, 5, 10};   // Invalid
    int n = sizeof(pushed) / sizeof(pushed[0]);

    printf("Test Case 1: %d\n", validateStackSequences(pushed, popped1, n)); // Output 1
    printf("Test Case 2: %d\n", validateStackSequences(pushed, popped2, n)); // Output 0

    return 0;
}
