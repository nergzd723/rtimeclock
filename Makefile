all:
	gcc -fPIC -g -Wall -c librtimeclock.c
	gcc -g -shared -Wl,-soname,librtimeclock.so.1 -o librtimeclock.so.1 librtimeclock.o -lc
	ldconfig -n .
	ln -sf librtimeclock.so.1 librtimeclock.so
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH
	gcc -L. -Wall -o test test.c -lrtimeclock