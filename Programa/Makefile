all: principal

# Variável padrão (caso nenhuma seja passada)
# TARGET = ./
TARGET = main

# -----------------------------------------------------------------

principal:
	g++ -std=c++17 -Wall -g -lm -o $(TARGET) *.cpp
#	sleep 1
#	gcc -Wall -c -S main.c
#	rm -rf *.o

run: principal
	./$(TARGET)

rodar: principal
	./$(TARGET)

valg: principal
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

val: principal
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

valg2: principal
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) > saida.txt

val2: principal
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) > saida.txt
