// TODO: add non-numeric error handling for price
// TODO: add multiple items with different amounts and track them

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[64];
    float price;
    char currency[4];
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

    Product cart[10];
    bool running = true;
    int c;
    int quantity;

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

        printf("How many items are you going to buy? (max 10): ");

        if (scanf("%d", &quantity) != 1) {
            printf("Invalid input\n");
            continue;
        } else {
            while((c = getchar()) != '\n' && c != EOF) {
                // Discard remaining input
            }
        }

        for (int i = 0; i < quantity; i++) {
            strcpy(cart[i].currency, product.currency);

            printf("What would you like to buy?: ");

            if (fgets(cart[i].name, sizeof(cart[i].name), stdin) == NULL) {
                printf("Input stream failure\n");
            } else {
                cart[i].name[strcspn(cart[i].name, "\n")] = '\0';

                if (strcmp(cart[i].name, "q") == 0) {
                    running = false;
                    continue;
                }
            } 

            printf("How much does it cost?: ");

            if (scanf("%f", &cart[i].price) != 1) {
                printf("Invalid input\n");
            } else {
                while ((c = getchar()) != '\n' && c != EOF) {
                    // Discard remaining input
                }
            }
        }
        
        printf("\n------- Cart Summary -------\n");
        for (int i = 0; i < quantity; i++) {
            printf("\t[%d] %s: %.2f %s\n",
                i + 1,
                cart[i].name,
                cart[i].price,
                cart[i].currency);
        }
        break;
    }

    return EXIT_SUCCESS;
}
