//
// Created by ROG on 7/31/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE 1000

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Employee {
    char name[50];
    char date[50];
    struct Node *left;
    struct Node *right;
} Employee;

typedef struct Queue {
    Node *human[MAX_QUEUE];
    int front;
    int rear;
}Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}
int isEmptyQueue(Queue *q) {
    return q->front = q->rear = 0;
}
int isFullQueue(Queue *q) {
    return q->rear == MAX_QUEUE;
}
void enQueue(Queue *q, Node *node) {
    if (isFullQueue(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->rear < MAX_QUEUE) {
        q->human[q->rear++] = node;
    }
}
int deQueue(Queue *q) {
    if (!isEmptyQueue(q)) {
        return q->human[q->front++];
    }
    return NULL;
}
// tao cho ceo
Node *createCEO(char name, char date) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = name;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// tao cho nhan vien
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void menu() {
    printf("\n==== HR/HUMAN RESOURCE MANAGER ====\n");
    printf("1. Tao giam doc\n");
    printf("2. Them nhan vien cap duoi\n");
    printf("3. In so do nhan su \n");
    printf("4. Tim kiem nhan su theo ten\n");
    printf("5. Tinh chieu cao he thong nhan su\n");
    printf("6. In duong nhan CEO -> Nhan su bat ki\n");
    printf("7. Thoat\n");
}

Node *makeCEO(Node *root, char name, char date) {
    if (root == NULL) {
        printf("Da them CEO vao dau cay!\n");
        return createCEO(name, date);
    }
}

// Node *makeEmployee(Node *root, char name, char date) {
//     if (root == NULL) {
//         printf("Khong co giam doc, khong the them\n");
//         return 0;
//     }
//     if (root->left == NULL && root->right == NULL) {
//         if () {
//
//         }
//     }
// }




int main() {
    int choice;

    do {
        menu();
        printf("Moi nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Employee ceo;
                char nameCEO, dateCEO;
                printf("Moi nhap ten giam doc: ");
                fgets(ceo.name, 50, stdin);
                ceo.name[strcspn(ceo.name, "\n")] = '\0';
                printf("Moi nhp ngay tham gia: ");
                fgets(ceo.date, 50, stdin);
                ceo.date[strcspn(ceo.date, "\n")] = '\0';
                createCEO( nameCEO, dateCEO);
                break;
            case 2:
                printf("Chua duoc them!\n");
                break;
            case 3:
                printf("Chua duoc them!\n");
                break;
            case 4:
                printf("Chua duoc them!\n");
                break;
            case 5:
                printf("Chua duoc them!\n");
                break;
            case 6:
                printf("Chua duoc them!\n");
                break;
            case 7:
                printf("Da thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!");
                break;
        }

    } while (choice != 7);


    return 0;
}
