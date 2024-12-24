#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100

typedef struct {
    char id[20];
    char name[50];
    char author[50];
    float price;
    char category[30];
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void inputBooks() {
    printf("Nhap so luong sach: ");
    scanf("%d", &bookCount);
    getchar(); 

    for (int i = 0; i < bookCount; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Nhap ma sach: ");
        fgets(books[i].id, 20, stdin);
        strtok(books[i].id, "\n");

        printf("Nhap ten sach: ");
        fgets(books[i].name, 50, stdin);
        strtok(books[i].name, "\n");

        printf("Nhap tac gia: ");
        fgets(books[i].author, 50, stdin);
        strtok(books[i].author, "\n");

        printf("Nhap gia sach: ");
        scanf("%f", &books[i].price);
        getchar();

        printf("Nhap the loai: ");
        fgets(books[i].category, 30, stdin);
        strtok(books[i].category, "\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("Khong co sach nao.\n");
        return;
    }

    printf("\nDanh sach sach:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
    }
}

void addBookAtPosition() {
    if (bookCount >= MAX_BOOKS) {
        printf("Khong the them sach moi.\n");
        return;
    }

    int position;
    printf("Nhap vi tri muon them sach (1 den %d): ", bookCount + 1);
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > bookCount + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = bookCount; i >= position; i--) {
        books[i] = books[i - 1];
    }

    printf("Nhap thong tin sach moi:\n");
    printf("Nhap ma sach: ");
    fgets(books[position - 1].id, 20, stdin);
    strtok(books[position - 1].id, "\n");

    printf("Nhap ten sach: ");
    fgets(books[position - 1].name, 50, stdin);
    strtok(books[position - 1].name, "\n");

    printf("Nhap tac gia: ");
    fgets(books[position - 1].author, 50, stdin);
    strtok(books[position - 1].author, "\n");

    printf("Nhap gia: ");
    scanf("%f", &books[position - 1].price);
    getchar();

    printf("Nhap the loai: ");
    fgets(books[position - 1].category, 30, stdin);
    strtok(books[position - 1].category, "\n");

    bookCount++;
}

void deleteBookById() {
    char id[20];
    printf("Nhap ma sach can xoa: ");
    fgets(id, 20, stdin);
    strtok(id, "\n");

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].id, id) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Xoa sach thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma %s.\n", id);
}

void updateBookById() {
    char id[20];
    printf("Nhap ma sach con cap nhat: ");
    fgets(id, 20, stdin);
    strtok(id, "\n");

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Nhap ten sach: ");
            fgets(books[i].name, 50, stdin);
            strtok(books[i].name, "\n");

            printf("Nhap tac gia: ");
            fgets(books[i].author, 50, stdin);
            strtok(books[i].author, "\n");

            printf("Nhap gia: ");
            scanf("%f", &books[i].price);
            getchar();

            printf("Nhap the loai: ");
            fgets(books[i].category, 30, stdin);
            strtok(books[i].category, "\n");

            printf("Cap nhat sach thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma %s.\n", id);
}

void sortBooksByPrice(int ascending) {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if ((ascending && books[i].price > books[j].price) ||
                (!ascending && books[i].price < books[j].price)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep sach thanh cong.\n");
}

void searchBookByName() {
    char name[50];
    printf("Nhap ten sach can tim: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");

    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].name, name) != NULL) {
            printf("\nTim thay sach:\n");
            printf("Ma sach: %s\n", books[i].id);
            printf("Ten sach: %s\n", books[i].name);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia: %.2f\n", books[i].price);
            printf("The loai: %s\n", books[i].category);
            return;
        }
    }
    printf("Khong tim thay sach voi ten %s.\n", name);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin sach\n");
        printf("2. Hien thi sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma\n");
        printf("5. Cap nhat sach theo ma\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim sach theo ten\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            inputBooks();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            addBookAtPosition();
            break;
        case 4:
            deleteBookById();
            break;
        case 5:
            updateBookById();
            break;
        case 6:
            printf("Sap xep gia (1: tang, 0: giam): ");
            int ascending;
            scanf("%d", &ascending);
            getchar();
            sortBooksByPrice(ascending);
            break;
        case 7:
            searchBookByName();
            break;
        case 8:
            printf("Dang thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Thu lai.\n");
        }
    } while (choice != 8);
    return 0;
}
