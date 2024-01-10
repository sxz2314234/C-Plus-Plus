CXX=g++
SRC=$(wildcard *.cc) 
BINARY=$(SRC:%.cc=%.o)
INCLUDE=-I ~/C++/C-plus-plus/data_structure/Queue/cycle_queue/include

FLAG=-g
TARGET=cycle_queue
all:$(TARGET)

$(TARGET):$(BINARY)
	$(CXX) $(FLAG) $^ -o $@

%.o:%.cc
	$(CXX) $(FLAG) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf ./*.o
	rm -f $(TARGET)