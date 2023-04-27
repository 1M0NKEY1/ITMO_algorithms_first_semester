#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct queue {
    int count;
    node *head;
    node *tail;
} queue;

void initialize(queue *q) {
    q -> head = NULL;
    q -> tail = NULL;
}

//int isempty(queue *q) {
//    return (q -> tail == NULL);
//}

void push(queue *q, int value) {
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp -> value = value;
    tmp -> next = NULL;
    if(q != NULL) {
        q -> tail -> next = tmp;
        q -> tail = tmp;
    } else {
        q -> head = q -> tail = tmp;
    }
}

int pop(queue *q) {
    node *tmp;
    int n = q -> head -> value;
    tmp = q -> head;
    q -> head = q -> head -> next;
    free(tmp);
    return(n);
}

void print(node *head) {
    if(head == NULL) {
        printf("NULL\n");
    } else {
        printf("%d\n", head -> value);
        print(head->next);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char symbol;
    int value;

    queue *q;
    q = malloc(sizeof(queue));
    initialize(q);


    for (int i = 0; i < n; i++) {
        scanf("%c", &symbol);
        if (symbol == '+') {
            scanf("%d", &value);
            push(q, value);
        } else if (symbol == '-') {
            pop(q);
            print(q -> head);
        }
    }

    return 0;
}
