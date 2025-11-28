CFLAG := -Wno-implicit-function-declaration

Queue: app
Poly: den 
app: c_utils.o QueueAndLinkedList.o
	echo "building exceutable file 'app'"
	gcc $(CFLAG) QueueAndLinkedList.o c_utils.o -o app
	chmod +x app
dan:  c_utils.o PolynomialAndLinkedList.o
	echo "building exceutable file 'dan'"
	gcc $(CFLAG) PolynomialAndLinkedList.o c_utils.o -o dan
	chmod +x dan

c_utils.o: c_utils.c
	echo "building utils"
	gcc $(CFLAG) -c c_utils.c

QueueAndLinkedList.o: QueueAndLinkedList.c
	echo "building main file"
	gcc $(CFLAG) -c QueueAndLinkedList.c

PolynomialAndLinkedList.o: PolynomialAndLinkedList.c
	echo "building main file"
	gcc $(CFLAG) -c PolynomialAndLinkedList.c

clean:
	echo "deleting processes"
	rm *.o
	rm *.exe