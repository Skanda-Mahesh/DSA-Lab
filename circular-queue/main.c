#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int size;
    int rear;
    int front;
    int* queue;
} Queue;

int enqueue(Queue*, int);
int dequeue(Queue*);
int display(Queue*);

int main() {
    Queue* q1 = malloc(sizeof(Queue));
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &q1->size);

    q1->front = -1;
    q1->rear = -1;    

    q1->queue = calloc(sizeof(int), q1->size); 

    int inp = 0;

    while (1)
    {
        
        printf("1: Enter data \n 2: Pop from queue \n 3: Display Queue\n 4: Exit \n");
        scanf("%d" , &inp);

        switch (inp)
        {
        case 1:
            int input = 0;
            printf("Enter input: ");
            scanf("%d", &input);
            enqueue(q1, input);
            break;
        
        case 2:
            dequeue(q1);
            break;
        case 3:
            display(q1);
            break;
        case 4:
            return 0;
            break;
        
        default:
            break;
        }
    
    }

    free(q1->size);
    free(q1);
    
    

}

int enqueue(Queue* q1, int input) {
    if (q1->front == -1 && q1->rear==-1) {
        q1->queue[0] = input;
        q1->front = 0;
        q1->rear = 0;
    }

    else if (((q1->rear+1) % q1->size) == q1->front) {
        printf("Overflow condition\n");

    }

    else {
        q1->rear = (q1->rear+1) % q1->size;
        q1->queue[q1->rear] = input;
    }
}



int dequeue(Queue* q1) {
    if (q1->front == -1 && q1->rear==-1) {
        printf("Underflow, queue empty\n");
    }

    else if (q1->front == q1->rear + 1) {
        printf("\n%d\n", q1->queue[q1->front]);
        q1->front = -1;
        q1->rear = -1;

    }
        else if (q1->front == q1->rear) {
        printf("\n%d\n", q1->queue[q1->front]);
        q1->front = -1;
        q1->rear = -1;

    }

    else {
        int tmp = q1->queue[q1->front];
        q1->front = (q1->front + 1) % q1->size;
        printf("\n Popped value: %d\n ", tmp);
        tmp = NULL;
    }

}

int display(Queue* q1) {

    for (int i = q1->front; i< q1->rear; i = (i + 1) % q1->size) {
        printf("  %d  ", q1->queue[i]);
    }
     printf("  %d  ", q1->queue[q1->rear]);
}