
CC = g++

OBJ = out

LIBS =-L ./lib

rpi_ws281x =-lws2811

SRC = ./*cpp

#HEADS = ./*.h

CCFLAGS = -fpermissive -Wall -w

all:
	$(CC) $(SRC) $(HEADS) $(CCFLAGS) $(LIBS) $(rpi_ws281x) -o $(OBJ)
