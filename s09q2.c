#include <stdio.h>
#include <stdlib.h>

// Function to sort the disk request array
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the index of the first element greater than or equal to the head
int findIndex(int arr[], int n, int head) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= head) {
            index = i;
            break;
        }
    }
    return index;
}

// Function to simulate LOOK disk scheduling algorithm
void look(int arr[], int n, int head) {
    int total_head_movements = 0;

    // Sort the disk request array
    sort(arr, n);

    // Find the index of the first element greater than or equal to the head
    int index = findIndex(arr, n, head);

    // If no element is found greater than or equal to head, move to the last request
    if (index == -1) {
        index = n - 1;
        printf("%d -> ", head);
        total_head_movements += abs(head - arr[index]);
        head = arr[index];
    }

    // Move right
    for (int i = index; i < n; i++) {
        printf("%d -> ", arr[i]);
        total_head_movements += abs(head - arr[i]);
        head = arr[i];
    }

    // Move left
    for (int i = index - 1; i >= 0; i--) {
        printf("%d -> ", arr[i]);
        total_head_movements += abs(head - arr[i]);
        head = arr[i];
    }

    printf("\nTotal head movements: %d\n", total_head_movements);
}

int main() {
    int num_blocks, head_position;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &num_blocks);

    int *request_queue = (int *)malloc(num_blocks * sizeof(int));

    if (request_queue == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the disk request string: ");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &head_position);

    printf("Order of service:\n");
    look(request_queue, num_blocks, head_position);

    free(request_queue);

    return 0;
}
