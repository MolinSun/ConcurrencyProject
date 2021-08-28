#Molin Sun
#C00266170
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS) -fopenmp

ALL: main.o 
	$(CC) -o momoko main.o -fopenmp $(CFLAGS) $(DEBUGFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o

