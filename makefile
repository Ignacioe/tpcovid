# Makefile

INTERPRETE = interprete
SRC = main.c
DATABASE = database
CIUDAD = ciudad
REGISTRO = registro
COMP = gcc
ARGSCOMP = -Wall -Wextra -Werror -std=c99 -g

all: $(INTERPRETE)

$(INTERPRETE): $(DATABASE).o $(CIUDAD).o $(REGISTRO).o  $(SRC)
	$(COMP) $(ARGSCOMP) -o $(INTERPRETE) $(SRC) $(DATABASE).o $(CIUDAD).o $(REGISTRO).o

$(INTERPRETE).o: $(INTERPRETE).c
	$(COMP) $(ARGSCOMP) -c $(INTERPRETE).c

$(DATABASE).o: ./Database/$(DATABASE).c
	$(COMP) $(ARGSCOMP) -c ./Database/$(DATABASE).c

$(CIUDAD).o: ./Ciudad/$(CIUDAD).c
	$(COMP) $(ARGSCOMP) -c ./Ciudad/$(CIUDAD).c

$(REGISTRO).o: ./Registro/$(REGISTRO).c
	$(COMP) $(ARGSCOMP) -c ./Registro/$(REGISTRO).c

clean:
	rm *.o
