CXX = g++ -std=c++11
CFLAG = -c

imageops: interface.o Image.o
	$(CXX) interface.o Image.o -o imageops

interface.o: interface.cpp
	$(CXX) $(CFLAG) interface.cpp

clean:
	rm *.o imageops
