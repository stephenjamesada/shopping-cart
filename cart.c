// TODO: add multiple items with different amounts and track them

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    char currency[4];
    int count;
    char currencies[4][4];
} Product;

int main() {
    Product product = {
        .currencies = {
            "USD",
            "EUR",
            "GBP",
            "JPY"
        }
    };

    bool running = true;
    int c;

    while (running) {
        printf("1.\tUSD\n");
        printf("2.\tEUR\n");
        printf("3.\tGBP\n");
        printf("4.\tJPY\n");
        printf("Choose your currency (default USD): ");

        int choice;
        scanf("%d", &choice);
        while ((c = getchar()) != '\n' && c != EOF) {
            // discard remaining input
        }

        switch(choice) {
            case 1:
                strcpy(product.currency, product.currencies[0]);
                break;
            case 2:
                strcpy(product.currency, product.currencies[1]);
                break;
            case 3:
                strcpy(product.currency, product.currencies[2]);
                break;
            case 4:
                strcpy(product.currency, product.currencies[3]);
                break;
            default:
                strcpy(product.currency, product.currencies[0]);
                break;
        }

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

        printf("%s: %.2f %c\n", product.name, product.price, product.currency);
        product.count++;

        if (product.count == 1) {
            running = false;
            continue;
        }
    }

    return EXIT_SUCCESS;
}
