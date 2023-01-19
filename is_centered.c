#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct sized_array {
    unsigned int len;
    int *arr;
} sized_array_t;

int is_centered(sized_array_t* arr){
    // int arr[] = {10};
    printf("arr%d\n", arr->len);
    int i;
   // int len = sizeof(*arr) / sizeof(arr[0]);
    unsigned int len = arr->len;
    unsigned int mid = len / 2;
    if (len % 2 == 0)
        return (0);
    for (i = 0; i < mid; i++){
        if (arr->arr[i] <= arr->arr[mid] || arr->arr[len-i-1] <= arr->arr[mid])
            return (0);
    }
    return (1);
}

int main()
{
    int arr[] = {1,2,3,4};
    sized_array_t my_sized_arr = {
        sizeof(arr) / sizeof(int),
        arr
    };
    printf("%d\n", is_centered(&my_sized_arr));
    return (0);
}