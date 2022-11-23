CC = gcc


INC = inc
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -g -Wall

LDFLAGS = -o

IFLAGS = -I $(INC)


all: CBMS

CBMS: $(OBJ)/main.o $(OBJ)/app.o 
	$(CC) $(LDFLAGS) $(BIN)/CBMS $(OBJ)/main.o $(OBJ)/app.o 

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/app.o: $(SRC)/app.c
	$(CC) $(CFLAGS) $(SRC)/app.c $(IFLAGS)
	mv app.o $(OBJ)/


clean:
	rm -f *.out *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
