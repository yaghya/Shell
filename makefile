sh: shell.c prin.o echo.o execfork.o pinfo.o pwd.o divide.o 
	gcc -o sh shell.c prin.o echo.o pinfo.o execfork.o pwd.o divide.o
prin.o: prin.c
	gcc -c prin.c -o prin.o
echo.o: echo.c
	gcc -c echo.c -o echo.o
execfork.o: execfork.c
	gcc -c execfork.c -o execfork.o
pwd.o: pwd.c
	gcc -c pwd.c -o pwd.o
divide.o: divide.c
	gcc -c divide.c -o divide.o
pinfo.o: pinfo.c
	gcc -c pinfo.c -o pinfo.o
clean:
	rm -f sh prin.o echo.o pinfo.o execfork.o pwd.o divide.o 
