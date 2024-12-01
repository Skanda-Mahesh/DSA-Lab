#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 10

int prec(char operator);
int order(char operator);

 struct Stack {
    char arr[size];
    int top;
};

int push(struct Stack*, char input);
int pop(struct Stack*);
int InfixToPostfix(char *);
int display (struct Stack);

int main() {
    
}

int pop(struct Stack* operator_stack) {
    if (operator_stack->top == -1) {
        printf("The stack is empty");
    }

    else {
        char val = operator_stack->arr[operator_stack->top];
        operator_stack->top = operator_stack->top -1;

        return val;
    }
}

int push(struct Stack* operator_stack, char input) {
    if (operator_stack->top==(size-1)) {
        printf("Stack is full, cannot push to stack");

    }
    else {
        (operator_stack->top)++;

        operator_stack->arr[operator_stack->top] = input;

    }}

int prec(char operator) {

    if (operator=='^') {
        return 3;
    }

    else if (operator=='*' || operator=='/' || operator=='%') {
        return 2;
    }

    else if (operator=='+' || operator=='-') {
        return 1;
    }

}

int order(char operator) {
    if (operator=='^') {
        return 2;

    }
    else {
        return 1;
    }
}

int display (struct Stack stack) {

        for (int i = 0; i<9; i++) {
                printf("  %d  ", stack.arr[i]);
        }
        printf("\n");

        return 0;
}

int InfixToPostfix(char * inputExp) {
    int len = strlen(inputExp);
    
    struct Stack* operator = malloc(sizeof(struct Stack));
    struct Stack* output = malloc(sizeof(struct Stack));
    char c;
    for (int i = 0; i<len; i++) {
        c = inputExp[i];

        if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
            push(output, c);
        }

        if ((operator->top==-1) || (c=='()')) {
            push(operator, c);
        }

        if (prec(c) > prec(operator->arr[operator->top])) {
            push(operator, c);
        }

        if (prec(c) < prec(operator->arr[operator->top])) {
            int flag = 0;

            while (flag != 1 || operator->top != -1) {
                push(output, pop(operator));
                if (prec(c) < operator->arr[operator->top]) {
                    push(operator, c);
                    flag = 1;
                }
                
            }
        }

        if (prec(c) == operator->arr[operator->top]) {
            if (order(c) == 2) {
                push(output, pop(operator));
                push(operator, c);
            }
        }

        if (c==')') {
            char ch;
            while (ch != '(' || operator->arr[operator->top]!= -1) {
                push(output, pop(operator));
            }
        }

         while (operator->arr[operator->top]!= -1) {
                push(output, pop(operator));

    

    }

}