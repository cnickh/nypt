IDIR=inc
CC=gcc
CFLAGS=-I$(IDIR) -lm
ODIR=obj

_DEPS = Value.h Page.h Types.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ0 = basic_test.o Value.o Genesis.o Bit.o Util.o Page.o
OBJ0 = $(patsubst %,$(ODIR)/%,$(_OBJ0))

_OBJ1 = adv_test.o Value.o Genesis.o Bit.o Util.o Page.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = page_test.o Value.o Genesis.o Bit.o Util.o Page.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

_OBJ3 = prime_test.o Prime.o Value.o Genesis.o Bit.o Util.o Page.o
OBJ3 = $(patsubst %,$(ODIR)/%,$(_OBJ3))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

basic: $(OBJ0)
	$(CC) -o $@ $^ $(CFLAGS)

advance: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

page: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

prime: $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
