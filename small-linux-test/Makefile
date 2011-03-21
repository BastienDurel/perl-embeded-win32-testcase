SRC=main.cpp perlapi.cpp
O=$(SRC:.cpp=.o)

CXXFLAGS=-I/usr/lib/perl/5.10.1/CORE

testpl: $(O)
	$(CXX) -o $@ $(O) -lperl

test: testpl
	./testpl

clean:
	rm -f $(O)
