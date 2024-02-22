BOFNAME := test
LIBINCLUDE := 
CFLAGS := -masm=intel
CC_x64 := x86_64-w64-mingw32-gcc
CC_x86 := i686-w64-mingw32-gcc
STRIP_x64 := x86_64-w64-mingw32-strip
STRIP_x86 := i686-w64-mingw32-strip
CC=x86_64-w64-mingw32-clang

all:
	$(CC_x64) $(CFLAGS) -Os -c src/$(BOFNAME).c -DBOF -o bin/$(BOFNAME).x64.o
	$(STRIP_x64) --strip-unneeded bin/$(BOFNAME).x64.o

test:
	$(CC_x64) $(CFLAGS) src/$(BOFNAME).c -g $(LIBINCLUDE) -o bin/$(BOFNAME).x64.exe

clean:
	rm -f bin/$(BOFNAME).x64.*

