CXX:=g++
flag=-g
INCLUDE=-I ../include

SRC=$(wildcard *.cc)
BIN=$(SRC:%.cc=%.o)

TARGET=graph

all:$(TARGET)

$(TARGET):$(BIN)
	$(CXX) $(flag) $^ -o $@ 

%.o:%.cc
	$(CXX) $(flag) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf $(BIN)
	mv ./$(TARGET) ../bin