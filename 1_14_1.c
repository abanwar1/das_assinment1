#include <stdio.h>
#include <stdlib.h>
int *arr = NULL;
int size = 0, choice=0, pos=0;

void create() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);
	arr = (int*) malloc(size * sizeof(int));
	printf("Enter %d elements: ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void display() {
    printf("List:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int count() {
    return size;
}

void reverse(int *arr, int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    printf("Array reversed Successfully.\n");
}

void indexOf(int *arr, int size) {
    int found, flag = 0;
    printf("\nEnter element to find: ");
    scanf("%d", &found);
    printf("Indix possition of %d: ", found);
    for (int i = 0; i < size; i++) {
        if (arr[i] == found) {
            printf("%d ", i);
            flag = 1;
        }
    }
    if (!flag) {
        printf("Element Not found.\n");
    }
}

void indexElement(int *arr, int size) {
    int index;
    printf("\nEnter index of element: ");
    scanf("%d", &index);
    if (index >= 0 && index < size) {
        printf("Element at index %d: %d\n", index, arr[index]);
    } else {
        printf("Element not present.\n");
    }
}

void insert(int **arr, int *size) {
    int index, data;
    printf("\nEnter index to insert value: ");
    scanf("%d", &index);
    printf("Enter the element: ");
    scanf("%d", &data);
    if (index >= 0 && index <= *size) {
        (*size)++;
        *arr = (int *)realloc(*arr, (*size) * sizeof(int));
        for (int i = *size - 1; i > index; i--) {
            (*arr)[i] = (*arr)[i - 1];
        }
        (*arr)[index] = data;
        printf("Element inserted.\n");
    } else {
        printf("Invalid index. Please Try Again\n");
    }
}

void delete_val() {
    int index;
    printf("Enter the index of the number to delete (0-%d): ", size - 1);
    scanf("%d", &index);

    if(index >= 0 && index < size) {
        int num = arr[index];
        for(int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr = (int *)realloc(arr,(size - 1)*sizeof(int));
        size--;

        printf("value '%d' deleted successfully.\n", num);
    } else {
        printf("Invalid index, please try again.\n");
    }
}

void merge(int** arr, int* size) {
    int size2;
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    
    int* arr2 = (int*)malloc(size2 * sizeof(int));
    
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    *arr = (int*)realloc(*arr, (*size + size2) * sizeof(int));
    for (int i = 0; i < size2; i++) {
        (*arr)[*size+i] = arr2[i];
    }
    
    *size += size2;
    
    printf("Merged array:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
    
    free(arr2);
}
void split(int pos) {
    int *left, *right;
    int left_size = 0, right_size = 0;
    left = malloc(0);
    right = malloc(0);
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < pos) {
            left_size++;
            left = realloc(left, left_size * sizeof(int));
            left[left_size - 1] = arr[i];
        } else {
            right_size++;
            right = realloc(right, right_size * sizeof(int));
            right[right_size - 1] = arr[i];
        }
    }
    
    printf("Array split successfully.\n");
    printf("Left subarray: ");
    for (int i = 0; i < left_size; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");
    printf("Right subarray: ");
    for (int i = 0; i < right_size; i++) {
        printf("%d ", right[i]);
    }
    printf("\n");
}

void sort() {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}
void search() {
    int num,i=0,flag=0;
    printf("Enter the number to search: ");
    scanf("%d", &num);

    while(i<=size) {
		if (arr[i] == num) {
            printf("%d is found at index %d\n", num, i);
            flag=1;
        }
        i++;
    }
    
	if(flag==0){
		printf("Not Found\n\n");
	}  
}

int main() {
    int choice, data;

    do {
        printf("\n*****OPERATIONS*****\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Reverse\n");
        printf("5. Index of a given element\n");
        printf("6. Indexed element\n");
        printf("7. Insert\n");
        printf("8. Delete\n");
        printf("9. Merge\n");
        printf("10. Split\n");
        printf("11. Sort\n");
        printf("12. Search\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Total number of element: %d\n", count());
                break;

            case 4:
                reverse(arr,size);
                break;

            case 5:
                indexOf(arr,size);
                break;

            case 6:
                indexElement(arr,size);
                break;

            case 7:
                insert(&arr,&size);
                break;

            case 8:
				delete_val();
                break;

            case 9:
                merge(&arr, &size);
                break;

            case 10:
                printf("Enter the position you want to split:");
                scanf("%d",&pos);
				split(pos);
                break;

            case 11:
                sort();
                break;

            case 12:
                search();
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 0);
	
	free(arr);
	
    return 0;
}
