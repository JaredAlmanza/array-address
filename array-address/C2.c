#include <stdio.h>
#include <stdlib.h>

struct FlexArray {
    size_t size;
    int data[]; 
};

int main() {
    size_t size_of_array;

    printf("Enter the size of the array: ");
    scanf("%zu", &size_of_array);

    struct FlexArray *arr = malloc(sizeof(struct FlexArray) + size_of_array * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    arr->size = size_of_array;

    printf("Enter the elements:\n");
    for (size_t i = 0; i < size_of_array; ++i) {
        scanf("%d", &arr->data[i]);
    }

    printf("Address of the first element: %p\n", (void *)&arr->data[0]);
    for (size_t i = 0; i < size_of_array; ++i) {
        printf("%zu: %d : (%p)\n", i + 1, arr->data[i], (void *)&arr->data[i]);
    }


    free(arr);

    printf("\nJared Almanza, gnn962, Assignment 6 Fall 2023 DS");

    return 0;
}
