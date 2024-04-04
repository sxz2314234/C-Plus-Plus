CXX=g++
Cflag=-g
SOURCE=$(wildcard *.cc)
BIN=$(SOURCE:%.cc=%.o)

Target=KMP
$(Target):$(BIN)
	$(CXX)  $^ -o $@

%.o:%.cc
	$(CXX) $(Cflag) -c $< -o $@

clean:
	rm -rf $(BIN)