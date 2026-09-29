// TODO: v2: add multiple items with different amounts and track them

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int count;
} Product;

int main() {
    Product product;

    bool running = true;
    char currency = '$';
    int c;

    while (running) {
        printf("What would you like to buy?: ");

        // Finds newline, changes to null terminator
        if (fgets(product.name, sizeof(product.name), stdin) == NULL) {
            printf("Input stream failure\n");
        } else {
            product.name[strcspn(product.name, "\n")] = '\0';

            if (strcmp(product.name, "q") == 0) {
                running = false;
                continue;
            }
        }

        printf("How much does it cost?: ");

        if (scanf("%f", &product.price) != 1) {
            printf("Invalid input\n");
        } else {
            while ((c = getchar()) != '\n' && c != EOF) {
                // Discard remaining input (condition does the work)
            }
        }

        printf("%s: %c%.2f\n", product.name, currency, product.price);
        product.count++;

        if (product.count == 1) {
            running = false;
            continue;
        }
    }

    return EXIT_SUCCESS;
}
