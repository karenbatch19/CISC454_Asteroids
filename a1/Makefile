LDFLAGS  = -L. -Llib32 -lglfw -lGL -lGLU -ldl
CXXFLAGS = -g -Wall -Wno-write-strings -Wno-parentheses -DLINUX

OBJS = main.o world.o object.o ship.o asteroid.o shell.o gpuProgram.o linalg.o strokefont.o fg_stroke.o glad/src/glad.o
EXEC = asteroids

all:    $(EXEC)

asteroids: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)  $(LDFLAGS) 

clean:
	rm -f  *~ $(EXEC) $(OBJS)

depend:	
	makedepend -Y *.h *.cpp 2> /dev/null

# DO NOT DELETE

asteroid.o: headers.h linalg.h object.h
gpuProgram.o: headers.h linalg.h
headers.o: linalg.h
object.o: headers.h linalg.h
shell.o: headers.h linalg.h object.h
ship.o: headers.h linalg.h object.h shell.h
strokefont.o: headers.h linalg.h
world.o: headers.h linalg.h ship.h object.h shell.h asteroid.h main.h seq.h
asteroid.o: headers.h linalg.h asteroid.h object.h
gpuProgram.o: gpuProgram.h headers.h linalg.h
linalg.o: linalg.h
main.o: headers.h linalg.h gpuProgram.h world.h ship.h object.h shell.h
main.o: asteroid.h main.h seq.h
object.o: headers.h linalg.h object.h world.h ship.h shell.h asteroid.h
object.o: main.h seq.h gpuProgram.h
shell.o: shell.h headers.h linalg.h object.h
ship.o: ship.h headers.h linalg.h object.h shell.h
strokefont.o: strokefont.h headers.h linalg.h
world.o: world.h headers.h linalg.h ship.h object.h shell.h asteroid.h main.h
world.o: seq.h gpuProgram.h strokefont.h
