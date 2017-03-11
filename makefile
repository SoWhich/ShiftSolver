CC=gcc
CFLAGS=-Werror -Wall -Wextra -Wpedantic
DEPS = shiftcypher.h
OBJ = main.o shiftcypher.o 
OFOLDER = objects

%.o: %.c $(DEPS)
	$(CC) -c -o $(OFOLDER)/$@ $< $(CFLAGS)

shiftcypher: $(OBJ)
	gcc -o $@ $(OFOLDER)/shiftcypher.o $(OFOLDER)/main.o $(CFLAGS)

clean:
	rm $(OFOLDER)/*.o shiftcypher