# I used "Simple makefile generator CP v2.5". It is amazing tbh.

OBJS	= main.o menu.o book.o catalog.o
SOURCE	= src/main.cpp src/menu.cpp src/book.cpp src/catalog.cpp
HEADER	= src/menu.h src/book.h src/catalog.h
OUT		= bookstore
CC	 	= g++
FLAGS	= -g3 -c -Wall
LFLAGS	=

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

bookstore: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++17

menu.o: src/menu.cpp
	$(CC) $(FLAGS) src/menu.cpp -std=c++17

book.o: src/book.cpp
	$(CC) $(FLAGS) src/book.cpp -std=c++17

catalog.o: src/catalog.cpp
	$(CC) $(FLAGS) src/catalog.cpp -std=c++17

clean:
	rm -f $(OBJS) $(OUT)

valgrind_clean:
	rm valgrindLog.txt

run: $(OUT)
	./$(OUT)

debug: $(OUT)
	valgrind --log-file=valgrindLog.txt ./$(OUT)

valgrind: $(OUT)
	valgrind --log-file=valgrindLog.txt ./$(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full --log-file=valgrindLog.txt ./$(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
			 --leak-resolution=high \
			 --track-origins=yes \
			 --vgdb=yes \
			 --verbose \
			 --log-file=valgrindLog.txt \
			 ./$(OUT)