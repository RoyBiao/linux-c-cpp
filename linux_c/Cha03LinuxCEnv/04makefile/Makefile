calculate:main.o add.o.divide.o mimus.o multiply.o
	gcc main.o add.o divide.o mimus.o multiply.o -o calculate
   
main.o:main.c math.h
	gcc -c main.c
   
add.o:add.c math.h
	gcc -c add.c
   
divide.o:divide.c math.h	
	gcc -c divide.c
  
minus.o:minus.c math.h
	gcc -c minus.c
  
multiply.o:multiply.c math.h
	gcc -c multiply.c
  
clean:main.o add.o divide.o mimus.o multiply.o calculate

