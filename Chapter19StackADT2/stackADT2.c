//
// Created by ctlister on 12/7/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *message) {
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Stack create(int size) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created");
    s->contents = malloc(size * sizeof(Item));
    if (s->contents == NULL ) {
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top = 0;
    s->size = size;
    return 0;
}

void destroy(Stack s) {
    free(s->contents);
    free(s);
}

void make_empty(Stack s){
    s->top = 0;
}

bool is_empty(Stack s) {
    return s->top == 0;
}

bool is_full(Stack s) {
    return s->top == s->size;
}

void push(Stack s, Item i) {
    if (is_full(s))
        terminate("Error in push: stack is full");
    s->contents[s->top++] = i;
}

Item pop(Stack s) {
    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    return s->contents[--s->top];
}
//error: initializer element is not constant, need to change headers files
//const s1 = create(100);
//const s2 = create(200);
void main() {
    return;
}

