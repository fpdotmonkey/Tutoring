LDFLAGS = -L/usr/local/lib

CFLAGS = -g -D__DEBUG__

SOURCES=pass_by_pointer.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pass_by_pointer

all: $(SOURCES) $(EXECUTABLE) $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(EXECUTABLE): $(OBJECTS) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
