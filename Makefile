CC = gcc
CFLAGS = -Iinclude -Itests/unity -Wall -Wextra 
#-Wall e -Wextra ativam avisos de compilação adicionais

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TESTS = $(wildcard tests/*.c)
UNITY_SRC = tests/unity/unity.c

main_debug: 
	$(CC) -o main_debug main.c $(SRC) $(CFLAGS) -g

main: main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJ) $(TESTS) $(UNITY_SRC)
	$(CC) -Iinclude -Itests/unity -o test_runner $(OBJ) $(TESTS) $(UNITY_SRC)

clean:
	rm -f src/*.o test_runner main main_debug