#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char id[20];
    char name[50];
    float importPrice;
    float salePrice;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;
float revenue = 0.0;

void inputProduct() {
    Product newProduct;
    printf("Nhap ma san pham: ");
    fgets(newProduct.id, 20, stdin);
    strtok(newProduct.id, "\n");
    printf("Nhap ten san pham: ");
    fgets(newProduct.name, 50, stdin);
    strtok(newProduct.name, "\n");
    printf("Nhap gia nhap: ");
    scanf("%f", &newProduct.importPrice);
    getchar();
    printf("Nhap gia ban: ");
    scanf("%f", &newProduct.salePrice);
    getchar();
    printf("Nhap so luong: ");
    scanf("%d", &newProduct.quantity);
    getchar();

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, newProduct.id) == 0) {
            products[i].quantity += newProduct.quantity;
            revenue -= newProduct.quantity * newProduct.importPrice;
            printf("Da cap nhat so luong san pham ton tai.\n");
            return;
        }
    }

    products[productCount++] = newProduct;
    revenue -= newProduct.quantity * newProduct.importPrice;
    printf("Da them san pham moi.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("Khong co san pham nao.\n");
        return;
    }

    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < productCount; i++) {
        printf("\nSan pham %d:\n", i + 1);
        printf("Ma san pham: %s\n", products[i].id);
        printf("Ten san pham: %s\n", products[i].name);
        printf("Gia nhap: %.2f\n", products[i].importPrice);
        printf("Gia ban: %.2f\n", products[i].salePrice);
        printf("So luong: %d\n", products[i].quantity);
    }
}

void updateProduct() {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    fgets(id, 20, stdin);
    strtok(id, "\n");

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Nhap ten moi: ");
            fgets(products[i].name, 50, stdin);
            strtok(products[i].name, "\n");

            printf("Nhap gia nhap moi: ");
            scanf("%f", &products[i].importPrice);
            getchar();

            printf("Nhap gia ban moi: ");
            scanf("%f", &products[i].salePrice);
            getchar();

            printf("Nhap so luong moi: ");
            scanf("%d", &products[i].quantity);
            getchar();

            printf("Cap nhat san pham thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma %s.\n", id);
}

void sortProductsByPrice(int ascending) {
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            if ((ascending && products[i].salePrice > products[j].salePrice) ||
                (!ascending && products[i].salePrice < products[j].salePrice)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Sap xep san pham thanh cong.\n");
}

void searchProduct() {
    char name[50];
    printf("Nhap ten san pham can tim: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");

    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printf("\nSan pham tim thay:\n");
            printf("Ma san pham: %s\n", products[i].id);
            printf("Ten san pham: %s\n", products[i].name);
            printf("Gia nhap: %.2f\n", products[i].importPrice);
            printf("Gia ban: %.2f\n", products[i].salePrice);
            printf("So luong: %d\n", products[i].quantity);
            return;
        }
    }
    printf("Khong tim thay san pham voi ten %s.\n", name);
}

void sellProduct() {
    char id[20];
    int quantity;
    printf("Nhap ma san pham can ban: ");
    fgets(id, 20, stdin);
    strtok(id, "\n");

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Nhap so luong can ban: ");
            scanf("%d", &quantity);
            getchar();

            if (products[i].quantity == 0) {
                printf("San pham da het hang.\n");
                return;
            }
            if (quantity > products[i].quantity) {
                printf("Khong con du hang.\n");
                return;
            }

            products[i].quantity -= quantity;
            revenue += quantity * products[i].salePrice;
            printf("Ban hang thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma %s.\n", id);
}

void displayRevenue() {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
        case 3:
            inputProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 4:
            updateProduct();
            break;
        case 5: {
            int ascending;
            printf("Sap xep theo gia (1: Tang dan, 0: Giam dan): ");
            scanf("%d", &ascending);
            getchar();
            sortProductsByPrice(ascending);
            break;
        }
        case 6:
            searchProduct();
            break;
        case 7:
            sellProduct();
            break;
        case 8:
            displayRevenue();
            break;
        case 9:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 9);

    return 0;
}
