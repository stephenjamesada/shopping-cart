CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -g

cart: cart.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f cart
