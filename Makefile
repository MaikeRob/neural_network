CC = gcc
CFLAGS = -Iinclude -Itests/unity -Wall -Wextra 
LFLAGS = -lm -lopenblas -Llibs/generic_openblas/lib
#-Wall e -Wextra ativam avisos de compilação adicionais

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TESTS = $(wildcard tests/*.c)
UNITY_SRC = tests/unity/unity.c

main_debug: 
	$(CC) -o main_debug main.c $(SRC) $(CFLAGS) -g $(LFLAGS)

main: main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJ) $(TESTS) $(UNITY_SRC)
	$(CC) -Iinclude -Itests/unity -o test_runner $(OBJ) $(TESTS) $(UNITY_SRC) $(LFLAGS)

clean:
	rm -f src/*.o test_runner main main_debug