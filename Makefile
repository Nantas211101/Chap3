build: compile
	g++ ./obj/*.o -o ./release/chap3 -L "D:\SFML-2.5.1\lib" -l sfml-graphics -l sfml-window -l sfml-system
compile: 
# -I "D:\SFML-2.5.1\include"
# -L "D:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
	cd ./obj && g++ -c ../src/*.cpp  -I "D:\SFML-2.5.1\include" 