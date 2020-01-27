pa2: clean main.o OnOptionsMenu.o Employee.o 
	g++ main.o OnOptionsMenu.o Employee.o -o pa2
main.o: main.cpp errorcode.h
	g++ -c -g -Wall main.cpp
OnOptionsMenu.o: OnOptionsMenu.h OnOptionsMenu.cpp
	g++ -c -g -Wall OnOptionsMenu.cpp
Employee.o: Employee.cpp Employee.h
	g++ -c -g -Wall Employee.cpp
# clean:
# 	rm -f *.o  pa1
clean:
	del -F *.o

