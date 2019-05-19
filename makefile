make:
	g++ -c vector.cpp
	g++ -c generating.cpp
	g++ -c Time.cpp
	g++ -std=c++14 vector.o Time.o 2_uzduotis_vector.cpp -o test
	g++ -o generavimas generavimas.cpp generating.o
	./generavimas
	./test
valymas:
	rm *.o test generavimas blogi.txt geri.txt mokiniai1.txt mokiniai2.txt mokiniai2.txt mokiniai3.txt mokiniai4.txt mokiniai5.txt