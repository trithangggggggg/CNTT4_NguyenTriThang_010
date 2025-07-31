//
// Created by ROG on 7/29/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 1000

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef struct Queue {
    Node *items[MAX_QUEUE];
    int front;
    int rear;
}Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
}
int isEmpty(Queue *q) {
    return q->front == q->rear;
}
void enQueue(Queue *q, Node *node) {
    if (q->rear < MAX_QUEUE) {
        q->items[q->rear++] = node;
    }
}
Node *deQueue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    }
    return NULL;
}

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ham giai phong bo nho
void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
// ham hien thi chuc nang
void showMenu() {
    printf("\n====Binary Search Tree====\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Traverse\n");
    printf("4. Count Leavesn\n");
    printf("5. Count height\n");
    printf("6. Exit\n");
}
//thao tac them phan tu vao trong cay
Node *insert(Node *root, int value) {
    if (root == NULL) {
        //ne chua co phan tu nao thi se them vao dau
        printf("Da them phan tu vao dau cay\n");
        return createNode(value);
    }
    if (root->data == value) {
        printf("Phan tu co gia tri %d da ton tai trong cay\n", value);
    }else if (root->data > value) {
        // them vao ben trai
        root->left = insert(root->left, value);
    }else if (root->data < value) {
        // them vao ben phai
        root->right = insert(root->right, value);
    }
    // tra ve root vua tao ra
    return root;
}
//xoa 1 phan tu trong cay
Node *delete(Node *root, int value) {
    if (root == NULL) {
        printf("Cay ron, khong the xoa!\n");
        return NULL;
    }
    if (value < root->data) {
        root->left = delete(root->left, value);
    }else if (value > root->data) {
        root->right = delete(root->right, value);
    }else {
        if (root->left == NULL && root->right == NULL) {
            // 1 root
            free(root);
            printf("Da xoa phan tu %d khoi cay!\n", value);
        }else if (root->left == NULL) {
            // xoa ben phai
            Node *temp = root->right;
            free(root);
            printf("Da xoa phan tu %d khoi cay!\n", value);
            return temp;
        }else if (root->right == NULL) {
            // xoa ben trai
            Node *temp = root->left;
            free(root);
            printf("Da xoa phan tu %d khoi cay!\n", value);
            return temp;
        }else {
            Node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

//dem la cua cay
int countLeavess(Node *root) {
    if (root == NULL) {
        return 0;
    }
    // neu chi co 1 node cinh
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeavess(root->left) + countLeavess(root->right);
}
//chieu cao cua cay
int countHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }
    // cay co chieu cao ben tay trai la
    int leftHeight = countHeight(root->left);

    int rightHeight = countHeight(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }else {
        return rightHeight + 1;
    }

}
// duyet cay
void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);

}

void leverOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue q;
    init(&q);
    enQueue(&q, root);
    while (!isEmpty(&q)) {
        Node *current = deQueue(&q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enQueue(&q, current->left);
        }
        if (current->right != NULL) {
            enQueue(&q, current->right);
        }
    }
}

int main() {
    int choice;
    Node *root = NULL;
    int value;
    do {
        showMenu();
        printf("\n");
        printf("Vui long nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("nhap gia tri cho node: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                int deleteValue;
                printf("dien gia tri muon xoa: ");
                scanf("%d", &deleteValue);
                root = delete(root, deleteValue);
                break;
            case 3:
                if (root == NULL) {
                    printf("Cay rong, khong the duyet!!\n");
                    return 0;
                }
                printf("Duyt ay theo preOrder: ");
                preOrder(root);
                printf("\n");
                printf("Duyet cay theo inOrder: " );
                inOrder(root);
                printf("\n");
                printf("Duyet cay theo postOrder: ");
                postOrder(root);
                printf("\n");
                printf("Duyet cay theo leverOrder: ");
                leverOrder(root);
                printf("\n");
                break;
            case 4:
                printf("So la trong cay: %d", countLeavess(root));
                break;
            case 5:
                printf("Chieu cao cua cay: %d", countHeight(root));
                break;
            case 6:
                printf("Daa thoat chuong trinh!");
                freeTree(root);
                break;
            default:
                printf("Lua hon hong hop le!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}