CC = g++
CDFLAGS = -Wall -g
SRC = main.cpp EarClipping.cpp
OBJ = $(SRC:%.cpp=%.o)
EXE = main.out

all: $(EXE)
	@echo Done!
	@echo
	@echo Usage: ./$(EXE)
$(EXE): $(OBJ)
	@echo Linking...
	@$(CC) $(OBJ) -o $@

$(OBJ): $(SRC)
	@echo Compiling...
	@$(CC) $(CDFLAGS) -c $(SRC) $<

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f *.out
