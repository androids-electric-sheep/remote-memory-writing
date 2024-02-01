all: injector test

injector: format
	gcc injector.c -Wall -Wextra -o injector.out

test: format
	gcc test.c -Wall -Wextra -o test.out

format:
	clang-format -i *.c

clean:
	rm -vf *.out
