FLAGS = 

debug:
		g++ $(FLAGS) main.cpp -DDEBUG -o prog
relese:
		g++ $(FLAGS) main.cpp -o prog