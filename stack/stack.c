#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct StackIde {
	int arr[10]; 
	int top;
};

int insert(struct StackIde* );
int pop(struct StackIde* );
int display(struct StackIde);


int main() {
	struct StackIde stack ;
	stack.top = -1;
	memset(stack.arr, 0, sizeof(stack.arr));
	insert(&(stack));
	insert(&(stack));
	insert(&(stack));
	insert(&(stack));
	insert(&(stack));
	pop(&(stack));
	display(stack);
	pop(&(stack));
	display(stack);
	return 0;

}

int pop(struct StackIde *stack) {

	if (stack->top !=-1) {
		printf("The value is: %d", stack->arr[stack->top]);
		printf("\n");
		stack->arr[stack->top] = 0;
		stack->top = stack->top -1;
		printf("\n");
		return 1;

	}

	else {
		printf("There is no data to remove in the stack");
		printf("\n");
		return 0;
	}

}


int insert (struct StackIde* stack) {

	if (stack->top != 9) {
		stack->top += 1;
		printf("Enter the data you want to insert");
		scanf("%d", &(stack->arr[stack->top]));
		printf("\n");
		printf("Data inserted");
		printf("\n");
		return 0;
	}


	else {
		printf("Stack is full");
		return 1;
	}

}


int display (struct StackIde stack) {
	
	for (int i = 0; i<9; i++) {
		printf("  %d  ", stack.arr[i]);
	}
	printf("\n");

	return 0;
}
	



















