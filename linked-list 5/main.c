#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* link;
};


void insertFront(struct node** head, int data) {

    struct node* temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->link = *head;

    // Return the new head of the list
    *head = temp;
}

void insertRear(struct node** head, int data) {

    struct node* tmp = malloc(sizeof(struct node));

    tmp->data = data;
    tmp->link = NULL;

    struct node* current = *head;

    while (current->link != NULL) {
        current = current->link;
    }
    current->link = tmp;
}


void display(struct node* head) {
    while(head != NULL) {
        printf("%d", head->data);
        head = head->link;
    }
}

void deleteAtEnd(struct node** head_ref) {
    struct node* head = *(head_ref);
    if (head == NULL) {
        printf("Linked list is empty!");
        return;
    }

    if (head->link == NULL) {
        free(head);
        printf("Last node deleated!");
        *head_ref = NULL;
        return;

    }

    struct node* current = *head_ref;
    while ((current->link)->link != NULL) {
        current = current->link;
    }

    free(current->link);
    current->link = NULL;
}

void deleatAtFront(struct node** head_ref) {
    if (*(head_ref) == NULL) {
        printf("Linked list is empty!");
    }
    else if ((*head_ref)->link == NULL) {
        *head_ref = NULL;
        printf("First node deleated");
    }
    else {
        struct node* tmp = *head_ref;
        *head_ref = (*head_ref)->link;
        free(tmp);

    }
}

void deleatAtLocation(struct node** head_ref, const int element) {
    if (element == 1) {
        deleatAtFront(head_ref);
    }
    else if (element == -1) {
        deleteAtEnd(head_ref);
    }
    else {
        struct node* current = *head_ref;
        int itr = 1;
        while (current != NULL && itr != element-1) {
            current = current->link;
            itr++;
        }

        struct node* tmp = NULL;

        if (current == NULL) {
            printf("Cant delete, element dosent exist!");
        }
        else if (current->link == NULL) {
            printf("Cant deleate, the element dosent exist!");

        }
        else if (current->link->link != NULL) {
            tmp = current->link;
            current->link = current->link->link;
            free(tmp);
        }


        }
    }
