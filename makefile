all: executable

IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

SRC=src
LDIR =lib

LIBS=-lSDL2 -lstdc++

_DEPS = CEngine.h CRenderer.h CColor.h COrganism.h CGame.h CVector3.h
DEPS = $(patsubst %,$(SRC)/%,$(_DEPS))

_OBJ = main.cpp CEngine.cpp CRenderer.cpp COrganism.cpp CColor.cpp CGame.cpp CVector3.cpp
OBJ = $(patsubst %,$(SRC)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
