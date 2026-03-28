CC	:= cc
PREFIX	:= /usr/
BINDIR	:= $(PREFIX)/bin
BINS	:= dog hadiain tap crdir no say standby real fake 
CFLAGS	= -march=native -O2 -pipe -Wall -Wextra

all: $(BINS) 

no: no.c
	$(CC) $(CFLAGS) -o no no.c
real: real.c
	$(CC) $(CFLAGS) -o real real.c
fake: fake.c
	$(CC) $(CFLAGS) -o fake fake.c
hadiain: hadiain.c
	$(CC) $(CFLAGS) -o hadiain hadiain.c
crdir: crdir.c
	$(CC) $(CFLAGS) -o crdir crdir.c
tap: tap.c
	$(CC) $(CFLAGS) -o tap tap.c
say: say.c
	$(CC) $(CFLAGS) -o say say.c
standby: standby.c
	$(CC) $(CFLAGS) -o standby standby.c
clean:
	rm -f $(BINS)
install: all
	install -d $(BINDIR)
	install -m 755 $(BINS) $(BINDIR)
uninstall:
	cd $(BINDIR) && rm -f $(BINS)
.PHONY: all no real fake tap crdir standby say hadiain clean install uninstall
