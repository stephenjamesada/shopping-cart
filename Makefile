CC = gcc
CFLAGS = -std=c2x -Wall -Wextra -Wpedantic -g
SANITIZE_FLAGS = -fsanitize=address,undefined
TARGET = cart

$(TARGET): cart.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)

sanitize: CFLAGS += $(SANITIZE_FLAGS)
sanitize: clean $(TARGET) ./$(TARGET)
