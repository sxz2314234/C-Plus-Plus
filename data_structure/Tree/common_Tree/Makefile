CXX=g++
flag=-g
SRC=$(wildcard *.cpp)
BINARY=$(SRC:%.cpp=%.o)
TARGET=test

all:$(TARGET)

$(TARGET):$(BINARY)
	$(CXX) $(flag) $^ -o $(TARGET)  

%.o:%.cpp
	$(CXX) $(flag) -c $< -o $@ 

clean:
	rm -rf $(BINARY)