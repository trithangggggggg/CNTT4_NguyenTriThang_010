//
// Created by ROG on 7/28/2025.
//
#include <stdio.h>
#define MAX_CHARACTER 1000

void menu() {
    printf("\n=====MENU=======\n");
    printf("1. INSERT x\n");
    printf("2. UNDO\n");
    printf("3. REDO\n");
    printf("4. DISPLAYS\n");
    printf("5. EXITS\n");
}

typedef struct Operation {
    char action;
    char value;
} Operation;

typedef struct Stack {
    Operation data[MAX_CHARACTER];
    int top;
}Stack;

// khoi tao stack
void initStack(Stack *s) {
     s->top == -1;
}
// kiem tra stack romg
int isEmptyStack(Stack *s) {
    return s->top == -1;
}
// kiem tra stack full
int isFullStack(Stack *s) {
    return s->top == MAX_CHARACTER - 1;
}
// them phan tu vao stack
void push(Stack *s, char value) {

}






int main() {

    return 0;
}