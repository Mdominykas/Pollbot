CXX = g++
DEPS = Poll.h NameEnterBot.h Selecting.h Constants.h
OBJ = main.o Poll.o NameEnterBot.o Selecting.o Constants.o

pollbot: main.o $(OBJ) $(DEPS)
	$(CXX) -o pollbot $(OBJ)

main.o: main.cpp $(DEPS)
	$(CXX) -c main.cpp

Poll.o: Poll.cpp $(DEPS)
	$(CXX) -c Poll.cpp

NameEnterBot.o: NameEnterBot.cpp $(DEPS)
	$(CXX) -c NameEnterBot.cpp

Selecting.o: Selecting.cpp $(DEPS)
	$(CXX) -c Selecting.cpp

Constants.o: Constants.cpp $(DEPS)
	$(CXX) -c Constants.cpp