#include <stdio.h>
#include <stdlib.h>

int insert(int*, int , int* , int, int*);
int dequeue(int*, int*, int*);
int display(int* , int, int*, int*);

int main() {

    int size = 0;
    printf("Enter size of queue: ");
    scanf("%d", &size);

    int* queue = calloc(size, sizeof(int));
    
    int rear = -1;
    int top = -1;
    int inp=0;
    int val=0;

    while (1) {
        printf("1: Enter data \n 2: Pop from queue \n 3: Display Queue\n 4: Exit \n");
        scanf("%d", &inp);

        switch (inp)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(queue, val, &rear, size, &top);
            break;
        
        case 2:
            dequeue(queue, &top, &rear);
            break;
        case 3:
            display(queue, size, &rear, &top);
            break;
        case 4:
            return 0;
        }
    }



}

int insert(int* queue, int value, int* rear, int size, int* top) {
    if (*(rear)==(size-1)) {
        printf("There is no space left in queue!, Overflow.\n \n");
        return 1;
    }
    else {

        if (*top == -1) {
            (*top)++;
        }

        (*rear)++;
        queue[*(rear)] = value;
        return 0;
    }

}

int dequeue(int* queue, int* top, int* rear) {
    if (*top== -1 || *top>*rear) {

        printf("Queue is aldready empty / Underflow!\n \n");
        return 1;
    }
 
    queue[*(top)] = 0;
    (*top)++;
    return 0;

    if (*top>*rear) {
        *top = -1;
        *rear = -1;
    }
    
}

int display(int* queue, int size, int* rear, int* top) {
    for (int i=(*top); i<=(*rear); i++) {
        printf(" %d ", queue[i]);
    }
    printf("\n");
}