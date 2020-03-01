CFLAGS = -O -Wall -std=gnu11 -I../j2735 -lczmq -lzmq
LIBS = ../j2735/libj2735.a

DEC = wave

all: $(DEC)

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(DEC): dec.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	-$(RM) $(DEC) $(UDP) *.o
