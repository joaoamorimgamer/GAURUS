CC	:= cc
PREFIX	:= /usr/
BINDIR	:= $(PREFIX)/bin
BINS	:= dog crdir hadiain no real fake 
CFLAGS	= -march=native -std=c99 -O2 -pipe -Wall -Wextra

all: $(BINS) 

no: no.c
	$(CC) $(CFLAGS) -o no no.c
real: real.c
	$(CC) $(CFLAGS) -o real real.c
fake: fake.c
	$(CC) $(CFLAGS) -o fake fake.c
hadiain: hadiain.c
	$(CC) $(CFLAGS) -o hadiain hadiain.c
dog: dog.c
	$(CC) $(CFLAGS) -o dog dog.c
crdir: crdir.c
	$(CC) $(CFLAGS) -o crdir crdir.c
clean:
	rm -f $(BINS)
install: all
	install -d $(BINDIR)
	install -m 755 $(BINS) $(BINDIR)
uninstall:
	cd $(BINDIR) && rm -f $(BINS)
.PHONY: all no real dog crdir fake hadiain clean install uninstall
