CC = gcc
CFLAGS = -c
LDFLAGS =
SRC_DIR = implementations
OBJ_DIR = objetos
BIN = programa

SOURCES = main.c $(SRC_DIR)/aux.c $(SRC_DIR)/arvore.c
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/aux.o $(OBJ_DIR)/arvore.o

all: $(BIN)
	./$(BIN)
	$(MAKE) clean

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(OBJECTS)

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR)/aux.o: $(SRC_DIR)/aux.c
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR)/arvore.o: $(SRC_DIR)/arvore.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)
