//
// Created by ctlister on 12/5/22.
//

#ifndef STACK_H
#define STACK_H
#include <stdbool.h> /* C99 Only */

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
#endif

