//
// Created by ROG on 7/31/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Book {
    int id;
    char title[50];
    float price;
    char author[50];
    char category[50];
    char date[50];
}Book;

typedef struct SingleNode {
    Book book;
    struct SingleNode* next;
}SingleNode;
typedef struct DoubleNode {
    Book book;
    struct DoubleNode* next;
    struct DoubleNode* prev;
}DoubleNode;

SingleNode *finishNode = NULL;

SingleNode *creatSingleNode(Book book) {
    SingleNode* newNode = (SingleNode*)malloc(sizeof(SingleNode));
    newNode->book = book;
    newNode->next = NULL;
    return newNode;
}
DoubleNode *creatDoubleNode(Book book) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->book = book;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
DoubleNode *insertDoubleNodeAtEnd(DoubleNode *head,Book book) {
    DoubleNode *temp = head;
    while (temp != NULL) {
        if (temp->book.id == book.id) {
            printf("Sach co id %d da ton tai, khong the them!\n", book.id);
            return head;
        }
        temp = temp->next;
    }
    DoubleNode* newNode = creatDoubleNode(book);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
//case2
void displayDoubleNode(DoubleNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    DoubleNode* temp = head;
    printf("Danh sach cac quyen sach: \n");
    while (temp != NULL) {
        printf("\nId: %d", temp->book.id);
        printf("\nTitle: %s", temp->book.title);
        printf("\nPrice: %.2f", temp->book.price);
        printf("\nAuthor: %s", temp->book.author);
        printf("\nCategory: %s", temp->book.category);
        printf("Date: %s\n", temp->book.date);
        temp = temp->next;
    }
    printf("\n");
}
// case3
DoubleNode *deleteBookWithId(DoubleNode *head, int id) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    DoubleNode* current = head;
    DoubleNode* temp = NULL;
    while (current != NULL && current->book.id != id) {
        temp = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("khong tim that id %d\n", id);
        return head;
    }
    if (current == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        finishNode = current;
        free(current);
        return head;
    }
    temp->next = current->next;
    current->next->prev = temp;
    finishNode = current;
    free(current);
    return head;

}
//case 4
DoubleNode* updateDoubleNodeById(DoubleNode *head, int id) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    DoubleNode* temp = head;
    while (temp != NULL && temp->book.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("khong tim that id %d\n", id);
        return head;
    }
    printf("\nId: %d", temp->book.id);
    printf("\nTitle: %s", temp->book.title);
    printf("\nPrice: %.2f", temp->book.price);
    printf("\nAuthor: %s", temp->book.author);
    printf("\nCategory: %s", temp->book.category);
    printf("Date: %s\n", temp->book.date);
    printf("Moi cap nhat thong tin sach:\n");
    fflush(stdin);
    printf("Nhap ten sach : ");
    fgets(temp->book.title, 50, stdin);
    temp->book.title[strcspn(temp->book.title, "\n")] = '\0';
    printf("Nhap price : ");
    scanf("%f", &temp->book.price);
    fflush(stdin);
    printf("Nhap ten tac gia : ");
    fgets(temp->book.author, 50, stdin);
    temp->book.author[strcspn(temp->book.author, "\n")] = '\0';
    printf("Nhap ngay nhap sach : ");
    fgets(temp->book.date, 50, stdin);
    temp->book.date[strcspn(temp->book.date, "\n")] = '\0';
    printf("Da update thogn tin sach co id %d!", temp->book.id);
    return head;
}


//case 7
void searchByNameBook(DoubleNode *head, char *name ) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    DoubleNode* temp = head;
    int find = 0;
    while (temp != NULL) {
        if (strstr(temp->book.title, name) != NULL) {
            printf("\nId: %d", temp->book.id);
            printf("\nTitle: %s", temp->book.title);
            printf("\nPrice: %.2f", temp->book.price);
            printf("\nAuthor: %s", temp->book.author);
            printf("\nCategory: %s", temp->book.category);
            printf("\nDate: %s\n", temp->book.date);
            find = 1;
        }
        temp = temp->next;
    }
    if (find == 0) {
        printf("Khong tim thay sach !!");
        return;
    }
}

void menu() {
    printf("\n=======Book Store Manager =======\n");
    printf("1. Them Sach \n");
    printf("2. Hien thi danh sach cac quyen sach\n");
    printf("3. Xoa sach \n");
    printf("4. Cap nhat thong tin sach\n");
    printf("5. Danh dau sach cho thue\n");
    printf("6. Sap xep sach(theo ten tac gia)\n");
    printf("7. Tim kiem sach (theo ten)\n");
    printf("8. Thoat chuong trinh\n");
}



int main() {
    int choice;
    SingleNode* singleHead = NULL;
    DoubleNode* doubleHead = NULL;
    do {
        menu();
        printf("Moi ban nhap lua chon(1-8): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int n;
                printf("Nhap so luong sach muon them : ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    Book newBook;
                    printf("Nhap id sach : ");
                    scanf("%d", &newBook.id);
                    fflush(stdin);
                    printf("Nhap ten sach : ");
                    fgets(newBook.title, 50, stdin);
                    newBook.title[strcspn(newBook.title, "\n")] = '\0';
                    printf("Nhap price : ");
                    scanf("%f", &newBook.price);
                    fflush(stdin);
                    printf("Nhap ten tac gia : ");
                    fgets(newBook.author, 50, stdin);
                    newBook.author[strcspn(newBook.author, "\n")] = '\0';
                    printf("Nhap phan loai sach : ");
                    fgets(newBook.category, 50, stdin);
                    newBook.category[strcspn(newBook.category, "\n")] = '\0';
                    printf("Nhap ngay nhap sach : ");
                    fgets(newBook.date, 50, stdin);
                    newBook.date[strcspn(newBook.date, "\n")] = '\0';
                    doubleHead = insertDoubleNodeAtEnd(doubleHead, newBook);
                }
                break;
            case 2:
                displayDoubleNode(doubleHead);
                break;
            case 3:
                int deleteIDBook;
                printf("Nhap Id sach muon xoa: ");
                scanf("%d", &deleteIDBook);
                doubleHead = deleteBookWithId(doubleHead, deleteIDBook);
                break;
            case 4:
                int updateIDBook;
                printf("Nhap Id sach muon update: ");
                scanf("%d", &updateIDBook);
                doubleHead = updateDoubleNodeById(doubleHead, updateIDBook);
                break;
            case 5:
                printf("Chuc nang chua duoc cap nhat!!\n");
                break;
            case 6:
                printf("Chuc nang chua duoc cap nhat!!\n");
                break;
            case 7:
                char searchNameBook[50];
                printf("Nhap sach ten sach muon tim kiem: ");
                fflush(stdin);
                fgets(searchNameBook, 50, stdin);
                searchNameBook[strcspn(searchNameBook, "\n")] = '\0';
                searchByNameBook(doubleHead, searchNameBook);
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 8);



    return 0;
}