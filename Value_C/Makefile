IDIR=inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj

_DEPS = Value.h Page.h Types.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = test.o Value.o Genesis.o Bit.o Util.o Page.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
