CFLAG := -Wno-implicit-function-declaration

Queue: app

app: c_utils.o QueueAndLinkedList.o
	echo "building exceutable file 'app'"
	gcc $(CFLAG) QueueAndLinkedList.o c_utils.o -o app
	chmod +x app

c_utils.o: c_utils.c
	echo "building utils"
	gcc $(CFLAG) -c c_utils.c

QueueAndLinkedList.o: QueueAndLinkedList.c
	echo "building main file"
	gcc $(CFLAG) -c QueueAndLinkedList.c

clean:
	echo "deleting processes"
	rm *.o
	rm *.exe