#Author:  Andrew Thiele
#Email:  <thielea@oregonstate.edu>
#Makefile for Project2 Zoo Tycoon

#source files: 

#Description:  Creates object files from source files to c++11 standard and
#              deletes .o and bin(executables) with "clean" command.
#
#              Checks for memory leaks with Valgrind
#              with 'val' command.
#
tycoon: Animal.o Penguin.o Tiger.o Turtle.o validate.o Zoo.o zooDrv.o
	g++ Animal.o Penguin.o Tiger.o Turtle.o validate.o Zoo.o zooDrv.o -o tycoon
	
zTest: Animal.o Penguin.o Tiger.o Turtle.o validate.o Zoo.o zooTest.o
	g++ Animal.o Penguin.o Tiger.o Turtle.o validate.o Zoo.o zooTest.o -o zTest
 
Animal.o: Animal.cpp
	g++ -std=c++11 -c -g Animal.cpp
	
Penguin.o: Penguin.cpp
	g++ -std=c++11 -c -g Penguin.cpp
	
Tiger.o: Tiger.cpp
	g++ -std=c++11 -c -g Tiger.cpp
	
Turtle.o: Turtle.cpp
	g++ -std=c++11 -c -g Turtle.cpp
	
validate.o: validate.cpp
	g++ -std=c++11 -c -g validate.cpp

Zoo.o: Zoo.cpp
	g++ -std=c++11 -c -g Zoo.cpp
	
zooDrv.o: zooDrv.cpp
	g++ -std=c++11 -c -g zooDrv.cpp
	
zooTest.o: zooTest.cpp
	g++ -std+c++11 -c -g zooTest.cpp

#debug:
 
	 	
val:
	valgrind --leak-check=full ./tycoon
	
clean:
	rm *.o war
