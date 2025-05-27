#include <stdio.h>
#define MAXSIZE 7
#define TRUE 1
#define FALSE 0

// Structure defining Stack data structure
struct Stack {
    int top;
    int array[MAXSIZE];
} st;

// Initializes the top index to -1
void initialize() {
    st.top = -1;
}

// Checks if Stack is Full or not
int isFull() {
    return (st.top >= MAXSIZE - 1);
}

// Checks if Stack is Empty or not
int isEmpty() {
    return (st.top == -1);
}

// Adds an element to stack and then increments top index
void push(int num) {
    if (isFull()) {
        printf("Stack is Full...\n");
    } else {
        st.top++;
        st.array[st.top] = num;
    }
}

// Removes top element from stack and decrements top index
int pop() {
    if (isEmpty()) {
        printf("Stack is Empty...\n");
        return -1; // Returning -1 as an indicator of an empty stack
    } else {
        int removed = st.array[st.top];
        st.top--;
        return removed;
    }
}

// Prints elements of stack using recursion
void printStack() {
    if (!isEmpty()) {
        int temp = pop();
        printStack();
        printf(" %d ", temp);
        push(temp);
    }
}

// Inserts an element at the bottom of the stack
void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
    } else {
        // Store the top element and recursively call insertAtBottom for the rest of the stack
        int top = pop();
        insertAtBottom(item);
        
        // Once the item is inserted at the bottom, push the top element back to stack
        push(top);
    }
}

// Reverses the stack using recursion
void reverse() {
    if (!isEmpty()) {
        // Keep popping top element of stack in every recursive call till stack is empty
        int top = pop();
        reverse();

        // Now, instead of inserting element back on top of stack,
        // we insert it at the bottom of stack
        insertAtBottom(top);
    }
}

// Returns the number of elements in Stack
int getSize() {
    return st.top + 1;
}

// Main function
int main() {
    // Initializing stack
    initialize();

    // Adding elements to stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Original Stack\n");
    printStack();

    reverse();

    printf("\nReversed Stack\n");
    printStack();

    return 0;
}
