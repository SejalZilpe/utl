
myapp:main.o add.o multiply.o
	@gcc  main.o add.o multiply.o -o $@  # @ is used to hide the command on terminal $@ is to make the executable name

main.o: add.h add.c multiply.h multiply.c main.c
	@gcc -g -c main.c

add.o: add.h add.c
	@gcc -g -c add.c

multiply.o: multiply.h multiply.c
	@gcc -g -c multiply.c

clean:
	@rm *.o myapp
