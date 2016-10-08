install:
	make build;
	make run;

build:
	g++ -Wall -lSDL2 -lSDL2_image -o main.out main.cpp

run:
	./main.out
	$(echo "Running main.cpp")

clean:
	rm main.out;
