FLAGS = -O2 # optimize the code
all: test_Assignement main test_Node test_Container test_Cost

main: Cost.o Node.o Container.o Assignement.o Main.cpp
	g++ $(FLAG) -o main Cost.o Assignement.o Node.o Container.o Main.cpp

test_Assignement: Cost.o Node.o Container.o Assignement.o test_Assignement.cpp
	g++ $(FLAG) -o test_Assignement Cost.o Assignement.o Node.o Container.o test_Assignement.cpp

test_Cost: Cost.o Node.o Container.o test_Cost.cpp
	g++ $(FLAG) Cost.o Node.o Container.o test_Cost.cpp -o test_Cost

test_Container: Node.o Container.o test_Container.cpp
	g++ $(FLAG) Container.o Node.o test_Container.cpp -o test_Container

test_Node: Node.o test_Node.cpp 
	g++ $(FLAG) -o test_Node Node.o test_Node.cpp

Assignement.o: Assignement.cpp assignement.h
	g++ $(FLAG) -c Assignement.cpp

Node.o: Node.cpp node.h
	g++ $(FLAG) -c Node.cpp

Cost.o: Cost.cpp cost.h
	g++ $(FLAG) -c Cost.cpp

Container.o: Container.cpp container.h
	g++ $(FLAG) -c Container.cpp

clean:
	rm -f *.o test_Assignement test_Container test_Cost test_Node main *.exe

run_all: main 
	./main