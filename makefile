all: executable

IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

SRC=src
LDIR =lib

LIBS=-lSDL -lstdc++

_DEPS = CEngine.h CRenderer.h CGame.h
DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))

_OBJ = main.cpp CEngine.cpp CRenderer.cpp CGame.cpp
OBJ = $(patsubst %,$(SRC)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
