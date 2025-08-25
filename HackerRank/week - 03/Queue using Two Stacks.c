#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000  
typedef struct {
    int data[MAX];
    int top;
} stack;
void push(stack *s, int val) {
    s->data[++(s->top)] = val;
}
int pop(stack *s) {
    return s->data[(s->top)--];
}
int peak(stack *s) {
    return s->data[s->top];
}
int isEmpty(stack *s) {
    return s->top == -1;
}
int main() {
    int q;
    scanf("%d", &q);
    stack stack_in, stack_out;
    stack_in.top = -1;
    stack_out.top = -1;
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(&stack_in, x);
        } 
        else if (type == 2) {
            if (isEmpty(&stack_out)) {
                while (!isEmpty(&stack_in)) {
                    push(&stack_out, pop(&stack_in));
                }
            }
            pop(&stack_out);
        } 
        else if (type == 3) {
            if (isEmpty(&stack_out)) {
                while (!isEmpty(&stack_in)) {
                    push(&stack_out, pop(&stack_in));
                }
            }
            printf("%d\n", peak(&stack_out));
        }
    }

    return 0;
}