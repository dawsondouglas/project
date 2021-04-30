audio: main.o PreprocessManager.o Mono8BitManager.o Mono16BitManager.o Stereo8BitManager.o Stereo16BitManager.o
	g++ -std=c++11 -o audio main.o PreprocessManager.o Mono8BitManager.o

main.o: main.cpp Mono8BitManager.h PreprocessManager.h
	g++ -std=c++11 -c main.cpp

PreprocessManager.o: PreprocessManager.cpp PreprocessManager.h AudioManager.h  Header.h
	g++ -std=c++11 -c PreprocessManager.cpp

Mono8BitManager.o: Mono8BitManager.cpp Mono8BitManager.h AudioManager.h
	g++ -std=c++11 -c Mono8BitManager.cpp

Mono16BitManager.o: Mono16BitManager.cpp Mono16BitManager.h AudioManager.h
	g++ -std=c++11 -c Mono16BitManager.cpp

Stereo8BitManager.o: Stereo8BitManager.cpp Stereo8BitManager.h AudioManager.h
	g++ -std=c++11 -c Stereo8BitManager.cpp

Stereo16BitManager.o: Stereo16BitManager.cpp Stereo16BitManager.h AudioManager.h
	g++ -std=c++11 -c Stereo16BitManager.cpp

clean:
	rm audio *.o
