#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 1000000
#define MAX_OPS 1000000
#define APPEND 1
#define DELETE 2

typedef struct {
    int typ; 
    char *str; 
    int len;
} Opern;
char S[MAX_LEN + 5]; 
int s_len = 0;
Opern un_stack[MAX_OPS];
int top = -1;
void push(Opern op) {
    un_stack[++top] = op;
}
Opern pop() {
    return un_stack[top--];
}
int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            char w[1000001];
            scanf("%s", w);
            int wlen = strlen(w);
            strcpy(S + s_len, w);
            s_len += wlen;
            Opern op;
            op.typ = DELETE;
            op.len = wlen;
            op.str = NULL;
            push(op);
        } else if (typ == 2) {
            int k;
            scanf("%d", &k);
            char *deleted = (char *)malloc((k + 1) * sizeof(char));
            strncpy(deleted, S + s_len - k, k);
            deleted[k] = '\0';
            s_len -= k;
            S[s_len] = '\0';
            Opern op;
            op.typ = APPEND;
            op.str = deleted;
            op.len = 0;
            push(op);

        } else if (typ == 3) { 
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);

        } else if (typ == 4) { 
            Opern op = pop();
            if (op.typ == DELETE) {
                s_len -= op.len;
                S[s_len] = '\0';
            } 
            else if (op.typ == APPEND) {
                int len = strlen(op.str);
                strcpy(S + s_len, op.str);
                s_len += len;
                free(op.str);
            }
        }
    }

    return 0;
}