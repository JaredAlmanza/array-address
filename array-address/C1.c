#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int* address;
} Element;

Element* resizeArray(Element* arr, int oldSize, int newSize) {
    Element* newArr = (Element*)malloc(newSize * sizeof(Element));
    int elementsToCopy = oldSize < newSize ? oldSize : newSize;
    
    for (int i = 0; i < elementsToCopy; i++) {
        newArr[i] = arr[i];
    }
    
    free(arr); 
    return newArr;
}

Element* removeAtIndex(Element* arr, int size, int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index!\n");
        return arr;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return resizeArray(arr, size, size - 1);
}

int main() {
    int size, indexToRemove;

    printf("Enter the initial size of the array: ");
    scanf("%d", &size);

    Element* dynamicArray = (Element*)malloc(size * sizeof(Element));

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i].value);
        dynamicArray[i].address = &dynamicArray[i].value;
    }

    printf("Array elements along with their addresses:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Address: %p\n", dynamicArray[i].value, dynamicArray[i].address);
    }

    printf("Enter the index to remove an element: ");
    scanf("%d", &indexToRemove);

    dynamicArray = removeAtIndex(dynamicArray, size, indexToRemove);

    printf("Updated Array:\n");
    for (int i = 0; i < size - 1; i++) {
        printf("Value: %d, Address: %p\n", dynamicArray[i].value, dynamicArray[i].address);
    }

    free(dynamicArray); 

    printf("\nJared Almanza, gnn962, Assignment 6 Fall 2023 DS");

    return 0;
}
