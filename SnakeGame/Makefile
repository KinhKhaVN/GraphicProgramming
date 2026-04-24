CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++17

SHELL := powershell.exe


default:
	g++ -o main.exe *.cpp -std=c++17 -Iinclude -Llib -lraylib -lgdi32 -lwinmm

run:
	main.exe

clean:
	rm *.o, main.exe
