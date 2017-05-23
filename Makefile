CXX = g++ -std=c++11
CFLAG = -c

imageops: driverClass.o Image.o
	$(CXX) driverClass.o Image.o -o imageops

driverClass.o: driverClass.cpp
	$(CXX) $(CFLAG) driverClass.cpp

clean:
	rm *.o imageops
