
all: eliminarRepetidos eliminarRepetidosOrdenado hanoi HeapSort
	g++ -o eliminarRepetidos eliminarRepetidos.cpp  
	./eliminarRepetidos salida1.csv 12345 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 11000 12000 13000 14000 15000 

	g++ -o eliminarRepetidosOrdenado eliminarRepetidosOrdenado.cpp 
	./eliminarRepetidosOrdenado salida2.csv 12345 10000 20000 30000 40000 50000 60000 70000 80000 90000 100000 110000 120000 130000 140000 150000

	g++ -o hanoi hanoi.cpp 
	./hanoi salida3.csv 12345 3 4 5 7 9 10 13 15 17 20 21 22 23 24 25

	g++ -o HeapSort HeapSort.cpp 
	./HeapSort salida4.csv 12345 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 11000 12000 13000 14000 15000 

clean:
	rm eliminarRepetidos eliminarRepetidosOrdenado hanoi HeapSort
	#rm *.txt
	rm *.csv
