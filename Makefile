all:
	@[ -d lib ] || mkdir -p lib
	clang -std=c17 -O2 -c -o vector.o vector.c
	ar rcs lib/libvector.a vector.o