all: executable

CC=gcc
CFLAGS=-I$(IDIR) -std=c++11
LDIR =lib

IDIR =include
SRC=src
ODIR=object

LIBS=$(shell sdl2-config --libs) -lstdc++

# game objects and handlers
WORLD = World Organism StateMachine Behaviour Stimulus Mutator
# convenient data models for linking game objects to the renderer
STRUCT = Vector3 Color
# things that handle simple object containment, or SDL operations
INTERFACE = Engine Renderer Game
# things that don't start with C, i.e. files containing collections or int main(int, const char[]);
MISC = main base_stimuli base_behaviours

FULL = $(patsubst %,C%,$(WORLD) $(STRUCT) $(INTERFACE)) $(MISC)

DEPS = $(patsubst %,$(IDIR)/%.h,$(FULL))
#DEPS = $(FULL:%,$(IDIR)/%.h)

CODE = $(patsubst %,$(SRC)/%.cpp,$(FULL))
#CODE = $(FULL:%,$(SRC)/%.cpp)

OBJ = $(patsubst %,$(SRC)/%.o,$(FULL))
#OBJ = $(FULL:%,$(SRC)/%.cpp)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable: $(CODE)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
