test : main.cpp Lentcode.o
	g++ -g -o $@ $^

Lentcode.o:Lentcode.cpp
	g++ -g -c -o $@ $^
