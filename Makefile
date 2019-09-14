CC=gcc
CFLAGS=-O2 -Wall

all: rev1.exe rev2.exe rev3.exe

rev1.exe: rev1.c
	$(CC) rev1.c $(CFLAGS) -o rev1.exe

rev2.exe: rev2.c
	$(CC) rev2.c $(CFLAGS) -o rev2.exe

rev3.exe: rev3.c
	$(CC) rev3.c $(CFLAGS) -o rev3.exe

rev4.exe: rev4.c
	$(CC) rev4.c $(CFLAGS) -o rev4.exe

rev5.exe: rev5.c
	$(CC) rev5.c $(CFLAGS) -o rev5.exe

rev6.exe: rev6.c
	$(CC) rev6.c $(CFLAGS) -o rev6.exe

self1.exe: self1.c
	$(CC) self1.c $(CFLAGS) -o self1.exe

self2.exe: self2.c
	$(CC) self2.c $(CFLAGS) -o self2.exe

self3.exe: self3.c
	$(CC) self3.c $(CFLAGS) -o self3.exe

self4.exe: self4.c
	$(CC) self4.c $(CFLAGS) -o self4.exe

self5.exe: self5.c
	$(CC) self5.c $(CFLAGS) -o self5.exe

self6.exe: self6.c
	$(CC) self6.c $(CFLAGS) -o self6.exe
