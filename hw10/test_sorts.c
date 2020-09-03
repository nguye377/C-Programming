#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sorts.h"
bool _is_sorted(const int* , size_t);

int main(int argc, char* argv[]) {
    //TESTING  quick_sort_array() function
    int array[] = {9,5,3,1,4,2,8,7,6,0};
    printf("Before sorting, the list should be: ");
    for(int i = 0; i< 10; i++) {
        printf("%d ", array[i]);
    }

    printf("\nAfter sorting, the list should be: ");
    quick_sort_array(array, 10);
    for(int i = 0; i< 10; i++) {
        printf("%d ", array[i]);
    }
    //------------------------------------
    printf("\n");
    printf("-------------------------");
    printf("\n After TREE-SORTING, the array should be: ");
    //TESTING BST
	int array_test[] = {12, 12, 44, 6, 4, 77, 1, 2, 3, 3, 77, 44};
	tree_sort_array(array_test, 12);
	for (int i = 0; i < 12; i++) {
		printf("%d ", array_test[i]);
	}
    printf("\n"); 
    //Using Bool to test
    bool a = _is_sorted(array_test, 12);
    if (a == true) {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    tree_sort_array(NULL, 0);
    return EXIT_SUCCESS;
}

bool _is_sorted(const int* array, size_t size) {
    for(int i =0; i < size; i++){
        if(array[i] < array[i-1]){
            return false;
        }
    }
    return true;
}
//0-10